---
title: mesy特权架构
---

- [1. mesy特权架构](#1-mesy特权架构)
  - [1.1. mesy特权软件栈](#11-mesy特权软件栈)
  - [1.2. 特权等级](#12-特权等级)
- [2. 控制状态寄存器](#2-控制状态寄存器)
  - [2.1. CSR地址映射](#21-csr地址映射)
  - [2.2. CSR列表](#22-csr列表)
- [3. 机器态ISA](#3-机器态isa)
  - [3.1. 机器态CSR](#31-机器态csr)
    - [3.1.1. ISA寄存器`misa`](#311-isa寄存器misa)
    - [3.1.2. 供应商ID寄存器`mvendorid`](#312-供应商id寄存器mvendorid)
    - [3.1.3. 架构ID寄存器`marchid`](#313-架构id寄存器marchid)
    - [3.1.4. 实现ID寄存器`mimpid`](#314-实现id寄存器mimpid)
    - [3.1.5. 状态寄存器`mstatus`](#315-状态寄存器mstatus)
      - [3.1.5.1. 特权和全局中断使能栈](#3151-特权和全局中断使能栈)
    - [3.1.6. 中断向量基址寄存器`mtvec`](#316-中断向量基址寄存器mtvec)
    - [3.1.7. 异常程序计数器`mepc`](#317-异常程序计数器mepc)
    - [3.1.8. 原因寄存器`mcause`](#318-原因寄存器mcause)
  - [3.2. 机器态特权指令](#32-机器态特权指令)
    - [3.2.1. 环境调用](#321-环境调用)
    - [3.2.2. 陷阱返回指令](#322-陷阱返回指令)
    - [3.2.3. 等待中断](#323-等待中断)
  - [3.3. 复位](#33-复位)
  - [3.4. 不可屏蔽中断](#34-不可屏蔽中断)
- [4. 操作系统态ISA](#4-操作系统态isa)
  - [4.1. 页式虚拟内存](#41-页式虚拟内存)
- [5. mesy特权指令集列表](#5-mesy特权指令集列表)

# 1. mesy特权架构

## 1.1. mesy特权软件栈

mesy特权架构固定具有操作系统层，但不具有虚拟化层，即应用程序通过ABI与OS交互，OS通过SBI与SEE交互。

## 1.2. 特权等级

mesy支持三种特权等级，不支持调试模式。

|等级|编码|名称|缩写|
|:--:|:--:|:--:|:--:|
|0|00|用户态|U|
|1|01|操作系统态|S|
|3|11|机器态|M|

# 2. 控制状态寄存器

mesy仅包含部分必要的RISC-V CSR。

## 2.1. CSR地址映射

mesy用$12$位地址空间（$csr[11:0]$）编码最多4096个CSR。其中，最高两位（$csr[11:10]$）编码读写权限，次高两位（$csr[9:8]$）编码最低允许特权等级。

## 2.2. CSR列表

<table border="1" style="border-collapse:collapse">
<caption>mesy非特权CSR地址</caption>
<tr><th>地址</th><th>权限</th><th>名称</th><th>描述</th></tr>
<tr><th colspan="4">非特权计数器/计时器</th></tr>
<tr><td>0xC00</td><td>URO</td><td>cycle</td><td>周期计数器</td></tr>
<tr><td>0xC02</td><td>URO</td><td>instret</td><td>指令计数器</td></tr>
<tr><td>0xC80</td><td>URO</td><td>cycleh</td><td>cycle高$32$位</td></tr>
<tr><td>0xC82</td><td>URO</td><td>instreth</td><td>instret高$32$位</td></tr>
</table>

<table border="1" style="border-collapse:collapse">
<caption>mesy机器态CSR地址</caption>
<tr><th>地址</th><th>权限</th><th>名称</th><th>描述</th></tr>
<tr><th colspan="4">机器信息寄存器</th></tr>
<tr><td>0xF11</td><td>MRO</td><td>mvendorid</td><td>供应商ID</td></tr>
<tr><td>0xF12</td><td>MRO</td><td>marchid</td><td>架构ID</td></tr>
<tr><td>0xF13</td><td>MRO</td><td>mimpid</td><td>实现ID</td></tr>
<tr><th colspan="4">机器中断设置</th></tr>
<tr><td>0x300</td><td>MRW</td><td>mstatus</td><td>机器状态寄存器</td></tr>
<tr><td>0x301</td><td>MRW</td><td>misa</td><td>指令集架构和扩展</td></tr>
<tr><td>0x305</td><td>MRW</td><td>mtvec</td><td>机器中断服务基址</td></tr>
<tr><th colspan="4">机器中断服务</th></tr>
<tr><td>0x341</td><td>MRW</td><td>mepc</td><td>机器异常程序寄存器</td></tr>
<tr><td>0x342</td><td>MRW</td><td>mcause</td><td>机器中断原因</td></tr>
<tr><th colspan="4">机器计数器/计时器</th></tr>
<tr><td>0xB00</td><td>MRW</td><td>mcycle</td><td>机器周期计数器</td></tr>
<tr><td>0xB02</td><td>MRW</td><td>minstret</td><td>机器指令计数器</td></tr>
<tr><td>0xB80</td><td>MRW</td><td>mcycleh</td><td>mcycle高$32$位</td></tr>
<tr><td>0xB82</td><td>MRW</td><td>minstreth</td><td>minstret高$32$位</td></tr>
</table>

# 3. 机器态ISA

## 3.1. 机器态CSR

### 3.1.1. ISA寄存器`misa`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:6%"><ruby>MXL[1:0]<rt>31:30</rt></ruby></td>
    <td style="width:12%"><ruby>0<rt>29:26</rt></ruby></td>
    <td><ruby>Extensions<rt>25:0</rt></ruby></td>
</tr></table>

mesy只支持机器字长为$32$位，故$MXL[1:0]$固定为$1$。

|位|字符|描述|
|--:|--:|:--|
|0|A|原子扩展|
|1-4|B-E|保留|
|5|F|单精度浮点扩展|
|8|I|基础ISA|
|12|M|整数乘除扩展|
|18|S|操作系统态|
|20|U|用户态|

### 3.1.2. 供应商ID寄存器`mvendorid`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td><ruby>Vendor ID<rt>31:0</rt></ruby></td>
</tr></table>

对于本工程中的ylikou架构，$mvendorid=0x59616e67$。

### 3.1.3. 架构ID寄存器`marchid`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td><ruby>Architecture ID<rt>31:0</rt></ruby></td>
</tr></table>

对于本工程中的ylikou架构，$marchid=0x4d455359$。

### 3.1.4. 实现ID寄存器`mimpid`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td><ruby>Implementation<rt>31:0</rt></ruby></td>
</tr></table>

对于本工程中的ylikou架构，$mimpid=0x796c696b$。

### 3.1.5. 状态寄存器`mstatus`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:88%"><ruby>0<rt>31:4</rt></ruby></td>
    <td style="width:6%"><ruby>MPP[1:0]<rt>3:2</rt></ruby></td>
    <td style="width:3%"><ruby>MPIE<rt>1</rt></ruby></td>
    <td><ruby>MIE<rt>0</rt></ruby></td>
</tr></table>

#### 3.1.5.1. 特权和全局中断使能栈

全局中断使能位$MIE$用于机器态。

当程序在$x$态执行，$xIE=1$时开启全局中断，$xIE=0$时关闭全局中断。对于低特权级$w<x$的中断，不管$xIE$值总是关闭。对于高特权级$y>x$的中断，不管$xIE$值总是开启。

对于嵌套陷阱，特权等级$x$对应两个字段表示中断栈。$xPIE$表示陷阱前的中断使能位，$xPP$表示陷阱前的特权等级。当发生陷阱将特权等级从$y$转到$x$，$xPIE$置为$xIE$，$xIE$置为$0$，$xPP$置为$y$。

`MRET`和`SRET`指令用于用M态和S态陷阱返回。当`xRET`执行时，设$xPP=y$，$xIE$置为$xPIE$，特权等级转为$y$，$xPIE$置为$1$，$xPP$置为$U$。

### 3.1.6. 中断向量基址寄存器`mtvec`

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:94%"><ruby>BASE<rt>31:2</rt></ruby></td>
    <td><ruby>MODE<rt>1:0</rt></ruby></td>
</tr></table>

|MODE值|名称|描述|
|--:|:--:|:--|
|0|直接式|所有异常置$pc$为$BASE$|
|1|向量式|异步中断置$pc$为$BASE+4\times cause$|

### 3.1.7. 异常程序计数器`mepc`

$mepc$的低两位总是$0$。

当因陷阱进入M态时，$mepc$存入被中断或导致异常的指令虚拟地址。

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td><ruby>mepc<rt>31:0</rt></ruby></td>
</tr></table>

### 3.1.8. 原因寄存器`mcause`

$Interrupt$位表示陷阱是否由中断引起。

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:3%"><ruby>Interrupt<rt>31</rt></ruby></td>
    <td><ruby>Exception Code<rt>30:0</rt></ruby></td>
</tr></table>

|Interrupt|Exception Code|描述|
|--:|--:|:--|
|1|1|S态软件中断|
|1|3|M态软件中断|
|1|5|S态计时器中断|
|1|7|M态计时器中断|
|1|9|S态外部中断|
|1|11|M态外部中断|
|0|2|非法指令|
|0|8|U态环境调用|
|0|9|S态环境调用|
|0|11|M态环境调用|
|0|13|缺页异常|

|优先级|异常码|描述|
|:--:|--:|:--|
|最高|2|非法指令|
|最低|8,9,11|环境调用|

## 3.2. 机器态特权指令

### 3.2.1. 环境调用

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">func12</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr><td>ECALL</td><td><i>00000</i></td><td>PRIV</td><td><i>00000</i></td><td>SYSTEM</td></tr>
</table>

`ECALL`在U态，S态，M态执行时，分别产生`environment-call-from-U-mode`，`environment-call-from-S-mode`，`environment-call-from-M-mode`异常。

### 3.2.2. 陷阱返回指令

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">func12</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr><td>MRET/SRET</td><td><i>00000</i></td><td>PRIV</td><td><i>00000</i></td><td>SYSTEM</td></tr>
</table>

`MRET`和`SRET`用于在陷阱处理后从对应特权等级返回。

### 3.2.3. 等待中断

`WFI`用于暂停当前程序知道中断产生。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">func12</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr><td>WFI</td><td><i>00000</i></td><td>PRIV</td><td><i>00000</i></td><td>SYSTEM</td></tr>
</table>

## 3.3. 复位

机器复位后，特权等级置为$M$，$mstatus$的$MIE$字段置为$0$。$pc$置为实现确定的特定值。

## 3.4. 不可屏蔽中断

不可屏蔽中断只用于硬件错误，立即跳转到实现确定的NMI地址上，特权等级置为$M$。

# 4. 操作系统态ISA

## 4.1. 页式虚拟内存

# 5. mesy特权指令集列表

<table border="1" style="border-collapse:collapse;width:100%;text-align:center">
<caption>陷阱返回指令</caption>
<tr>
    <td style="width:20%">0001000</th>
    <td style="width:14%">00010</th>
    <td style="width:14%">00000</th>
    <td style="width:8%">000</th>
    <td style="width:14%">00000</th>
    <td style="width:20%">1110011</th>
    <td>SRET</td>
</tr>
<tr><td>0011000</td><td>00010</td><td>00000</td><td>000</td><td>00000</td><td>1110011</td><td>MRET</td></tr>
</table>

<table border="1" style="border-collapse:collapse;width:100%;text-align:center">
<caption>中断管理指令</caption>
<tr>
    <td style="width:20%">0001000</th>
    <td style="width:14%">00101</th>
    <td style="width:14%">00000</th>
    <td style="width:8%">000</th>
    <td style="width:14%">00000</th>
    <td style="width:20%">1110011</th>
    <td>WFI</td>
</tr>
</table>
