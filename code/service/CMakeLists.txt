include(CTest)
enable_testing()

find_package(Boost)

add_library(statemachine STATIC src/statemachine.cpp include/statemachine.hpp)
target_include_directories(statemachine PUBLIC include)

add_executable(hometec src/main.cpp)
target_link_libraries(hometec PUBLIC statemachine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
