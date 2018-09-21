### Resources usage

Please make sure that you have enough resources available. Check `shared-file-size =` in your `config.ini` to reflect your needs. Set it to at least 25% more than current size.

Provided values are expected to grow significantly over time.

Blockchain data takes over **50GB** of storage space.

#### Full node
Shared memory file for full node uses something about **50GB** (depends on exact settings)

#### Exchange node
Shared memory file for exchange node users over **10GB**
(tracked history for single account)

#### Seed node
Shared memory file for seed node uses over **10GB**

#### Other use cases
Shared memory file size varies, depends on your specific configuration but it is expected to be somewhere between "seed node" and "full node" usage.
