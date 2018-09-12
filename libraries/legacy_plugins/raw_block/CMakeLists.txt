file(GLOB HEADERS "include/dpay/plugins/raw_block/*.hpp")

add_library( dpay_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( dpay_raw_block dpay_app dpay_chain dpay_protocol fc )
target_include_directories( dpay_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
