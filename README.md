# 1. YangVillageWeb

羊村网站源代码。

- [1. YangVillageWeb](#1-yangvillageweb)
- [2. Prerequisites](#2-prerequisites)
  - [2.1. Install packages](#21-install-packages)
  - [2.2. Clone Repository](#22-clone-repository)
  - [2.3. Copy resources](#23-copy-resources)
  - [2.4. Install TinyMCE](#24-install-tinymce)
- [3. Build](#3-build)
- [4. Deploy](#4-deploy)
  - [4.1. Create databse](#41-create-databse)
  - [4.2. Config NGINX](#42-config-nginx)
  - [4.3. Run](#43-run)

# 2. Prerequisites

## 2.1. Install packages

```bash
sudo pacman -S ccache cmake fcgi git nginx sqlite spawn-fcgi wt
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

# 4. Deploy

## 4.1. Create databse

```bash
sqlite yangvillage.db -init initdb.sql
```

## 4.2. Config NGINX

```bash
cp wt_fcgi.conf     /etc/nginx/wt_fcgi.conf
cp wt_ssl.conf      /etc/nginx/wt_ssl.conf
cp wt_static.conf   /etc/nginx/wt_static.conf
cp yangvillage.conf /etc/nginx/sites-available.conf
ln -s /etc/nginx/sites-available/yangvillage.conf /etc/nginx/sites-enabled/yangvillage.conf
```

> add `include /etc/nginx/sites-enabled/*;` in http block in nginx.conf

## 4.3. Run

```bash
WT_APP_ROOT=/path/to/repo spawn-fcgi -n build/bin/homepage.wt -a 0.0.0.0 -p 9001
WT_APP_ROOT=/path/to/repo spawn-fcgi -n build/bin/bookmark.wt -a 0.0.0.0 -p 9002
WT_APP_ROOT=/path/to/repo spawn-fcgi -n build/bin/broadcast.wt -a 0.0.0.0 -p 9003
WT_APP_ROOT=/path/to/repo spawn-fcgi -n build/bin/portfolio.wt -a 0.0.0.0 -p 9004
nginx -s reload
```
