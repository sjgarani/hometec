#${WS}/hometec/CMakeLists.txt

cmake_minimum_required(VERSION 3.4)
project(hometec CXX)

SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

# set(CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} "/usr/local/share/celix/cmake/modules")
find_package(Celix REQUIRED)

add_subdirectory(bundles/hometec_service)

add_celix_container(hometec
    CXX
    BUNDLES
        Celix::shell
        Celix::shell_tui
            hometec_service
)