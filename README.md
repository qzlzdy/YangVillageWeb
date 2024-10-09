# 1. YangVillageWeb

[羊村网站](https://yangvillage.top)源代码。

- [1. YangVillageWeb](#1-yangvillageweb)
- [2. Prerequisites](#2-prerequisites)
  - [2.1. Install packages](#21-install-packages)
- [3. Build](#3-build)
- [4. Deploy](#4-deploy)
  - [4.1. Create Directories](#41-create-directories)
  - [4.2. Copy Files](#42-copy-files)
  - [4.3. Create databse](#43-create-databse)
  - [4.4. Config Nginx](#44-config-nginx)
  - [4.5. Run](#45-run)

# 2. Prerequisites

## 2.1. Install packages

```bash
sudo pacman -S ccache cmake fcgi git nginx ninja sqlite spawn-fcgi wt
```

# 3. Build

```bash
git clone https://github.com/qzlzdy/YangVillageWeb.git
cd YangVillageWeb

cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

# 4. Deploy

## 4.1. Create Directories

```bash
mkdir -p /usr/share/yangvillage/{bin,static/resouces{,/tinymce}}
mkdir -p /etc/yangvillage
mkdir -p /var/lib/yangvillage
mkdir -p /run/yangvillage
ln -s /usr/share/yangvillage/bin /var/lib/yangvillage/bin
ln -s /usr/share/yangvillage/static /var/lib/yangvillage/static
ln -s /etc/yangvillage/wt_config.xml /var/lib/yangvillage/wt_config.xml
```

## 4.2. Copy Files

```bash
# copy resources
cp -r /usr/share/Wt/resources/* /usr/share/yangvillage/static/resources/

# install TinyMCE
aria2c https://download.tiny.cloud/tinymce/community/tinymce_4.9.11.zip
unzip tinymce_4.9.11.zip
cp -r tinymce/js/tinymce/* /usr/share/yangvillage/static/resources/tinymce/

# copy static files
cp -r static/* /usr/share/yangvillage/static/
cp template.xml /usr/share/yangvillage/

# copy binary
cp build/bin/*.wt /usr/share/yangvillage/bin/

# copy wt_config.xml
cp wt_config.xml /etc/yangvillage/
```

## 4.3. Create databse

```bash
sqlite3 /var/lib/yangvillage/yangvillage.db -init initdb.sql
```

## 4.4. Config Nginx

```bash
cp nginx-config/wt_*.conf /etc/nginx/
cp nginx-config/yangvillage.conf /etc/nginx/sites-available/
ln -s /etc/nginx/sites-available/yangvillage.conf /etc/nginx/sites-enabled/yangvillage.conf
nginx -s reload
```

> add `include /etc/nginx/sites-enabled/*;` in http block in nginx.conf

## 4.5. Run

```bash
export WT_APP_ROOT=/var/lib/yangvillage
nohup spawn-fcgi -n /var/lib/yangvillage/bin/bookmark.wt -a 0.0.0.0 -p 9002 >/dev/null &
nohup spawn-fcgi -n /var/lib/yangvillage/bin/toolkits.wt -a 0.0.0.0 -p 9003 >/dev/null &
nohup spawn-fcgi -n /var/lib/yangvillage/bin/portfolio.wt -a 0.0.0.0 -p 9004 >/dev/null &
```
