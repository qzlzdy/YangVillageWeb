---
title: mesy特权架构
---
<!--
    YangVillage Website
    Copyright (C) 2024  Qzlzdy

    This content is licensed under the Creative Commons Attribution Share Alike
    4.0 International (CC-BY-SA-4.0).

    See <https://creativecommons.org/licenses/by-sa/4.0/>.
-->
- [1. mesy特权架构](#1-mesy特权架构)
  - [1.1. mesy特权软件栈](#11-mesy特权软件栈)
  - [1.2. 特权等级](#12-特权等级)
- [2. 控制状态寄存器](#2-控制状态寄存器)
  - [2.1. CSR地址映射](#21-csr地址映射)
  - [2.2. CSR列表](#22-csr列表)
- [3. 机器态ISA](#3-机器态isa)
  - [3.1. 机器态CSR](#31-机器态csr)
    - [3.1.1. 供应商ID寄存器`mvendorid`](#311-供应商id寄存器mvendorid)
    - [3.1.2. 架构ID寄存器`marchid`](#312-架构id寄存器marchid)
    - [3.1.3. 实现ID寄存器`mimpid`](#313-实现id寄存器mimpid)
    - [3.1.4. 状态寄存器`mstatus`](#314-状态寄存器mstatus)
      - [3.1.4.1. 特权和全局中断使能栈](#3141-特权和全局中断使能栈)
    - [3.1.5. 陷阱向量基址寄存器`mtvec`](#315-陷阱向量基址寄存器mtvec)
    - [3.1.6. 硬件性能计数器](#316-硬件性能计数器)
    - [3.1.7. 异常程序计数器`mepc`](#317-异常程序计数器mepc)
    - [3.1.8. 原因寄存器`mcause`](#318-原因寄存器mcause)
  - [3.2. 机器态特权指令](#32-机器态特权指令)
    - [3.2.1. 环境调用](#321-环境调用)
    - [3.2.2. 陷阱返回指令](#322-陷阱返回指令)
    - [3.2.3. 等待中断](#323-等待中断)
  - [3.3. 复位](#33-复位)
  - [3.4. 不可屏蔽中断](#34-不可屏蔽中断)
- [4. 内核态ISA](#4-内核态isa)
  - [4.1. 内核态CSR](#41-内核态csr)
  - [4.2. 页式虚拟内存](#42-页式虚拟内存)
    - [4.2.1. 内存保护](#421-内存保护)
    - [4.2.2. 虚拟地址翻译过程](#422-虚拟地址翻译过程)
- [5. mesy特权指令集列表](#5-mesy特权指令集列表)

# 1. mesy特权架构

## 1.1. mesy特权软件栈

mesy特权架构具有操作系统层，但不具有虚拟化层，即应用程序通过ABI与OS交互，OS通过SBI与SEE交互。

## 1.2. 特权等级

mesy支持三种特权等级。特权等级用于在软件栈的不同组件之间提供保护，执行比当前态更高级的操作将导致异常。

|等级|编码|名称|缩写|
|:--:|:--:|:--:|:--:|
|0|00|用户态|U|
|1|01|内核态|S|
|3|11|机器态|M|

# 2. 控制状态寄存器

## 2.1. CSR地址映射

mesy用$12$位地址空间编码最多4096个CSR。其中最高$2$位编码读写权限，次高$2$位编码允许最低的特权等级。

访问不存在的CSR、写只读CSR导致非法指令异常。

## 2.2. CSR列表

计时器、计数器、浮点CSR是非特权CSR，除此之外的CSR是特权CSR。

**非特权CSR地址**

![非特权地址](/images/mesy-priv/UnprivilegedCsrAddress.png)

**机器态CSR地址**

![机器态地址](/images/mesy-priv/MachineLevelCsrAddress.png)

# 3. 机器态ISA

机器态是mesy中权限最高的等级。

## 3.1. 机器态CSR

### 3.1.1. 供应商ID寄存器`mvendorid`

`mvendorid`是只读寄存器，记录供应商ID。

![mvendorid](/images/mesy-priv/VendorIdRegister.png)

!!! 羊村科技的供应商ID为`0x59616e67`，即`Yang`。

### 3.1.2. 架构ID寄存器`marchid`

`marchid`是只读寄存器，记录架构ID。

![marchid](/images/mesy-priv/ArchitectureIdRegister.png)

!!! ylikou架构的架构ID为`0x4d455359`，即`MESY`。

### 3.1.3. 实现ID寄存器`mimpid`

`mimpid`是只读寄存器，记录处理器实现的版本。

![mimpid](/images/mesy-priv/ImplementationIdRegister.png)

!!! ylikou架构的实现ID为`0x796c696b`，即`ylik`。

### 3.1.4. 状态寄存器`mstatus`

`mstatus`记录当前处理器的状态和控制操作模式。

![mstatus](/images/mesy-priv/StatusRegister.png)

#### 3.1.4.1. 特权和全局中断使能栈

`MIE`是机器态的全局中断使能位，用于保证当前等级下中断处理的原子性。

当程序在$x$态执行，$x$`IE=`$1$时开启全局中断，$x$`IE=`$0$时关闭全局中断。对于低特权级$w<x$的中断，与$x$`IE`值无关且总是关闭。对于高特权级$y>x$的中断，与$x$`IE`值无关且总是开启。

对于嵌套陷阱，特权等级$x$对应两个字段表示中断栈。$x$`PIE`表示陷阱前的中断使能位，$x$`PP`表示陷阱前的特权等级。当发生陷阱将特权等级从$y$转到$x$，$x$`PIE`置为$x$`IE`，$x$`IE`置为$0$，$x$`PP`置为$y$。

`MRET`和`SRET`指令用于用M态和S态返回。当$x$`RET`执行时，设$x$`PP=`$y$，$x$`IE`置为$x$`PIE`，特权等级转为$y$，$x$`PIE`置为$1$，$x$`PP`置为`U`。

### 3.1.5. 陷阱向量基址寄存器`mtvec`

`mtvec`记录陷阱向量的配置，由向量基址`BASE`和向量模式`MODE`组成。

![mtvec](/images/mesy-priv/TrapVectorBaseAddressRegister.png)

|`MODE`值|名称|描述|
|--:|:--:|:--|
|$0$|直接模式|所有异常将$pc$设置为$BASE$|
|$1$|向量模式|异步中断将$pc$设置为$BASE+4\times cause$|

当`MODE`设置为向量模式时，`BASE`的低$4$位被忽略，直接与中断号拼接产生陷阱向量。

### 3.1.6. 硬件性能计数器

`mcycle`计数机器时钟。`minstret`记录完成的指令数。`mcycle`和`minstret`都有$64$位精度。

### 3.1.7. 异常程序计数器`mepc`

`mepc`的低两位总是$0$，可以记录虚拟地址。

当因陷阱进入`M`态时，`mepc`存入被中断或导致异常的指令虚拟地址。

![mepc](/images/mesy-priv/ExceptionProgramCounter.png)

### 3.1.8. 原因寄存器`mcause`

当因陷阱进入`M`态时，`mcause`存入导致该陷阱的事件代码。

`Interrupt`位表示陷阱是否由中断引起。`Exception Code`字段记录上一次异常或中断的代码。

![mcause](/images/mesy-priv/CauseRegister.png)

**陷阱代码**

|`Interrupt`|`Exception Code`|描述|
|--:|--:|:--|
|$1$|1|S态软件中断|
|$1$|3|M态软件中断|
|$1$|5|S态计时器中断|
|$1$|7|M态计时器中断|
|$1$|9|S态外部中断|
|$1$|11|M态外部中断|
|$0$|2|非法指令|
|$0$|8|U态环境调用|
|$0$|9|S态环境调用|
|$0$|11|M态环境调用|
|$0$|13|缺页异常|

指令可能同时产生多个同步异常，它们的优先级按降序排列如下。

|优先级|异常码|描述|
|:--:|--:|:--|
|最高|2|非法指令|
| |8,9,11|环境调用|
|最低|13|访存缺页异常|

## 3.2. 机器态特权指令

### 3.2.1. 环境调用

![环境调用](/images/mesy/EnvironmentCall.png)

`ECALL`用于发出执行环境请求。在U态，S态，M态执行时，分别产生对应特权等级的环境调用异常。

### 3.2.2. 陷阱返回指令

![陷阱返回指令](/images/mesy-priv/TrapReturnInstructions.png)

`MRET`和`SRET`用于在陷阱处理后从对应特权等级返回。$x$`RET`可以在$x$态及更高特权等级执行，执行低等级的$x$`RET`时，会弹出低等级的中断使能和特权模式栈。除[3.1.4.1节](#3141-特权和全局中断使能栈)中描述的操作以外，$x$`RET`还会设置$pc$为$epc$。

### 3.2.3. 等待中断

`WFI`用于暂停当前程序直到有中断需要被处理。`WFI`可在所有特权等级下执行。

![等待中断](/images/mesy-priv/WaitForInterrupt.png)

## 3.3. 复位

机器复位后，特权等级置为`M`，`mstatus`的`MIE`字段置为$0$。$pc$置为特定值。

## 3.4. 不可屏蔽中断

不可屏蔽中断只用于硬件错误，立即跳转到实现确定的NMI向量地址上，特权等级置为`M`。`mepc`存入被中断的指令虚拟地址，`mcause`存入指明NMI源的值。

# 4. 内核态ISA

## 4.1. 内核态CSR

## 4.2. 页式虚拟内存

### 4.2.1. 内存保护

### 4.2.2. 虚拟地址翻译过程

# 5. mesy特权指令集列表

**陷阱返回指令**

![陷阱返回](/images/mesy-priv/TrapReturnList.png)

**中断管理指令**

![中断管理](/images/mesy-priv/InterruptManagementList.png)
