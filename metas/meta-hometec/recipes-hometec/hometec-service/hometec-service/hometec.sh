#!/bin/sh

LOCAL_IP="$(ifconfig  | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}')"

DISCOVERY_CFG_POLL_ENDPOINTS="http://$LOCAL_IP:9999/org.apache.celix.discovery.configured" RSA_IP=$LOCAL_IP CELIX_BUNDLES_PATH=/usr/libexec/bundles /usr/libexec/hometec
