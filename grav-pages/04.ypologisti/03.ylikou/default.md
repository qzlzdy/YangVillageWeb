---
title: ylikou处理器
---

- [1. ylikou处理器](#1-ylikou处理器)
- [2. 取指](#2-取指)
- [3. 执行](#3-执行)
- [4. 写回](#4-写回)
- [5. 访存](#5-访存)
- [6. 缓存](#6-缓存)

# 1. ylikou处理器

原型：[riscv-mini][1]
实现语言：[Chisel3](https://www.chisel-lang.org/)

[1]: https://github.com/ucb-bar/riscv-mini.git

---

ylikou处理器是mesy ISA在本工程的实现。原型是[`ucb-bar/riscv-mini`][1]，但也参考了[`OpenXiangShan/XiangShan`][2]。

[2]: https://github.com/OpenXiangShan/XiangShan.git

ylikou使用Chisel3库实现。Chisel3是Scala语言下的用于硬件设计的库，提供了很多内置的硬件模块。但ylikou尽量少使用这些模块，因为ylikou最终需要用红石电路实现，即精确到门级建模。

!!! 为什么不直接用Verilog - Verilog在接口方面支持较差，而处理器接口又多。而SystemVerilog虽然在接口方面有所改进，但内置硬件模块仍不能满足ylikou的需要。

ylikou与riscv-mini一样是三段流水线设计，即取指，执行，写回三个阶段。不同于MIPS ISA，ylikou的分支、访存指令没有延迟槽。ylikou在执行分支、访存指令时，通过插入空泡阻塞流水线。ylikou只有哈佛结构的L1 Cache，Cache与内存通过syndesmos协议交互。

# 2. 取指

ylikou的取指阶段非常简单，包括以下微步骤：

1. 取指目标生成器根据当前机器状态选择指令地址，取指目标来源一般有：
   1. $pc+4$（绝大部分情况）
   2. $pc$（插入空泡）
   3. $tvec$（发生陷阱时）
   4. $epc$（陷阱返回时）
   5. $ALU$（跳转时）
2. 将取指目标传输至L1I，同时更新$pc$。指令将在下一阶段返回。

# 3. 执行

# 4. 写回

# 5. 访存

# 6. 缓存
