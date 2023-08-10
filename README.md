# 1. YangVillageWeb

羊村网站源代码。

- [1. YangVillageWeb](#1-yangvillageweb)
- [2. Prerequisites](#2-prerequisites)
  - [2.1. Install packages](#21-install-packages)
  - [2.2. Clone Repository](#22-clone-repository)
  - [2.3. Copy resources](#23-copy-resources)
  - [2.4. Install TinyMCE](#24-install-tinymce)
- [3. Build](#3-build)
- [4. Start server](#4-start-server)
  - [4.1. Initialization](#41-initialization)
  - [4.2. Run](#42-run)

# 2. Prerequisites

## 2.1. Install packages

```bash
pacman -S cmake ccache sqlite wt git
```

## 2.2. Clone Repository

```bash
git clone https://github.com/qzlzdy/YangVillageWeb.git
cd YangVillageWeb
```

## 2.3. Copy resources

```bash
mkdir resources
cp -r /usr/share/Wt/resources/* resources/
```

## 2.4. Install TinyMCE

```bash
aria2c https://download.tiny.cloud/tinymce/community/tinymce_4.9.11.zip
unzip tinymce_4.9.11.zip
mkdir resources/tinymce
cp -r tinymce/js/tinymce/* resources/tinymce/
```

# 3. Build

```bash
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

# 4. Start server

## 4.1. Initialization

```bash
# Create database
sqlite yangvillage.db -init initdb.sql

# Create Diffie-Hellman parameters file
openssl dhparam -check -text -out dh2048.pem 2048
```

## 4.2. Run

```bash
yangvillage.wt \
    --docroot ".;/resources,/images" \
    -c wt_config.xml \
    --http-address 0.0.0.0 \
    --https-addres 0.0.0.0 \
    --ssl-certificate=server.pem \
    --ssl-private-key=server.key \
    --ssl-tmp-dh=dh2048.pem \
    --ssl-cipherlist='ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-DSS-AES128-GCM-SHA256:kEDH+AESGCM:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-DSS-AES128-SHA256:DHE-RSA-AES256-SHA256:DHE-DSS-AES256-SHA:DHE-RSA-AES256-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:AES:CAMELLIA:DES-CBC3-SHA:!aNULL:!eNULL:!EXPORT:!DES:!RC4:!MD5:!PSK:!aECDH:!EDH-DSS-DES-CBC3-SHA:!EDH-RSA-DES-CBC3-SHA:!KRB5-DES-CBC3-SHA'
```
