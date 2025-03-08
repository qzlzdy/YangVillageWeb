---
title: erga编译工具链
---
<!--
    YangVillage Website
    Copyright (C) 2024  Qzlzdy

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
