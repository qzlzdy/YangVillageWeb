---
title: 羊村公告板
menu: API文档
---
<!--
    YangVillage Website
    Copyright (C) 2024  Qzlzdy

    This content is licensed under the Creative Commons Attribution Share Alike
    4.0 International (CC-BY-SA-4.0).

    See <https://creativecommons.org/licenses/by-sa/4.0/>.
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
