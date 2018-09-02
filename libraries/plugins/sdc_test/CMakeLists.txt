file(GLOB HEADERS "include/dpay/plugins/sdc_test/*.hpp")

add_library( sdc_test_plugin
             sdc_test_plugin.cpp
           )

target_link_libraries( sdc_test_plugin chain_plugin dpay_chain dpay_protocol )
target_include_directories( sdc_test_plugin
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   sdc_test_plugin

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
