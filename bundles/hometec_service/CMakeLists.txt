add_celix_bundle(hometec_service
    SOURCES
        src/hometec_service_activator
        src/turn_command
    VERSION 1.0.0
    SYMBOLIC_NAME "hometec_service"
)
target_include_directories(hometec_service PRIVATE src)
target_link_libraries(hometec_service PRIVATE Celix::shell_api lightec_api)

celix_bundle_files(hometec_service
    ../lightec_api/avro/generated/com.garani.lightec.api.LedService.avpr
    DESTINATION .
)