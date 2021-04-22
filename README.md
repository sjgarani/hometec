# Hometec

## Executar Hometec

`mkdir build`

`cd build`

`cmake ..`

`make`

`cd deploy\hometec`

`DISCOVERY_CFG_POLL_ENDPOINTS=http://[IP of Lightec Node]:9999/org.apache.celix.discovery.configured ./hometec`


## Executar Hometec in Docker


git submodule add https://github.com/sjgarani/lightec_api.git bundles/lightec_api

docker build -t celix/base .
docker-compose up

docker run --network=docker_vpcbr -it celix/base:latest telnet 10.5.0.3 6666
