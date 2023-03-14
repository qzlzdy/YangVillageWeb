# 1. YangVillageWeb

羊村网站源代码。

- [1. YangVillageWeb](#1-yangvillageweb)
- [2. Prerequisites](#2-prerequisites)
  - [2.1. Install packages](#21-install-packages)
  - [2.2. Copy resources](#22-copy-resources)
  - [2.3. Install TinyMCE](#23-install-tinymce)
  - [2.4. Prepare certificate](#24-prepare-certificate)
- [3. Build](#3-build)
- [4. Start server](#4-start-server)

# 2. Prerequisites

## 2.1. Install packages

```bash
pacman -S cmake wt
```

## 2.2. Copy resources

```bash
mkdir resources
cp -r /usr/share/Wt/resources/* resources/
```

## 2.3. Install TinyMCE

```bash
aria2c https://download.tiny.cloud/tinymce/community/tinymce_4.9.11.zip
unzip tinymce_4.9.11.zip
mkdir resources/tinymce
cp -r tinymce/js/tinymce/* resources/tinymce/
```

## 2.4. Prepare certificate

```bash
openssl dhparam -check -text -out dh2048.pem 2048
openssl genrsa -des3 -out server.key 2048
openssl req -new -key server.key -out server.csr
cp server.key server.key.org
openssl rsa -in server.key.org -out server.key
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt
cat server.crt server.key server.crt > server.pem
```

# 3. Build

```bash
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

# 4. Start server

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
