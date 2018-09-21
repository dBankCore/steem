file(GLOB HEADERS "include/dpay/delayed_node/*.hpp")

add_library( dpay_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( dpay_delayed_node dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   dpay_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
