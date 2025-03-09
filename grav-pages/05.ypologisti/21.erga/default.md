---
title: erga编译工具链
---
<!--
    YangVillage Website
    Copyright (C) 2024  Qzlzdy

    This content is licensed under the Creative Commons Attribution Share Alike
    4.0 International (CC-BY-SA-4.0).

    See <https://creativecommons.org/licenses/by-sa/4.0/>.
-->
- [1. erga编译工具链](#1-erga编译工具链)
- [2. metag编译器](#2-metag编译器)
- [3. symvo汇编器](#3-symvo汇编器)
- [4. synde链接器](#4-synde链接器)

# 1. erga编译工具链

原型：[LLVM](https://llvm.org/)

---

erga编译工具链包含了将glossa语言翻译成ylikou架构机器代码的所有组件。

# 2. metag编译器

metag将glossa语言翻译成mesy汇编指令，作为symvo汇编器的输入。

# 3. symvo汇编器

symvo将mesy汇编指令翻译成ylikou机器代码，产生对象文件。

# 4. synde链接器

synde将多个对象文件链接为一个可执行文件。
