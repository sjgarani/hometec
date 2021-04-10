add_celix_bundle(hometec_service
    SOURCES
        src/led_service_impl
        src/led_service_activator
    SYMBOLIC_NAME "hometec_service"
    VERSION 1.0.0
)

target_include_directories(hometec_service PRIVATE src)
target_link_libraries(hometec_service PRIVATE Celix::log_service_api Celix::log_helper Celix::rsa_spi hometec_api)

get_target_property(DESCR hometec_api INTERFACE_DESCRIPTOR)
celix_bundle_files(hometec_service ${DESCR} DESTINATION .)
