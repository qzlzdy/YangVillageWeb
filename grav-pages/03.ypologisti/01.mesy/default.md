---
title: mesy指令集架构
---

- [1. mesy指令集架构](#1-mesy指令集架构)
- [2. 基本整数指令集](#2-基本整数指令集)
  - [2.1. 编程模型](#21-编程模型)
  - [2.2. 指令格式](#22-指令格式)
  - [2.3. 立即数编码](#23-立即数编码)
  - [2.4. 整数计算指令](#24-整数计算指令)
  - [2.5. 控制转移指令](#25-控制转移指令)
  - [2.6. 载入和储存指令](#26-载入和储存指令)
  - [2.7. 环境调用](#27-环境调用)
- [3. 整数乘除扩展(M)](#3-整数乘除扩展m)
  - [3.1. 乘法操作](#31-乘法操作)
  - [3.2. 除法操作](#32-除法操作)
- [4. 原子指令扩展(A)](#4-原子指令扩展a)
- [5. 控制状态寄存器指令扩展(Zicsr)](#5-控制状态寄存器指令扩展zicsr)
  - [5.1. CSR指令](#51-csr指令)
- [6. 单精度浮点数扩展(F)](#6-单精度浮点数扩展f)
- [7. mesy指令集列表](#7-mesy指令集列表)

# 1. mesy指令集架构

原型：[RISC-V](https://riscv.org/technical/specifications/)

---

设计指令集架构\(Instruction Set Architecture, ISA\)是建造红石计算机的第一步。ISA是计算机硬件系统设计的依据，也是软件系统能够在计算机上运行的基础。mesy是基于RISC-V针对红石计算机的设计目标进行修改后的指令集。

mesy对于RISC-V的不同：

- mesy只使用部分扩展。mesy固定使用IMAFDZicsr扩展的内容，但可能不通过硬件实现，而是通过软件模拟。mesy删除了其他扩展的内容。
- mesy只支持32位地址空间。
- mesy只支持单核、单处理器。
- mesy没有可变长指令，指令固定为32位。

下文主要介绍非特权级架构，特权级架构参阅[此处](../mesy-priv)

# 2. 基本整数指令集

mesy删除了内存排序指令。

## 2.1. 编程模型

mesy的编程模型与RV32I一致，有32个32位通用寄存器`x0-x31`，和一个程序计数器`pc`。其中`x0`硬编码为`0`。

## 2.2. 指令格式

mesy的指令格式与RV32I基本一致，根据立即数编码方式分为6类。

**R型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:22%"><ruby>func7<rt>31:25</rt></ruby></td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**I型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:38%"><ruby>imm[11:0]<rt>31:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**S型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:22%"><ruby>imm[11:5]<rt>31:25</rt></ruby></td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>imm[4:0]<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**B型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:22%"><ruby>imm[13|11:6]<rt>31|30:25</rt></ruby></td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>imm[5:2|12]<rt>11:8|7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**U型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:62%"><ruby>imm[31:12]<rt>31:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**J型指令**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:62%">
        <ruby>imm[21|11:2|12|20:13]<rt>31|30:21|20|19:12</rt></ruby>
    </td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

## 2.3. 立即数编码

mesy的立即数编码与RISC-V基本一致。因为mesy中不包含16位长指令，指令地址偏移量固定为4字节，因此B型、J型指令中的立即数的低2位均为0。

**I型立即数**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:66%"><ruby>inst[31]<rt>31:11</rt></ruby></td>
    <td><ruby>inst[30:20]<rt>10:0</rt></ruby></td>
</tr></table>

**S型立即数**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:66%"><ruby>inst[31]<rt>31:11</rt></ruby></td>
    <td style="width:19%"><ruby>inst[30:25]<rt>10:5</rt></ruby></td>
    <td><ruby>inst[11:7]<rt>4:0</rt></ruby></td>
</tr></table>

**B型立即数**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:59%"><ruby>inst[31]<rt>31:13</rt></ruby></td>
    <td style="width:34%">
        <ruby>inst[7|30:25|11:8]<rt>12|11:6|5:2</rt></ruby>
    </td>
    <td><ruby>0<rt>1:0</rt></ruby></td>
</tr></table>

**U型立即数**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:62%"><ruby>inst[31:12]<rt>31:12</rt></ruby></td>
    <td><ruby>0<rt>11:0</rt></ruby></td>
</tr></table>

**J型立即数**

<table border="1" style="border-collapse:collapse;width:100%;text-align:center"><tr>
    <td style="width:34%"><ruby>inst[31]<rt>31:21</rt></ruby></td>
    <td style="width:59%">
        <ruby>inst[19:12|20|30:21]<rt>20:13|12|11:2</rt></ruby>
    </td>
    <td><ruby>0<rt>1:0</rt></ruby></td>
</tr></table>

## 2.4. 整数计算指令

**整数RI指令**

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">imm[11:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>I-Imm[11:0]</i></td>
    <td><i>src</i></td>
    <td>ADDI/SLTI[U]</td>
    <td><i>dest</i></td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td><i>I-Imm[11:0]</i></td>
    <td><i>src</i></td>
    <td>ANDI/ORI/XORI</td>
    <td><i>dest</i></td>
    <td>OP-IMM</td>
</tr>
</table>

`ADDI`将立即数与$rs1$相加。

`SLTI`做有符号数比较，当$rs1$小于立即数时在$rd$写入$1$，否则写入$0$。`SLTIU`与`SLTI`相似，但做无符号数比较。

`ANDI`，`ORI`，`XORI`分别做位与，位或，位异或运算。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">imm[11:5]</th>
    <th style="width:16%;text-align:center">imm[4:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>0000000</i></td>
    <td><i>shamt</i></td>
    <td><i>rs1</i></td>
    <td>SLLI</td>
    <td><i>dest</i></td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td><i>0000000</i></td>
    <td><i>shamt</i></td>
    <td><i>rs1</i></td>
    <td>SRLI</td>
    <td><i>dest</i></td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td><i>0100000</i></td>
    <td><i>shamt</i></td>
    <td><i>rs1</i></td>
    <td>SRAI</td>
    <td><i>dest</i></td>
    <td>OP-IMM</td>
</tr>
</table>

I型移位指令，将$rs1$偏移常数位，偏移量取立即数低$5$位。`SLLI`做逻辑左移；`SRLI`做逻辑右移；`SRAI`做算术右移。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:62%;text-align:center">imm[31:12]</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>U-Imm[31:12]</i></td>
    <td><i>dest</i></td>
    <td>LUI</td>
</tr>
<tr>
    <td><i>U-Imm[31:12]</i></td>
    <td><i>dest</i></td>
    <td>AUIPC</td>
</tr>
</table>

`LUI`将立即数在低位补$12$位$0$后存入$rd$。

`AUIPC`将立即数在低位补$12$位$0$后与$pc$相加。

!!! `AUIPC`使用的$pc$值实际上是紧跟`AUIPC`后一条指令的地址，即$pc+4$。

**整数RR指令**

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">func7</th>
    <th style="width:16%;text-align:center">rs2</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>0000000</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>ADD/SLT/SLTU</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
<tr>
    <td><i>0000000</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>AND/OR/XOR</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
<tr>
    <td><i>0000000</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>SLL/SRL</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
<tr>
    <td><i>0100000</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>SUB/SRA</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
</table>

`ADD`将$rs1$和$rs2$相加。`SUB`将$rs1$减去$rs2$。`SLT`和`SLTU`分别做无符号和有符号比较，当$rs1$小于$rs2$时在$rd$写入$1$，否则写入$0$。`AND`，`OR`，`XOR`分别做位与，位或，位异或操作。

`SLL`，`SRL`，`SRA`分别做逻辑左移，逻辑右移，算术右移操作，偏移量取$rs2$低$5$位。

**NOP指令**

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">imm[11:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>0000_0000_0000</i></td>
    <td><i>00000</i></td>
    <td>ADDI</td>
    <td><i>00000</i></td>
    <td>OP-IMM</td>
</tr>
</table>

NOP指令即空指令。

## 2.5. 控制转移指令

**无条件跳转**

`JAL`可以寻址$\pm2MB$的空间，并把紧跟的指令地址，即$pc+4$存入$rd$。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:62%;text-align:center">imm[21|11:2|12|20:13]</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>offset[21:2]</i></td>
    <td><i>dest</i></td>
    <td>JAL</td>
</tr>
</table>

`JALR`通过基址寻址，并把紧跟的指令地址，即$pc+4$存入$rd$。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">imm[11:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>offset[11:0]</i></td>
    <td><i>base</i></td>
    <td><i>000</i></td>
    <td><i>dest</i></td>
    <td>JALR</td>
</tr>
</table>

**条件分支**

条件分支的寻址范围是$\pm8KB$。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">imm[13|11:6]</th>
    <th style="width:16%;text-align:center">rs2</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">imm[5:2|12]</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>offset[13|11:6]</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>BEQ/BNE</td>
    <td><i>offset[5:2|12]</i></td>
    <td>BRANCH</td>
</tr>
<tr>
    <td><i>offset[13|11:6]</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>BLT[U]</td>
    <td><i>offset[5:2|12]</i></td>
    <td>BRANCH</td>
</tr>
<tr>
    <td><i>offset[13|11:6]</i></td>
    <td><i>src2</i></td>
    <td><i>src1</i></td>
    <td>BGE[U]</td>
    <td><i>offset[5:2|12]</i></td>
    <td>BRANCH</td>
</tr>
</table>

`BEQ`，`BNE`分别在$rs1$和$rs2$相等，不相等时跳转。`BLT`，`BLTU`分别在有符号，无符号情况下$rs1$小于$rs2$时跳转。`BGE`，`BGEU`分别在有符号，无符号情况下$rs1$大于等于$rs2$时跳转。

## 2.6. 载入和储存指令

mesy固定使用小端格式。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">imm[11:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>offset[11:0]</i></td>
    <td><i>base</i></td>
    <td><i>width</i></td>
    <td><i>dest</i></td>
    <td>LOAD</td>
</tr>
</table>

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">imm[11:5]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">imm[4:0]</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td><i>offset[11:5]</i></td>
    <td><i>src</i></td>
    <td><i>base</i></td>
    <td><i>width</i></td>
    <td><i>offset[4:0]</i></td>
    <td>STORE</td>
</tr>
</table>

载入和储存指令在寄存器与内存之间传输数据。

`LW`载入$32$位字。`LH`载入$16$位有符号半字。`LHU`载入$16$位无符号半字。`LB`载入$8$位有符号字节。`LBU`载入$8$位无符号字节。`SW`，`SH`，`SB`分别储存$32$位，$16$位，$8$位数据。

载入和存储指令只支持地址自然对齐。

## 2.7. 环境调用

mesy删除了用于调试环境的`EBREAK`指令。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">func12</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>ECALL</td>
    <td><i>00000</i></td>
    <td>PRIV</td>
    <td><i>00000</i></td>
    <td>SYSTEM</td>
</tr>
</table>

`ECALL`用于调用执行环境的服务。

# 3. 整数乘除扩展(M)

## 3.1. 乘法操作

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">func7</th>
    <th style="width:16%;text-align:center">rs2</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>MULDIV</td>
    <td><i>multiplier</i></td>
    <td><i>multiplicand</i></td>
    <td>MUL/MULH[[S]U]</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
</table>

`MUL`做有符号乘法运算，取低$32$位结果。`MULH`，`MULHU`，`MULHSU`分别做有符号，无符号，混合符号乘法运算，取高$32$位结果。

## 3.2. 除法操作

<table style="width:100%;text-align:center">
<tr>
    <th style="width:22%;text-align:center">func7</th>
    <th style="width:16%;text-align:center">rs2</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>MULDIV</td>
    <td><i>divisor</i></td>
    <td><i>dividend</i></td>
    <td>DIV[U]/REM[U]</td>
    <td><i>dest</i></td>
    <td>OP</td>
</tr>
</table>

`DIV`，`DIVU`分别做有符号，无符号除法运算，结果取商，向零取整。运算时$rs1$做被除数，$rs2$做除数。`REM`，`REMU`分别作有符号，无符号除法运算，结果取余数。余数的符号与被除数的符号相同。

|条件|被除数|除数|DIVU|REMU|DIV|REM|
|:--|:--:|:--:|:--:|:--:|:--:|:--:|
|除数为零|$x$|$0$|$2^L-1$|$x$|$-1$|$x$|
|除法溢出|$-2^{L-1}$|$-1$|$-$|$-$|$-2^{L-1}$|$0$|

# 4. 原子指令扩展(A)

# 5. 控制状态寄存器指令扩展(Zicsr)

## 5.1. CSR指令

# 6. 单精度浮点数扩展(F)

# 7. mesy指令集列表