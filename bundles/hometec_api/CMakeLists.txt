add_library(hometec_api INTERFACE)
target_include_directories(hometec_api INTERFACE include)
set_target_properties(hometec_api PROPERTIES
    "INTERFACE_DESCRIPTOR"
    "${CMAKE_CURRENT_LIST_DIR}/com.garani.hometec.api.LedService.avpr")
