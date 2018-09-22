file(GLOB HEADERS "include/dpay/tags/*.hpp")

add_library( dpay_tags
             tags_plugin.cpp )

target_link_libraries( dpay_tags dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_tags
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_tags

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
