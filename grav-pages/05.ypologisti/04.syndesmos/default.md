---
title: syndesmos协议
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
- [1. syndesmos协议](#1-syndesmos协议)
- [2. 架构](#2-架构)
  - [2.1. 网络拓扑](#21-网络拓扑)
  - [2.2. 通道优先级](#22-通道优先级)
- [3. 信号](#3-信号)
  - [3.1. 信号命名](#31-信号命名)
  - [3.2. 时钟、复位信号和电源](#32-时钟复位信号和电源)
    - [3.2.1. 时钟](#321-时钟)
    - [3.2.2. 复位](#322-复位)
  - [3.3. A通道](#33-a通道)
  - [3.4. B通道](#34-b通道)
  - [3.5. C通道](#35-c通道)
  - [3.6. D通道](#36-d通道)
  - [3.7. E通道](#37-e通道)
- [4. 序列化](#4-序列化)
- [5. 操作和消息](#5-操作和消息)
  - [5.1. 操作分类](#51-操作分类)
  - [5.2. 消息分类](#52-消息分类)
    - [5.2.1. `AcquireBlock`](#521-acquireblock)
    - [5.2.2. `AcquirePerm`](#522-acquireperm)
    - [5.2.3. `ProbeBlock`](#523-probeblock)
    - [5.2.4. `ProbePerm`](#524-probeperm)
    - [5.2.5. `ProbeAck`](#525-probeack)
    - [5.2.6. `ProbeAckData`](#526-probeackdata)
    - [5.2.7. `Grant`](#527-grant)
    - [5.2.8. `GrantData`](#528-grantdata)
    - [5.2.9. `GrantAck`](#529-grantack)
    - [5.2.10. `Release`](#5210-release)
    - [5.2.11. `ReleaseData`](#5211-releasedata)
    - [5.2.12. `ReleaseAck`](#5212-releaseack)
- [6. 权限](#6-权限)
  - [6.1. 权限转换](#61-权限转换)

# 1. syndesmos协议

原型：[TileLink](https://www.sifive.com/document-file/tilelink-spec-1.9.3)

---

syndesmos协议用于Cache与内存之间的通信，对应TL-C一致性等级。

- 为mesy架构设计，但也可用于其他架构
- 缓存一致性共享内存
- 具有解耦的接口

# 2. 架构

syndesmos以连接结点的树形定义，结点通过链路内的点对点通道发送和接受消息，在共享内存是执行操作。

## 2.1. 网络拓扑

结点对之间用链路连接。链路的一端与一个结点的主接口连接，另一端与另一个结点的从接口连接。带有主接口的结点可以向带有从接口请求权限或缓存数据。带有从接口的结点管理一段地址的访问权限。

## 2.2. 通道优先级

对每个链路，syndesmos定义有5个逻辑独立的通道，每个通道都是单向的。

**A通道**

- 传输缓存数据的请求。

**B通道**

- 传输协会缓存数据的请求。

**C通道**

- 根据请求传输数据或确认消息。

**D通道**

- 向原始请求者发送数据响应或确认消息。

**E通道**

- 从原始请求者处传输缓存块的最终确认。

通道之间的优先级升序排列为$A<B<C<D<E$。

# 3. 信号

**通道总览**

|通道|方向|作用|
|:--:|:--:|:--|
|A|主-从|请求向某地址发送消息|
|B|从-主|发送到缓存块的请求消息|
|C|主-从|缓存块的响应消息|
|D|从-主|某地址的响应消息|
|E|主-从|缓存块传输的最后握手|

**通道信号类型**

|类型|方向|描述|
|:--:|:--:|:--|
|X|输入|时钟或复位信号|
|C|顺向|控制信号|
|D|顺向|数据信号|
|V|顺向|有效信号，指示C/D信号合法性|
|R|反向|就绪信号，指示V信号被接受|

**链接参数**

|参数|描述|
|:--:|:--|
|$w$|数据总线宽度字节数|
|$a$|`address`字段位数|
|$z$|`size`字段位数|
|$o$|区分所有主设备的最少位数|

## 3.1. 信号命名

除了`clock`和`reset`信号外，信号由{通道标识符}_{信号名称}命名。

## 3.2. 时钟、复位信号和电源

syndesmos是同步协议，所有主从接口共享相同的时钟、复位信号和电源。

|信号|类型|宽度|描述|
|:--:|:--:|--:|:--|
|`clock`|X|$1$|总线时钟，上升沿触发|
|`reset`|X|$1$|总线复位，高电平触发|

### 3.2.1. 时钟

每个通道在时钟上升沿触发。输出信号只可能在时钟上升沿改变。

### 3.2.2. 复位

在复位结束前，所有`valid`信号为低电平。在复位时，就绪、控制和数据信号可以为任何值。

## 3.3. A通道

A通道由主接口流向从接口，传输发送到特定地址的请求消息。

|信号|类型|宽度|描述|
|:--|:--:|--:|:--|
|`a_opcode`|C|$2$|操作码，确定通道传输消息的类型|
|`a_param`|C|$3$|参数，指定缓存权限的转换|
|`a_size`|C|$z$|操作大小的对数字节数|
|`a_source`|C|$o$|主设备标识|
|`a_address`|C|$a$|操作的目标字节地址，对齐到`a_size`|
|`a_mask`|D|$w$|数据消息的字节掩码|
|`a_valid`|V|$1$|发送方正在发送请求|
|`a_ready`|R|$1$|接受方接受请求|

## 3.4. B通道

B通道由从接口流向主接口，传输向特定主设备的特定缓存块发送的请求消息。

|信号|类型|宽度|描述|
|:--|:--:|--:|:--|
|`b_opcode`|C|$2$|操作码，确定通道传输消息的类型|
|`b_param`|C|$3$|参数，指定缓存权限的转换|
|`b_size`|C|$z$|操作大小的对数字节数|
|`b_source`|C|$o$|主设备标识|
|`b_address`|C|$a$|操作的目标字节地址，对齐到`b_size`|
|`b_mask`|D|$w$|数据消息的字节掩码|
|`b_valid`|V|$1$|发送方正在发送请求|
|`b_ready`|R|$1$|接受方接受请求|

## 3.5. C通道

C通道由主接口流向从接口，向发送到特定缓存块的B通道请求发送响应消息，也用于主动写回脏数据。

|信号|类型|宽度|描述|
|:--|:--:|--:|:--|
|`c_opcode`|C|$2$|操作码，确定通道传输消息的类型|
|`c_param`|C|$3$|参数，指定缓存权限的转换|
|`c_size`|C|$z$|操作大小的对数字节数|
|`c_source`|C|$o$|主设备标识|
|`c_address`|C|$a$|操作的目标字节地址，对齐到`c_size`|
|`c_data`|D|$8w$|数据消息的载荷|
|`c_valid`|V|$1$|发送方正在发送请求|
|`c_ready`|R|$1$|接受方接受请求|

## 3.6. D通道

D通道由从接口流向主接口，向发送到特定地址的A通道请求发送响应消息，也用于向C通道主动写回发送确认消息。

|信号|类型|宽度|描述|
|:--|:--:|--:|:--|
|`d_opcode`|C|$2$|操作码，确定通道传输消息的类型|
|`d_param`|C|$3$|参数，指定缓存权限的转换|
|`d_size`|C|$z$|操作大小的对数字节数|
|`d_source`|C|$o$|主设备标识|
|`d_data`|D|$8w$|数据消息的载荷|
|`d_valid`|V|$1$|发送方正在发送请求|
|`d_ready`|R|$1$|接受方接受请求|

## 3.7. E通道

E通道由主接口流向从接口，传输D通道消息的接收确认。

|信号|类型|宽度|描述|
|:--|:--:|--:|:--|
|`e_valid`|V|$1$|发送方正在发送请求|
|`e_ready`|R|$1$|接受方接受请求|

!!! E通道只有一种操作，即`GrantAck`，无需额外字段

# 4. 序列化

当传输的数据大小比数据总线宽度大时，按照地址从低到高依次多周期传输。

# 5. 操作和消息

## 5.1. 操作分类

|操作|目的|
|:--|:--|
|Acquire|缓存一段地址的数据或增加缓存块的权限|
|Release|写回一段地址的缓存块或减少缓存块的权限|

## 5.2. 消息分类

![消息分类](/images/syndesmos/OperationsTaxonomy.png)

带有后缀`Data`的消息都有数据载荷。

**消息总览**，以操作类型分组

|消息|操作|opcode|A|B|C|D|E|响应|
|:--|:--|--:|:--|:--|:--|:--|:--|:--|
|`AcquireBlock`|Acquire|`0`|y|.|.|.|.|`GrantData`|
|`AcquirePerm`|Acquire|`1`|y|.|.|.|.|`Grant`|
|`Grant`|Acquire|`0`|.|.|.|y|.|`GrantAck`|
|`GrantData`|Acquire|`1`|.|.|.|y|.|`GrantAck`|
|`GrantAck`|Acquire|`-`|.|.|.|.|y| |
|`ProbeBlock`|Probe|`0`|.|y|.|.|.|`ProbeAckData`|
|`ProbePerm`|Probe|`1`|.|y|.|.|.|`ProbeAck`|
|`ProbeAck`|Probe|`0`|.|.|y|.|.| |
|`ProbeAckData`|Probe|`1`|.|.|y|.|.| |
|`Release`|Release|`2`|.|.|y|.|.|`ReleaseAck`|
|`ReleaseData`|Release|`3`|.|.|y|.|.|`ReleaseAck`|
|`ReleaseAck`|Release|`2`|.|.|.|y|.|`GrantAck`|

**消息总览**，以通道分组

![消息总览](/images/syndesmos/MessagesSummary.png)

### 5.2.1. `AcquireBlock`

`AcquireBlock`用于主设备获取数据缓存。

|A通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`a_opcode`|C|$2$|`AcquireBlock`|
|`a_param`|C|$3$|`Grow`权限组|
|`a_size`|C|$z$|从设备返回的对数字节数|
|`a_source`|C|$o$|主设备标识|
|`a_address`|C|$a$|操作的目标字节地址|
|`a_mask`|D|$w$|字节掩码|

### 5.2.2. `AcquirePerm`

`AcquirePerm`用于主设备提升缓存块权限。

|A通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`a_opcode`|C|$2$|`AcquirePerm`|
|`a_param`|C|$3$|`Grow`权限组|
|`a_size`|C|$z$|从设备返回的对数字节数|
|`a_source`|C|$o$|主设备标识|
|`a_address`|C|$a$|操作的目标字节地址|
|`a_mask`|D|$w$|字节掩码|

### 5.2.3. `ProbeBlock`

`ProbeBlock`用于从设备修改主设备缓存块权限。

|B通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`b_opcode`|C|$2$|`ProbeBlock`|
|`b_param`|C|$3$|`Cap`权限组|
|`b_size`|C|$z$|主设备Probe的对数字节数|
|`b_source`|C|$o$|主设备标识|
|`b_address`|C|$a$|操作的目标字节地址|
|`b_mask`|D|$w$|字节掩码|

### 5.2.4. `ProbePerm`

`ProbePerm`用于从设备修改主设备缓存块的权限。

|B通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`b_opcode`|C|$2$|`ProbePerm`|
|`b_param`|C|$3$|`Cap`权限组|
|`b_size`|C|$z$|主设备Probe的对数字节数|
|`b_source`|C|$o$|主设备标识|
|`b_address`|C|$a$|操作的目标字节地址|
|`b_mask`|D|$w$|字节掩码|

### 5.2.5. `ProbeAck`

`ProbeAck`用于主设备确认收到的Probe消息。

|C通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`c_opcode`|C|$2$|`ProbeAck`|
|`c_param`|C|$3$|`Shrink`或`Report`权限组|
|`c_size`|C|$z$|Probe的对数字节数|
|`c_source`|C|$o$|主设备标识|
|`c_address`|C|$a$|操作的目标字节地址|
|`c_data`|D|$8w$|忽略，可以为任意值|

### 5.2.6. `ProbeAckData`

`ProbeAckData`用于主设备确认受到的Probe消息并写回脏数据。

|C通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`c_opcode`|C|$2$|`ProbeAckData`|
|`c_param`|C|$3$|`Shrink`或`Report`权限组|
|`c_size`|C|$z$|Probe的对数字节数|
|`c_source`|C|$o$|主设备标识|
|`c_address`|C|$a$|操作的目标字节地址|
|`c_data`|D|$8w$|传输的数据载荷|

### 5.2.7. `Grant`

`Grant`用于从设备确认收到的Acquire消息，并向主设备提供权限。

|D通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`d_opcode`|C|$2$|`Grant`|
|`d_param`|C|$3$|`Cap`权限组|
|`d_size`|C|$z$|操作大小的对数字节数|
|`d_source`|C|$o$|主设备标识|
|`d_data`|D|$8w$|忽略，可以为任何值|

### 5.2.8. `GrantData`

`GrantData`用于从设备确认收到的Acquire消息，并提供缓存数据。

|D通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`d_opcode`|C|$2$|`GrantData`|
|`d_param`|C|$3$|`Cap`权限组|
|`d_size`|C|$z$|操作大小的对数字节数|
|`d_source`|C|$o$|主设备标识|
|`d_data`|D|$8w$|数据载荷|

### 5.2.9. `GrantAck`

`GrantAck`用于主设备响应传输操作的最终确认。

### 5.2.10. `Release`

`Release`用于主设备主动降低缓存块权限。

|C通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`c_opcode`|C|$2$|`Release`|
|`c_param`|C|$3$|`Shrink`或`Report`权限组|
|`c_size`|C|$z$|被降级的对数字节数|
|`c_source`|C|$o$|主设备标识|
|`c_address`|C|$a$|操作的目标字节地址|
|`c_data`|D|$8w$|忽略，可以为任何值|

### 5.2.11. `ReleaseData`

`ReleaseData`用于主设备主动降低缓存块权限，并写回脏数据。

|C通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`c_opcode`|C|$2$|`ReleaseData`|
|`c_param`|C|$3$|`Shrink`或`Report`权限组|
|`c_size`|C|$z$|被降级的对数字节数|
|`c_source`|C|$o$|主设备标识|
|`c_address`|C|$a$|操作的目标字节地址|
|`c_data`|D|$8w$|数据载荷|

### 5.2.12. `ReleaseAck`

`ReleaseAck`用于从设备确认收到的Release消息。

|D通道|类型|宽度|编码|
|:--|:--:|--:|:--|
|`d_opcode`|C|$2$|`ReleaseAck`|
|`d_param`|C|$3$|编码为0|
|`d_size`|C|$z$|操作大小的对数字节数|
|`d_source`|C|$o$|主设备标识|
|`d_data`|D|$8w$|忽略，可以为任何值|

# 6. 权限

内存访问操作要求结点获得正确的权限才能访问缓存。某个缓存块的权限可能是**无**、**只读**和**可读写**。每个结点根据其在一致性树中的位置分为四类：

**无**

- 未缓存数据的结点，无任何权限。

**主干**

- 具有缓存的结点，位于顶部和根结点之间，无任何权限。缓存的数据可能是过时的。

**顶部**

- 具有缓存的结点，有读写权限，可能有脏数据。

**分支**

- 位于顶部上方的结点，有只读权限。

## 6.1. 权限转换

权限转换必须指定预期的结果：提升权限，降低权限或保持权限。

|分组|内容|
|:--|:--|
|`Cap`|`toN(0)`，`toB(1)`，`toT(2)`|
|`Grow`|`NtoB(0)`，`NtoT(1)`，`BtoT(2)`|
|`Prune`|`TtoB(0)`，`TtoN(1)`，`BtoN(2)`|
|`Report`|`TtoT(3)`，`BtoB(4)`，`NtoN(5)`|

**`Prune`**

- 降低权限等级，注明原始权限和较低的新权限。

**`Grow`**

- 提升权限等级，注明原始权限和较低的新权限。

**`Report`**

- 保持权限不变，但会报告当前权限。

**`Cap`**

- 权限更改，不指明原始权限，只指明预期权限。
