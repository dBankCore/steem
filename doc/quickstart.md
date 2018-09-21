Quickstart
----------

### Get current dpayd
Use docker:
```
docker run \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-default \
    --restart unless-stopped dpay/dpay
```
#### Low memory node?
Above runs low memory node, which is suitable for:
- seed nodes
- witness nodes
- exchanges, etc.
For full api node use:

```
docker run \
    --env USE_WAY_TOO_MUCH_RAM=1 --env USE_FULL_WEB_NODE=1 \
    -d -p 6620:6620 -p 1776:1776 --name dpayd-full \
    --restart unless-stopped \
    dpay/dpay
```
### Configure for your use case
#### Full API node
You need to use `USE_WAY_TOO_MUCH_RAM=1` and `USE_FULL_WEB_NODE=1` as stated above.
You can Use `contrib/fullnode.config.ini` as a base for your `config.ini` file.
