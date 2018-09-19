file(GLOB HEADERS "include/dpay/private_message/*.hpp")

add_library( dpay_private_message
             private_message_plugin.cpp
           )

target_link_libraries( dpay_private_message dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
