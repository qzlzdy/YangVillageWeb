---
title: ESM文件格式
---

- [1. ESM文件格式](#1-esm文件格式)
- [2. ESM头(Ehdr)](#2-esm头ehdr)
  - [2.1. `e_ident`](#21-e_ident)
  - [2.2. `e_type`](#22-e_type)
  - [2.3. `e_ehsize`](#23-e_ehsize)
  - [2.4. `e_entry`](#24-e_entry)
  - [2.5. `e_phoff`](#25-e_phoff)
  - [2.6. `e_shoff`](#26-e_shoff)
  - [2.7. `e_phentsize`](#27-e_phentsize)
  - [2.8. `e_phnum`](#28-e_phnum)
  - [2.9. `e_shentsize`](#29-e_shentsize)
  - [2.10. `e_shnum`](#210-e_shnum)
  - [2.11. `e_shstrndx`](#211-e_shstrndx)
- [3. 程序头表(Phdr)](#3-程序头表phdr)
  - [3.1. `p_type`](#31-p_type)
  - [3.2. `p_offset`](#32-p_offset)
  - [3.3. `p_vaddr`](#33-p_vaddr)
  - [3.4. `p_paddr`](#34-p_paddr)
  - [3.5. `p_filesz`](#35-p_filesz)
  - [3.6. `p_memsz`](#36-p_memsz)
  - [3.7. `p_flags`](#37-p_flags)
  - [3.8. `p_align`](#38-p_align)
- [4. 段头表(Shdr)](#4-段头表shdr)
  - [4.1. `sh_name`](#41-sh_name)
  - [4.2. `sh_type`](#42-sh_type)
  - [4.3. `sh_flags`](#43-sh_flags)
  - [4.4. `sh_addr`](#44-sh_addr)
  - [4.5. `sh_offset`](#45-sh_offset)
  - [4.6. `sh_size`](#46-sh_size)
  - [4.7. `sh_link`](#47-sh_link)
  - [4.8. `sh_info`](#48-sh_info)
  - [4.9. `sh_addralign`](#49-sh_addralign)
  - [4.10. `sh_entsize`](#410-sh_entsize)

# 1. ESM文件格式

原型：[ELF](https://www.man7.org/linux/man-pages/man5/elf.5.html)

---

ESM文件是可执行文件，由ESM头、程序头表或段头表或两者组成。ESM头总是位于文件的零偏移量处。程序头表和段头表在文件中的偏移量在ESM头中定义。

# 2. ESM头(Ehdr)

```C++
struct EsmEhdr{
    uint8_t e_ident[4];
    uint16_t e_type;
    uint16_t e_ehsize;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};
```

## 2.1. `e_ident`

包含魔数的数组，固定由`[0x7f, 'E', 'S', 'M']`填充。

## 2.2. `e_type`

标识文件类型

|取值|文件类型|
|:--:|:--|
|`ET_NONE`|未知类型|
|`ET_REL`|可重定位文件|
|`ET_EXEC`|可执行文件|
|`ET_DYN`|动态库文件|

## 2.3. `e_ehsize`

ESM头的字节大小。

## 2.4. `e_entry`

系统将控制权转移到的虚拟地址，从而启动进程。如果文件没有相关入口点，该字段为零。

## 2.5. `e_phoff`

保存程序头表的字节偏移量。如果文件中没有程序头表，该字段为零。

## 2.6. `e_shoff`

保存段头表的字节偏移量。如果文件中没有段头表，该字段为零。

## 2.7. `e_phentsize`

保存文件程序头表中一个条目的字节大小，所有条目的大小相同。

## 2.8. `e_phnum`

包含程序头表中的条目数，`e_phentsize`和`e_phnum`的乘积就是表大小。如果文件没有程序头，该字段为零。如果程序头表中的条目数大于或等于`PN_XNUM(0xffff)`，该字段为`PN_XNUM`，程序头表中的实际条目数保存在段头表首个条目的`sh_info`字段中；否则，`sh_info`字段为零。

## 2.9. `e_shentsize`

保存文件段头表中一个条目的字节大小，所有条目的大小相同。

## 2.10. `e_shnum`

包含段头表中的条目数。`e_shentsize`和`e_shnum`的乘积就是表大小。如果文件没有段头，该字段为零。如果段头表中的条目数大于或等于`SHN_LORESERVE(0xff00)`，该字段为`SHN_LORESERVE`，段头表中的实际条目数保存在段头表首个条目的`sh_size`字段中；否则，`sh_size`字段为零。

## 2.11. `e_shstrndx`

保存与段名字符串表相关的条目的段头表索引。如果文件没有段名字符串表，该字段为`SHN_UNDEF(0)`。如果段名字符串表段的索引大于或等于`SHN_LORESERVE`，该字段为`SHN_XINDEX(0xffff)`，段名字符串表段的实际索引保存在段头表首个条目的`sh_link`字段中；否则，`sh_link`字段为零。

# 3. 程序头表(Phdr)

可执行文件或动态链接库文件的程序头表是一个结构数组，每个结构描述一个程序段或系统准备执行程序所需的其他信息。一个程序段可能含有一个或多个段。程序头只对可执行文件和动态链接库文件有意义。文件通过ESM头的`e_phentsize`和`e_phnum`字段指定程序头大小。

```C++
struct EsmPhdr{
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};
```

## 3.1. `p_type`

表示数组元素的程序段类型。

|类型|含义|
|:--:|:--|
|`PT_NULL`|数组元素未使用，其他字段未定义|
|`PT_LOAD`|数组元素指定了一个可加载段，由`p_filesz`和`p_memsz`描述。文件中的字节会被映射到内存段的起始位置。如果段的内存大小`p_memsz`大于文件大小`p_filesz`，额外的字节填入$0$。文件大小不得大于内存大小。程序头表中的可加载条目按`p_vaddr`字段升序排列|

## 3.2. `p_offset`

保存段的第一个字节相对文件开头的偏移量。

## 3.3. `p_vaddr`

保存段的第一个字节在内存中的虚拟地址。

## 3.4. `p_paddr`

在物理地址寻址的系统中，该字段保存段的物理地址。

## 3.5. `p_filesz`

保存段的文件镜像字节数。

## 3.6. `p_memsz`

保存段的内存镜像字节数。

## 3.7. `p_flags`

保存与段相关的标志位掩码：

|标志|含义|
|:--:|:--|
|`PF_X`|可执行段|
|`PF_W`|可写段|
|`PF_R`|可读段|

代码段通常有标志`PF_X`和`PF_R`；数据段通常有标志`PF_W`和`PF_R`。

## 3.8. `p_align`

保存段在内存和文件中的对齐值。可加载进程段的`p_vaddr`和`p_offset`值必须一致，且能被页面大小整除。值为零或一表示不需要对齐。否则，`p_align`应为$2$的整数次幂，`p_vaddr`等于`p_offset`，且能被`p_align`相乘。

# 4. 段头表(Shdr)

通过文件的段头表，可以找到文件的所有段。ESM头的`e_shoff`字段提供了从文件开头到段头表的字节偏移量，`e_shnum`字段保存了段头表包含的条目数。`e_shentsize`字段保存了每个条目的大小。段头表索引是指该段在数组的下标。首个条目索引和`SHN_LORESERVE`之后的索引是保留的。首个条目用于`e_phnum`、`e_shnum`和`e_shstrndx`的扩展。在其他情况下，首个条目的每个字段都设置为零。

一些特殊的索引号：

|宏|含义|
|:--:|:--|
|`SHN_UNDEF`|表示未定义、缺失、不相关或无意义的段引用|
|`SHN_LORESERVE`|制定保留索引范围的下限|

```C++
struct EsmShdr{
    uint32_t sh_name;
    uint32_t sh_type;
    uint32_t sh_flags;
    uint32_t sh_addr;
    uint32_t sh_offset;
    uint32_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint32_t sh_addralign;
    uint32_t sh_entsize;
};
```

## 4.1. `sh_name`

用于制定段的名称。其值是段头字符串表段的索引，给出了空终止字符串的位置。

## 4.2. `sh_type`

段的内容和语义标签。

|标签|含义|
|:--:|:--|
|`SHT_NULL`|表示段头未使用，没有相关的段。段头的其他字段未定义|
|`SHT_PROGBITS`|保存由程序定义的信息，其格式和含义完全由程序决定|
|`SHT_STRTAB`|包含一个字符串表，一个对象文件可能有多个字符串表段|

## 4.3. `sh_flags`

描述段各种属性的标志位。如果在该字段中设置了标志位，则该段属性为开启，否则为关闭或不适用。未定义的属性设置为零。

|标志|含义|
|:--:|:--|
|`SHF_WRITE`|该段包含在进程执行过程中应可写入的数据|
|`SHF_ALLOC`|该段在进程运行期间占用内存|
|`SHF_EXECINSTR`|该段包含可执行的机器指令|

## 4.4. `sh_addr`

如果该段出现在进程的内存镜像中，该字段包含该段第一个字节所在的地址。否则该字段为零。

## 4.5. `sh_offset`

表示从文件开头到该段第一个字节的字节偏移量。

## 4.6. `sh_size`

段的字节大小。

## 4.7. `sh_link`

包含一个段头表索引链接，含义取决于段类型。

## 4.8. `sh_info`

包含额外信息，含义取决于段类型。

## 4.9. `sh_addralign`

某些段有地址对齐限制。`sh_addr`的值必须与零对齐，且能被`sh_addralign`整除。只允许2的整数次幂。值0或1表示该段没有对齐限制。

## 4.10. `sh_entsize`

某些段保存有固定大小的条目表，如符号表。对于这些段，该字段给出每个条目的字节大小。如果段没有固定大小的条目表，该字段为零。
