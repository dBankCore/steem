# Installing dPay's Live Network Node With Docker
We provide instructions for installing dPay's live network node using Docker
for both Ubuntu 16.04 and Mac OSX. We do currently have instructions for
building on Windows but will be providing build instructions in our next release.

- [Installing With Ubuntu 16.04](#ubuntu-16-04)
- [Installing With MacOSX](#mac-osx)

## Ubuntu 16.04

### Install The Latest Version Of Docker
```
sudo apt-get remove docker docker-engine docker.io
sudo apt-get update
sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo apt-key fingerprint 0EBFCD88
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
sudo apt-get update
sudo apt-get install docker-ce
```

### Pure Docker Installation
There are two options when it comes to pure Docker installs of `dpayd` and
`cli_wallet`. You can simply install the latest stable release of `dpayd` and
`cli_wallet` or you can enable extra build requirements for low-memory and
launching web-based nodes for API/development purposes.

#### Install The Stable-Release / Low-Memory Node Of `dpayd`
**Suitable for:**
- seed nodes
- witness nodes
- exchanges, etc.

```
docker run \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-default \
    --restart unless-stopped dpay/dpay
```

#### Full API Node
**Suitable for:**
- dApps
- Developers
- Web Services

```
docker run \
    --env USE_WAY_TOO_MUCH_RAM=1 --env USE_FULL_WEB_NODE=1 \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-full \
    --restart unless-stopped \
    dpay/dpay
```

### Build From Source With Docker

We ship a Dockerfile.  This builds both common node type binaries.

```
git clone https://github.com/dpays/dpay
cd dpay
docker build -t dpay/dpay .
```

## Mac OSX

### Install The Latest Docker
- [Click here to download the latest DockerCE For Mac](https://download.docker.com/mac/stable/Docker.dmg)

**Follow the installation instructions via [Docker's documentation](https://docs.docker.com/docker-for-mac/install/)**

### Pure Docker Installation
There are two options when it comes to pure Docker installs of `dpayd` and
`cli_wallet`. You can simply install the latest stable release of `dpayd` and
`cli_wallet` or you can enable extra build requirements for low-memory and
launching web-based nodes for API/development purposes.

#### Install The Stable-Release / Low-Memory Node Of `dpayd`
**Suitable for:**
- seed nodes
- witness nodes
- exchanges, etc.

```
docker run \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-default \
    --restart unless-stopped dpay/dpay
```

#### Full API Node
**Suitable for:**
- dApps
- Developers
- Web Services

```
docker run \
    --env USE_WAY_TOO_MUCH_RAM=1 --env USE_FULL_WEB_NODE=1 \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-full \
    --restart unless-stopped \
    dpay/dpay
```

### Build From Source With Docker

We ship a Dockerfile.  This builds both common node type binaries.

```
git clone https://github.com/dpays/dpay
cd dpay
docker build -t dpay/dpay .
```
