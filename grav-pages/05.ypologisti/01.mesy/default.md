---
title: mesy指令集架构
---

- [1. mesy指令集架构](#1-mesy指令集架构)
  - [1.1. 内存](#11-内存)
  - [1.2. 指令长度编码](#12-指令长度编码)
  - [1.3. 异常、陷阱和中断](#13-异常陷阱和中断)
- [2. 基础整数指令组](#2-基础整数指令组)
  - [2.1. 编程模型](#21-编程模型)
  - [2.2. 指令格式](#22-指令格式)
  - [2.3. 整数计算指令](#23-整数计算指令)
    - [2.3.1. RI指令](#231-ri指令)
    - [2.3.2. RR指令](#232-rr指令)
    - [2.3.3. NOP指令](#233-nop指令)
  - [2.4. 控制转移指令](#24-控制转移指令)
    - [2.4.1. 无条件跳转](#241-无条件跳转)
    - [2.4.2. 条件分支](#242-条件分支)
  - [2.5. 载入和储存指令](#25-载入和储存指令)
  - [2.6. 环境调用](#26-环境调用)
- [3. 整数乘除指令组(M)](#3-整数乘除指令组m)
  - [3.1. 乘法运算](#31-乘法运算)
  - [3.2. 除法运算](#32-除法运算)
- [4. 原子指令组(A)](#4-原子指令组a)
- [5. 控制状态寄存器指令组(Zicsr)](#5-控制状态寄存器指令组zicsr)
  - [5.1. CSR指令](#51-csr指令)
- [6. 计数器](#6-计数器)
  - [6.1. 基础计数器和计时器](#61-基础计数器和计时器)
- [7. 单精度浮点数指令组(F)](#7-单精度浮点数指令组f)
- [8. mesy指令集列表](#8-mesy指令集列表)
- [9. 汇编手册](#9-汇编手册)

# 1. mesy指令集架构

原型：[RISC-V](https://riscv.org/technical/specifications/)

---

设计指令集架构是建造红石计算机的第一步，它是计算机硬件系统设计的依据。mesy指令集是基于RISC-V针对红石计算机的设计目标进行修改后的指令集。为了减少红石计算机的建造工程量及设计复杂度，mesy指令集删除了较少使用的特性，只保留基础功能。

mesy指令集的目标：

- mesy不使用扩展，由组代替扩展。所有mesy中的组都是必选，对应原`IMAFDZicsr`扩展的内容。
- mesy只支持$32$位地址空间。
- mesy只支持单核、单处理器。
- mesy没有可变长指令，指令固定为$32$位。

下文主要介绍非特权级架构，特权级架构[参阅此处](../mesy-priv)

## 1.1. 内存

mesy有一块$2^{32}B$的内存空间。一个*字*对应$32$位；一个*半字*对应$16$位；一个*双字*对应$64$位。内存空间是循环的，即$2^{31}-1$地址与$0$地址相邻。

## 1.2. 指令长度编码

mesy的指令长度固定为$32$位，必须自然对齐。指令位全为$0$或全为$1$的都是非法指令。

## 1.3. 异常、陷阱和中断

*异常*指运行时出现的与当前指令相关的异常情况。*中断*指可能导致意外控制转移的外部异步事件。*陷阱*指由异常或中断导致的向服务程序的控制转移。

# 2. 基础整数指令组

## 2.1. 编程模型

mesy的基础整数指令组中有32个$32$位通用寄存器`x0-x31`，以及一个非特权寄存器——程序计数器`pc`。其中`x0`硬编码为$0$，`pc`记录当前指令的地址。

## 2.2. 指令格式

mesy的指令格式分为6类。所有格式的指令总是$32$位，必须自然对齐。源寄存器`rs1`、`rs2`，目的寄存器`rd`在所有格式中的位置保持一致。除CSR指令的立即数以外，所有立即数使用符号扩展。立即数的符号位总是指令中的最高位。

![指令格式](/images/mesy/InstructionFormats.png)

立即数在指令中编码的原则遵循最大重叠规则。

![立即数格式](/images/mesy/ImmediateFormats.png)

## 2.3. 整数计算指令

### 2.3.1. RI指令

![整数计算指令](/images/mesy/IntegerRegImmArith.png)

`ADDI`计算立即数与$rs1$的合，结果存入$rd$。

`SLTI`做有符号比较，当$rs1$小于立即数时$rd$置$1$。`SLTIU`与`SLTI`相似，但做无符号比较。

`ANDI`，`ORI`，`XORI`分别做位与，位或，位异或运算，结果存入$rd$。

![整数计算指令](/images/mesy/IntegerRegImmShift.png)

立即数移位指令编码为I型，偏移量编码在立即数低$5$位。右移位的类型编码在第$30$位。`SLLI`做逻辑左移；`SRLI`做逻辑右移；`SRAI`做算术右移。

![整数计算指令](/images/mesy/IntegerRegImmUpper.png)

`LUI`将立即数存入$rd$高$20$位，并在低$12$位填$0$。

`AUIPC`将立即数作为偏移量高$20$位，计算相对$pc$的偏移地址，结果存入$rd$。

!!! `AUIPC`使用的$pc$值实际上是紧跟`AUIPC`后一条指令的地址，即$pc+4$。

### 2.3.2. RR指令

所有整数RR指令的源寄存器为`rs1`和`rs2`，目的寄存器是`rd`。`func7`和`func3`字段表示指令的操作类型。

![整数计算指令](/images/mesy/IntegerRegReg.png)

`ADD`计算$rs1$和$rs2$的合。`SUB`计算$rs1$与$rs2$的差。`SLT`和`SLTU`分别做有符号和无符号比较，当$rs1$小于$rs2$时$rd$置$1$。`AND`，`OR`和`XOR`分别做位与，位或和位异或运算。

`SLL`，`SRL`和`SRA`分别做逻辑左移，逻辑右移，算术右移运算，偏移量取$rs2$的低$5$位。

### 2.3.3. NOP指令

![整数计算指令](/images/mesy/NopInstruction.png)

NOP指令即空指令，仅修改$pc$和启用的计数器的值。

## 2.4. 控制转移指令

mesy提供两类控制转移指令：无条件跳转和条件分支。mesy中没有延迟槽

### 2.4.1. 无条件跳转

`JAL`可以寻址$\pm2MB$的空间，并把紧跟的指令地址，即$pc+4$存入$rd$。

![控制转移指令](/images/mesy/JumpAndLink.png)

`JALR`通过基址寻址，并把紧跟的指令地址，即$pc+4$存入$rd$。

![控制转移指令](/images/mesy/JumpAndLinkRegister.png)

### 2.4.2. 条件分支

条件分支的寻址范围是$\pm8KB$。

![控制转移指令](/images/mesy/ConditionalBranches.png)

`BEQ`，`BNE`分别在$rs1$和$rs2$相等，不相等时跳转。`BLT`，`BLTU`分别在有符号，无符号情况下$rs1$小于$rs2$时跳转。`BGE`，`BGEU`分别在有符号，无符号情况下$rs1$大于等于$rs2$时跳转。

## 2.5. 载入和储存指令

mesy固定使用小端格式。

![载入指令](/images/mesy/LoadInstructions.png)

![储存指令](/images/mesy/StoreInstructions.png)

载入和储存指令在寄存器与内存之间传输数据。载入指令将内存中的值拷贝到寄存器。储存指令将寄存器中的值拷贝到内存。

`LW`载入$32$位数据。`LH`载入$16$位有符号数据。`LHU`载入$16$位无符号数据。`LB`载入$8$位有符号数据。`LBU`载入$8$位无符号数据。`SW`，`SH`，`SB`分别储存$32$位，$16$位，$8$位数据。

载入和存储指令只支持地址自然对齐。

## 2.6. 环境调用

`SYSTEM`指令用于访问需要特权级的系统功能。这些指令分为两大类：原子读写CSR的指令和其他指令。

![环境调用](/images/mesy/EnvironmentCall.png)

`ECALL`用于调用执行环境的服务。

# 3. 整数乘除指令组(M)

## 3.1. 乘法运算

![乘法运算](/images/mesy/Multiplication.png)

`MUL`做有符号乘法运算，取低$32$位结果。`MULH`，`MULHU`，`MULHSU`分别做有符号，无符号，混合符号乘法运算，取高$32$位结果。

## 3.2. 除法运算

![除法运算](/images/mesy/Division.png)

`DIV`，`DIVU`分别做有符号，无符号除法运算，结果取商，向零取整。`REM`，`REMU`分别作有符号，无符号除法运算，结果取余数。余数的符号与被除数的符号相同。

|条件|被除数|除数|DIVU|REMU|DIV|REM|
|:--|:--:|:--:|:--:|:--:|:--:|:--:|
|除数为零|$x$|$0$|$2^L-1$|$x$|$-1$|$x$|
|除法溢出|$-2^{L-1}$|$-1$|$-$|$-$|$-2^{L-1}$|$0$|

# 4. 原子指令组(A)

# 5. 控制状态寄存器指令组(Zicsr)

mesy定义了一个分离的地址空间，包含4096个CSR。

## 5.1. CSR指令

CSR指令对一个CSR做原子读写。CSR地址在指令高$12$位编码。立即数在`rs1`字段编码，做无符号扩展。

![CSR指令](/images/mesy/CsrInstructions.png)

`CSRRW`原子交换CSR与寄存器中的值。该指令读取CSR中的值存入$rd$，并将$rs1$写入CSR。

`CSRRS`读取CSR的值存入$rd$，并以$rs1$为掩码将CSR置$1$。

`CSRRC`读取CSR的值存入$rd$，并以$rs1$为掩码将CSR置$0$。

`CSRRWI`，`CSRRSI`和`CSRRCI`与`CSRRW`，`CSRRS`和`CSRRC`相似，但用无符号立即数代替$rs1$。

# 6. 计数器

## 6.1. 基础计数器和计时器

![计数器](/images/mesy/CountersAndTimers.png)

mesy提供了数个$64$位只读用户态计数器。

`RDCYCLE`和`RDCYCLEH`分别读取`cycle`的低$32$位和高$32$位。`cycle`计数器在每个机器周期自增。

`RDINSTRET`和`RDINSTRETH`分别读取`instret`的低$32$位和高$32$位。

!!! 读取64位计数器的示例代码
!!!
!!! ```gas
!!! again:
!!!     rdcycleh    $3
!!!     rdcycle     $2
!!!     rdcycleh    $4
!!!     bne         $3, $4, again
!!! ```

# 7. 单精度浮点数指令组(F)

# 8. mesy指令集列表

**mesy编码表**，$instr[1:0]=11$。

![编码表](/images/mesy/OpcodeMap.png)

**基础指令组**

![基础指令组](/images/mesy/IntegerGroup.png)

**Zicsr指令组**

![Zicsr指令组](/images/mesy/ZicsrGroup.png)

**M指令组**

![M指令组](/images/mesy/MulDivGroup.png)

**A指令组**

![A指令组](/images/mesy/AtomicGroup.png)

**F指令组**

![F指令组](/images/mesy/FloatGroup.png)

# 9. 汇编手册

**汇编寄存器助记符**

|寄存器|别名|描述|保存方|
|:--|:--|:--|:--:|
|$x0$|$zero$|硬编码到$0$|$-$|
|$x1$|$ra$|返回地址|调用者|
|$x2$|$sp$|栈指针|被调用者|
|$x3$|$gp$|全局指针|$-$|
|$x4$|$tp$|线程指针|$-$|
|$x5$|$t0$|临时链接|调用者|
|$x6-7$|$t1-2$|临时|调用者|
|$x8$|$s0/fp$|非临时/页框指针|被调用者|
|$x9$|$s1$|非临时|被调用者|
|$x10-11$|$a0-1$|函数参数/返回值|调用者|
|$x12-17$|$a2-7$|函数参数|调用者|
|$x18-27$|$s2-11$|非临时|被调用者|
|$x28-31$|$t3-6$|临时|调用者|

**汇编伪指令**

|伪指令|基础指令|语义|
|:--|:--|:--|
|`la rd, symbol`|`auipc rd, delta[31:12] + delta[11]`<br/>`lw rd, rd, delta[11:0]`|载入绝对地址|
|`lla rd, symbol`|`auipc rd, delta[31:12] + delta[11]`<br/>`addi rd, rd, delta[11:0]`|载入相对地址|
|`l{b,h,w} rd, symbol`|`auipc rd, delta[31:12] + delta[11]`<br/>`l{b,h,w} rd, delta[11:0]`|全局加载|
|`s{b,h,w} rd, symbol, rt`|`auipc rt, delta[31:12] + delta[11]`<br/>`s{b,h,w} rd, delta[11:0](rt)`|全局储存|
|`nop`|`addi $0, $0, 0`|空指令|
|`li rd, immediate`|多条指令序列|加载立即数|
|`mv rd, rs`|`addi rd, rs, 0`|复制|
|`not rd, rs`|`xori rd, rs, -1`|位非|
|`neg rd, rs`|`sub rd, $0, rs`|相反数|
|`seqz rd, rs`|`sltiu rd, rs, 1`|$rs=0$时置$1$|
|`snez rd, rs`|`sltu rd, $0, rs`|$rs\neq0$时置$1$|
|`sltz rd, rs`|`slt rd, rs, $0`|$rs<0$时置$1$|
|`sgtz rd, rs`|`slt rd, $0, rs`|$rs>0$时置$1$|
|`beqz rs, offset`|`beq rs, $0, offset`|$rs=0$时跳转|
|`bnez rs, offset`|`bne rs, $0, offset`|$rs\neq0$时跳转|
|`blez rs, offset`|`bge $0, rs, offset`|$rs\le0$时跳转|
|`bgez rs, offset`|`bge rs, $0, offset`|$rs\ge0$时跳转|
|`bltz rs, offset`|`blt rs, $0, offset`|$rs<0$时跳转|
|`bgtz rs, offset`|`blt $0, rs, offset`|$rs>0$时跳转|
|`bgt rs, rt, offset`|`blt rt, rs, offset`|大于时跳转|
|`ble rs, rt, offset`|`bge rt, rs, offset`|小于等于时跳转|
|`bgtu rs, rt, offset`|`bltu rt, rs, offset`|大于时跳转（无符号）|
|`bleu rs, rt, offset`|`bgeu rt, rs, offset`|小于等于时跳转（无符号）|
|`j offset`|`jal $0, offset`|只跳转|
|`jal offset`|`jal $1, offset`|跳转并链接|
|`jr rs`|`jalr $0, 0(rs)`|跳转寄存器|
|`jalr rs`|`jalr $1, 0(rs)`|跳转寄存器并链接|
|`ret`|`jalr $0, 0($1)`|返回|
|`call offset`|`auipc $1, offset[31:12] + offset[11]`<br/>`jalr $1, offset[11:0]($1)`|调用|
|`tail offset`|`auipc $6, offset[31:12] + offset[11]`<br/>`jalr $0, offset[11:0]($6)`|尾调用|
|`rdinstret[h] rd`|`csrrs rd, instret[h], $0`|读$instret$|
|`rdcycle[h] rd`|`csrrs rd, cycle[h], $0`|读$cycle$|
|`csrr rd, csr`|`csrrs rd, csr, $0`|读CSR|
|`csrw csr, rs`|`csrrw $0, csr, rs`|写CSR|
|`csrs csr, rs`|`csrrs $0, csr, rs`|CSR置$1$|
|`csrc csr, rs`|`csrrc $0, csr, rs`|CSR置$0$|
|`csrwi csr, imm`|`csrwi $0, csr, imm`|写CSR（立即数）|
|`csrsi csr, imm`|`csrrs $0, csr, imm`|CSR置$1$（立即数）|
|`csrci csr, imm`|`csrrc $0, csr, imm`|CSR置$0$（立即数）|
