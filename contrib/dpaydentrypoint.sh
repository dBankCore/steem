#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start dpayd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/dpayd
  cp /usr/local/bin/dpays-sv-run.sh /etc/service/dpayd/run
  chmod +x /etc/service/dpayd/run
  runsv /etc/service/dpayd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasdpayd.sh
fi
