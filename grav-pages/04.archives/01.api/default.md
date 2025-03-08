---
title: 羊村公告板
menu: API文档
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
# 1. 羊村便民中心API文档

- [1. 羊村便民中心API文档](#1-羊村便民中心api文档)
- [2. 复读](#2-复读)
  - [2.1. 请求](#21-请求)
  - [2.2. 响应](#22-响应)

# 2. 复读

`GET /echo?echo={content}`

原样复读传入的内容。

## 2.1. 请求

`content`: 任意内容

!!! 示例：https://api.yangvillage.top/echo?echo=hello

## 2.2. 响应

`200`：返回`{content}`

`400`：错误
