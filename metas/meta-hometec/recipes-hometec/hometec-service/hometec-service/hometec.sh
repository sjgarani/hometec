#!/bin/sh

LOCAL_IP=$(ip addr show eth0 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)

if [ -z "$LOCAL_IP" ]
then
    LOCAL_IP="127.0.0.1"
fi

DISCOVERY_CFG_POLL_ENDPOINTS="http://$LOCAL_IP:9999/org.apache.celix.discovery.configured" RSA_IP=$LOCAL_IP CELIX_BUNDLES_PATH=/usr/libexec/bundles /usr/libexec/hometec
