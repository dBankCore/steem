file(GLOB HEADERS "include/dpay/plugins/block_info/*.hpp")

add_library( dpay_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( dpay_block_info dpay_app dpay_chain dpay_protocol fc )
target_include_directories( dpay_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
