# Hometec

Projeto experimental do uso do RSA Celix.
Dividido em dois projetos o experimento Hometec e Lightec, ambos usam o Projeto Lightec API como interface do Serviço.

## Obter o Lightec API

`git submodule add https://github.com/sjgarani/lightec_api.git bundles/lightec_api`


## Executar Hometec

`mkdir build`

`cd build`

`cmake ..`

`make`

`cd deploy\hometec`

`DISCOVERY_CFG_POLL_ENDPOINTS=http://[IP of Lightec Node]:9999/org.apache.celix.discovery.configured ./hometec`


### Entrar no CLI do Hometec

`telnet localhost 6666`

## Executar Hometec in Docker

`cd docker`

`docker build -t celix/base .`

`docker-compose up`


### Entrar no CLI do Hometec

`docker run --network=docker_vpcbr -it celix/base:latest telnet 10.5.0.3 6666`


## Comando Hometec

> turnOn # Configurar 255 no Estado do Led

> turnOff # Configurar 0 no Estado do Led


## Links

Github Celix: https://github.com/apache/celix

Github Lightec: https://github.com/sjgarani/lightec

Github Lightec API: https://github.com/sjgarani/lightec_api
