cmake_minimum_required(VERSION 3.4)
project(hometec)

SET(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti ${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

find_package(Celix REQUIRED)

add_subdirectory(bundles/lightec_api)
add_subdirectory(bundles/hometec_service)

add_celix_container(hometec
    COPY
    CXX
    BUNDLES
        Celix::rsa_topology_manager
        Celix::rsa_dfi
        Celix::shell
        Celix::remote_shell
        Celix::rsa_discovery
        hometec_service
    PROPERTIES
        RSA_PORT=18888
)
