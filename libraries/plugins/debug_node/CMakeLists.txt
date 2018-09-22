file(GLOB HEADERS "include/dpay/plugins/debug_node/*.hpp")

add_library( dpay_debug_node
             ${HEADERS}
             debug_node_plugin.cpp
             debug_node_api.cpp
           )

target_link_libraries( dpay_debug_node dpay_app dpay_chain dpay_protocol fc )
target_include_directories( dpay_debug_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS dpay_debug_node
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
       )
INSTALL( FILES ${HEADERS} DESTINATION "include/dpay/plugins/debug_node" )
