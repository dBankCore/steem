# Introducing dPay (beta)

dPay is a Delegated Proof of Stake blockchain that uses a "Proof of Brain" social consensus algorithm for token allocation.

  - Currency symbol BEX.
  - 10% APR inflation narrowing to 1% APR over 20 years.
  - 75% of inflation to "Proof of Brain" social consensus algorithm.
  - 15% of inflation to stake holders.
  - 10% of inflation to block producers.


# Chain Details
- **Blockchain ID** - 38f14b346eb697ba04ae0f5adcfaa0a437ed3711197704aa256a14cb9b4a8f26
- **Init Miner Public Key** - DWB6FSKRxQMaXSa6zXsETV8ZVexCdyau3pNYPERVeKCdSoiZPt4yg
- **Peer-To-Peer Port** - 6620
- **RPC/WS Port** - 1776

# Public API Nodes (RPC and WS Enabled)
- **[https://greatchain.dpays.io](https://greatchain.dpays.io)**
- **[https://jefferson.dpays.io](https://jefferson.dpays.io)**
- **[https://jackson.dpays.io](https://jackson.dpays.io)**
- **[https://maga.dpays.io](https://maga.dpays.io)**
- **[https://api.dpays.io](https://api.dpays.io)**
- **[https://node.dpayid.io](https://node.dpayid.io)**
- **[https://node.dsite.io](https://node.dsite.io)**
- **[https://node.dpeeps.io](https://node.dpeeps.io)**
- **[https://node.dgive.io](https://node.dgive.io)**
- **[https://node.dwiki.io](https://node.dwiki.io)**
- **[https://node.dpix.io](https://node.dpix.io)**
- **[https://node.dsocial.io](https://node.dsocial.io)**
- **[https://node.dvideo.io](https://node.dvideo.io)**
- **[https://dpaystan.link](https://dpaystan.link)**
- **[https://onceuponatime.link](https://onceuponatime.link)**
- **[https://dpaylana.link](https://dpaylana.link)**
- **[https://dpaynmh.network](https://dpaynmh.network)**

# dPay Governance
- [@onceuponatime](https://dsite.io/@onceupatime)
- [@jared](https://dsite.io/@jared)
- [@stan](https://dsite.io/@stan)
- [@nomoreheroes](https://dsite.io/@nomoreheroes)
- [@nickeles](https://dsite.io/@nickeles)
- [@michaelx](https://dsite.io/@michaelx)
- [@m](https://dsite.io/@m)
- [@stormkrow](https://dsite.io/@stormkrow)
- [@freedomfirst](https://dsite.io/@freedomfirst)
- [@lana](https://dsite.io/@lana)
- [@tablecafe](https://dsite.io/@tablecafe)
- [@bossdan](https://dsite.io/@bossdan)
- [@bigg](https://dsite.io/@bigg)
- [@whi](https://dsite.io/@whi)
- [@chiraag](https://dsite.io/@chiraag)
- [@morrison](https://dsite.io/@morrison)
- [@quin](https://dsite.io/@quin)
- [@lune](https://dsite.io/@lune)
- [@cryptokong](https://dsite.io/@cryptokong)
- [@cointroller](https://dsite.io/@cointroller)
- [@kusknee](https://dsite.io/@kusknee)

# dApps Powered By dPay's Network
- [dSite](https://dsite.io) // Can also access over dweb://site.d
- [dPeeps](https://dpeeps.io) // Can also access over dweb://peeps.d
- [dSocial](https://dsocial.io) // Can also access over dweb://social.d
- [dPix](https://dpix.io) // Can also access over dweb://pix.d
- [dWiki](https://dwiki.io) // Can also access over dweb://wiki.d
- [dGive](https://dgive.io) // Can also access over dweb://give.d
- [dBuy](https://dbuy.io) // Can also access over dweb://buy.d
- [dSeek](https://dseek.io) // Can also access over dweb://seek.d
- [dTunes](https://dtunes.io) // Can also access over dweb://tunes.d
- [dPayID](https://dpayid.io) // Can also access over dweb://pay.d
- [dVideo](https://dvideo.io) // Can also access over dweb://video.d
- [dVinci](https://dvinci.io) // Can also access over dweb://vinci.d
- [dMemo](https://dmemo.io) // Can also access over dweb://memo.d

# No Support & No Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

# Quickstart

Just want to get up and running quickly? We have pre-built docker images for your convenience. More details are in our [quickstart guide](https://github.com/dpays/dpays/blob/master/doc/exchangequickstart.md).

# Building

We strongly recommend using one of our pre-built Docker images or using Docker to build dPay. Both of these processes are described in the [quickstart guide](https://github.com/dpays/dpays/blob/master/doc/exchangequickstart.md).

If you would still like to build from source, we do have [build instructions](https://github.com/dpays/dpays/blob/master/doc/building.md) for Linux (Ubuntu LTS) and macOS.

## Dockerized p2p Node

To run a p2p node (ca. 2GB of memory is required at the moment):

    docker run \
        -d -p 6620:6620 -p 1776:1776 --name dpayd-default \
        dpays/dpay

    docker logs -f dpayd-default  # follow along

## Dockerized Full Node

To run a node with *all* the data (e.g. for supporting a content website)
that uses ca. 14GB of memory and growing:

    docker run \
        --env USE_WAY_TOO_MUCH_RAM=1 --env USE_FULL_WEB_NODE=1 \
        -d -p 6620:6620 -p 1776:1776 --name dpayd-full \
        dpays/dpay

    docker logs -f dpayd-full

# Environment variables

There are quite a few environment variables that can be set to run **dpayd** in different ways:

* `USE_WAY_TOO_MUCH_RAM` - if set to true, **dpayd** starts a 'full node'
* `USE_FULL_WEB_NODE` - if set to true, a default config file will be used that enables a full set of API's and associated plugins.
* `USE_NGINX_FRONTEND` - if set to true, this will enable an NGINX reverse proxy in front of **dpayd** that proxies websocket requests to **dpayd**. This will also enable a custom healthcheck at the path '/health' that lists how many seconds away from current blockchain time your node is. It will return a '200' if it's less than 60 seconds away from synced.
* `USE_MULTICORE_READONLY` - if set to true, this will enable **dpayd** in multiple reader mode to take advantage of multiple cores (if available). Read requests are handled by the read-only nodes, and write requests are forwarded back to the single 'writer' node automatically. NGINX load balances all requests to the reader nodes, 4 per available core. This setting is still considered experimental and may have trouble with some API calls until further development is completed.
* `HOME` - set this to the path where you want **dpayd** to store it's data files (block log, shared memory, config file, etc). By default `/var/lib/**dpayd**` is used and exists inside the docker container. If you want to use a different mountpoint (like a ramdisk, or a different drive) then you may want to set this variable to map the volume to your docker container.

# PaaS mode

**dpayd** now supports a PaaS mode (platform as a service) that currently works with Amazon's Elastic Beanstalk service. It can be launched using the following environment variables:

* `USE_PAAS` - if set to true, **dpayd** will launch in a format that works with AWS EB. Containers will exit upon failure so that they can be relaunched automatically by ECS. This mode assumes `USE_WAY_TOO_MUCH_RAM` and `USE_FULL_WEB_NODE`, they do not need to be also set.
* `S3_BUCKET` - set this to the name of the S3 bucket where you will store shared memory files for **dpayd** in Amazon S3. They will be stored compressed in bz2 format with the file name `blockchain-$VERSION-latest.tar.bz2`, where $VERSION is the release number followed by the git short commit hash stored in each docker image at `/etc/**dpayd**version`.
* `SYNC_TO_S3` - if set to true, the node will function to only generate shared memory files and upload them to the specified S3 bucket. This makes fast deployments and autoscaling for **dpayd** possible.

# Config File

Run `**dpayd**` once to generate a data directory and config file. The default location is `witness_node_data_dir`. Kill `**dpayd**`. It won't do anything without seed nodes. If you want to modify the config to your liking, we have two example configs used in the docker images. ( [consensus node](contrib/config-for-docker.ini), [full node](contrib/fullnode.config.ini) ) All options will be present in the default config file and there may be more options needing to be changed from the docker configs (some of the options actually used in images are configured via command line).

# Seed Nodes

A list of some seed nodes to get you started can be found in
[doc/seednodes.txt](doc/seednodes.txt).

This same file is baked into the docker images and can be overridden by
setting `DPAYD_SEED_NODES` in the container environment at `docker run`
time to a whitespace delimited list of seed nodes (with port).

# CLI Wallet

We provide a basic cli wallet for interfacing with `**dpayd**`. The wallet is self documented via command line help. The node you connect to via the cli wallet needs to be running the `account_by_key_api`, `condenser_api`, and needs to be configured to accept websocket connections via `webserver-ws-endpoint`.

# Building

See [doc/building.md](doc/building.md) for detailed build instructions, including
compile-time options, and specific commands for Linux (Ubuntu LTS) or macOS.

# Testing

See [doc/testing.md](doc/testing.md) for test build targets and info
on how to use lcov to check code test coverage.

# System Requirements

For a full web node, you need at least 110GB of disk space available. ****dpayd**** uses a memory mapped file which currently holds 56GB of data and by default is set to use up to 80GB. The block log of the blockchain itself is a little over 27GB. It's highly recommended to run **dpayd** on a fast disk such as an SSD or by placing the shared memory files in a ramdisk and using the `--shared-file-dir=/path` command line option to specify where. At least 16GB of memory is required for a full web node. Seed nodes (p2p mode) can run with as little as 4GB of memory with a 24 GB state file. Any CPU with decent single core performance should be sufficient. **dpayd** is constantly growing. As of August 2017, these numbers were accurate, but you may find you need more disk space to run a full node. We are also constantly working on optimizing dPay's use of disk space.

On Linux use the following Virtual Memory configuration for the initial sync and subsequent replays. It is not needed for normal operation.

```
echo    75 | sudo tee /proc/sys/vm/dirty_background_ratio
echo  1000 | sudo tee /proc/sys/vm/dirty_expire_centisecs
echo    80 | sudo tee /proc/sys/vm/dirty_ratio
echo 30000 | sudo tee /proc/sys/vm/dirty_writeback_centisecs
```
