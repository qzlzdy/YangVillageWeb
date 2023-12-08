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
- [整数乘除扩展(M)](#整数乘除扩展m)
  - [乘法操作](#乘法操作)

# 1. mesy指令集架构

原型：[RISC-V](https://riscv.org/technical/specifications/)

---

设计指令集架构\(Instruction Set Architecture, ISA\)是建造红石计算机的第一步。ISA是计算机硬件系统设计的依据，也是软件系统能够在计算机上运行的基础。mesy是基于RISC-V针对红石计算机的设计目标进行修改后的指令集。

mesy对于RISC-V的不同：

- mesy只使用部分扩展。mesy固定使用IMAFDZicsr扩展的内容，但可能不通过硬件实现，而是通过软件模拟。mesy删除了其他扩展的内容。
- mesy只支持32位地址空间。
- mesy只支持单核、单处理器。
- mesy没有可变长指令，指令固定为32位。

# 2. 基本整数指令集

mesy删除了内存排序指令

## 2.1. 编程模型

mesy的编程模型与RV32I一致，有32个32位通用寄存器`x0-x31`，和一个程序计数器`pc`。其中`x0`硬编码为`0`。

## 2.2. 指令格式

mesy的指令格式与RV32I基本一致，根据立即数编码方式分为6类。

**R型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:22%"><ruby>func7<rt>31:25</rt></ruby></td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**I型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:38%"><ruby>imm[11:0]<rt>31:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**S型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:22%"><ruby>imm[11:5]<rt>31:25</rt></ruby></td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%"><ruby>imm[4:0]<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**B型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:22%">{
        <ruby>imm[13]<rt>31</rt></ruby>,
        <ruby>imm[11:6]<rt>30:25</rt></ruby>
    }</td>
    <td style="width:16%"><ruby>rs2<rt>24:20</rt></ruby></td>
    <td style="width:16%"><ruby>rs1<rt>19:15</rt></ruby></td>
    <td style="width:9%"><ruby>func3<rt>14:12</rt></ruby></td>
    <td style="width:16%">{
        <ruby>imm[5:2]<rt>11:8</rt></ruby>,
        <ruby>imm[12]<rt>7</rt></ruby>
    }</td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**U型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:62%"><ruby>imm[31:12]<rt>31:12</rt></ruby></td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

**J型指令**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:62%">{
        <ruby>imm[21]<rt>31</rt></ruby>,
        <ruby>imm[11:2]<rt>30:21</rt></ruby>,
        <ruby>imm[12]<rt>20</rt></ruby>,
        <ruby>imm[20:13]<rt>19:12</rt></ruby>
    }</td>
    <td style="width:16%"><ruby>rd<rt>11:7</rt></ruby></td>
    <td><ruby>opcode<rt>6:0</rt></ruby></td>
</tr></table>

## 2.3. 立即数编码

mesy的立即数编码与RISC-V基本一致。因为mesy中不包含16位长指令，指令地址偏移量固定为4字节，因此B型、J型指令中的立即数的低2位均为0。

**I型立即数**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:66%"><ruby>inst[31]<rt>31:11</rt></ruby></td>
    <td><ruby>inst[30:20]<rt>10:0</rt></ruby></td>
</tr></table>

**S型立即数**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:66%"><ruby>inst[31]<rt>31:11</rt></ruby></td>
    <td style="width:19%"><ruby>inst[30:25]<rt>10:5</rt></ruby></td>
    <td><ruby>inst[11:7]<rt>4:0</rt></ruby></td>
</tr></table>

**B型立即数**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:59%"><ruby>inst[31]<rt>31:13</rt></ruby></td>
    <td style="width:34%">{
        <ruby>inst[7]<rt>12</rt></ruby>,
        <ruby>inst[30:25]<rt>11:6</rt></ruby>,
        <ruby>inst[11:8]<rt>5:2</rt></ruby>
    }</td>
    <td><ruby>0<rt>1:0</rt></ruby></td>
</tr></table>

**U型立即数**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:62%"><ruby>inst[31:12]<rt>31:12</rt></ruby></td>
    <td><ruby>0<rt>11:0</rt></ruby></td>
</tr></table>

**J型立即数**

<table border="1" style="width:100%;text-align:center"><tr>
    <td style="width:34%"><ruby>inst[31]<rt>31:21</rt></ruby></td>
    <td style="width:59%">{
        <ruby>inst[19:12]<rt>20:13</rt></ruby>,
        <ruby>inst[20]<rt>12</rt></ruby>,
        <ruby>inst[30:21]<rt>11:2</rt></ruby>
    }</td>
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
    <td>I-Imm[11:0]</td>
    <td>src</td>
    <td>ADDI/SLTI[U]</td>
    <td>dest</td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td>I-Imm[11:0]</td>
    <td>src</td>
    <td>ANDI/ORI/XORI</td>
    <td>dest</td>
    <td>OP-IMM</td>
</tr>
</table>

`ADDI`将立即数与`rs1`相加。

`SLTI`做有符号数比较，当`rs1`小于立即数时在`rd`写入`1`，否则写入`0`。`SLTIU`与`SLTI`相似，但做无符号数比较。

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
    <td>0000000</td>
    <td>shamt</td>
    <td>rs1</td>
    <td>SLLI</td>
    <td>dest</td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td>0000000</td>
    <td>shamt</td>
    <td>rs1</td>
    <td>SRLI</td>
    <td>dest</td>
    <td>OP-IMM</td>
</tr>
<tr>
    <td>0100000</td>
    <td>shamt</td>
    <td>rs1</td>
    <td>SRAI</td>
    <td>dest</td>
    <td>OP-IMM</td>
</tr>
</table>

I型移位指令，将`rs1`偏移常数位，偏移量取立即数低5位。`SLLI`做逻辑左移；`SRLI`做逻辑右移；`SRAI`做算术右移。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:62%;text-align:center">imm[31:12]</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>U-Imm[31:12]</td>
    <td>dest</td>
    <td>LUI</td>
</tr>
<tr>
    <td>U-Imm[31:12]</td>
    <td>dest</td>
    <td>AUIPC</td>
</tr>
</table>

`LUI`将立即数在低位补12位`0`后存入`rd`。

`AUIPC`将立即数在低位补12位`0`后与`pc`相加。

!!! `AUIPC`使用的`pc`值实际上是紧跟`AUIPC`后一条指令的地址，即`pc+4`。

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
    <td>0000000</td>
    <td>src2</td>
    <td>src1</td>
    <td>ADD/SLT/SLTU</td>
    <td>dest</td>
    <td>OP</td>
</tr>
<tr>
    <td>0000000</td>
    <td>src2</td>
    <td>src1</td>
    <td>AND/OR/XOR</td>
    <td>dest</td>
    <td>OP</td>
</tr>
<tr>
    <td>0000000</td>
    <td>src2</td>
    <td>src1</td>
    <td>SLL/SRL</td>
    <td>dest</td>
    <td>OP</td>
</tr>
<tr>
    <td>0100000</td>
    <td>src2</td>
    <td>src1</td>
    <td>SUB/SRA</td>
    <td>dest</td>
    <td>OP</td>
</tr>
</table>

`ADD`将`rs1`和`rs2`相加。`SUB`将`rs1`减去`rs2`。`SLT`和`SLTU`分别做无符号和有符号比较，当`rs1`小于`rs2`时在`rd`写入`1`，否则写入`0`。`AND`，`OR`，`XOR`分别做位与，位或，位异或操作。

`SLL`，`SRL`，`SRA`分别做逻辑左移，逻辑右移，算术右移操作，偏移量取`rs2`低5位。

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
    <td>0000_0000_0000</td>
    <td>00000</td>
    <td>ADDI</td>
    <td>00000</td>
    <td>OP-IMM</td>
</tr>
</table>

NOP指令即空指令。

## 2.5. 控制转移指令

**无条件跳转**

`JAL`可以寻址前后`2MB`的空间，并把紧跟的指令地址，即`pc+4`存入`rd`。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:62%;text-align:center">imm[21|11:2|12|20:13]</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>offset[21:2]</td>
    <td>dest</td>
    <td>JAL</td>
</tr>
</table>

`JALR`通过基址寻址，并把紧跟的指令地址，即`pc+4`存入`rd`。

<table style="width:100%;text-align:center">
<tr>
    <th style="width:38%;text-align:center">imm[11:0]</th>
    <th style="width:16%;text-align:center">rs1</th>
    <th style="width:9%;text-align:center">func3</th>
    <th style="width:16%;text-align:center">rd</th>
    <th style="text-align:center">opcode</th>
</tr>
<tr>
    <td>offset[11:0]</td>
    <td>base</td>
    <td>000</td>
    <td>dest</td>
    <td>JALR</td>
</tr>
</table>

**条件分支**

条件分支的寻址范围是前后`8KB`。

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
    <td>offset[13|11:6]</td>
    <td>src2</td>
    <td>src1</td>
    <td>BEQ/BNE</td>
    <td>offset[5:2|12]</td>
    <td>BRANCH</td>
</tr>
<tr>
    <td>offset[13|11:6]</td>
    <td>src2</td>
    <td>src1</td>
    <td>BLT[U]</td>
    <td>offset[5:2|12]</td>
    <td>BRANCH</td>
</tr>
<tr>
    <td>offset[13|11:6]</td>
    <td>src2</td>
    <td>src1</td>
    <td>BGE[U]</td>
    <td>offset[5:2|12]</td>
    <td>BRANCH</td>
</tr>
</table>

`BEQ`，`BNE`分别在`rs1`和`rs2`相等，不相等时跳转。`BLT`，`BLTU`分别在有符号，无符号情况下`rs1`小于`rs2`时跳转。`BGE`，`BGEU`分别在有符号，无符号情况下`rs1`大于等于`rs2`时跳转。

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
    <td>offset[11:0]</td>
    <td>base</td>
    <td>width</td>
    <td>dest</td>
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
    <td>offset[11:5]</td>
    <td>src</td>
    <td>base</td>
    <td>width</td>
    <td>offset[4:0]</td>
    <td>STORE</td>
</tr>
</table>

载入和储存指令在寄存器与内存之间传输数据。

`LW`载入32位字。`LH`载入16位有符号半字。`LHU`载入16位无符号半字。`LB`载入8位有符号字节。`LBU`载入8位无符号字节。`SW`，`SH`，`SB`分别储存32位，16位，8位数据。

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
    <td>00000</td>
    <td>PRIV</td>
    <td>00000</td>
    <td>SYSTEM</td>
</tr>
</table>

`ECALL`用于调用执行环境的服务。

# 整数乘除扩展(M)

## 乘法操作


