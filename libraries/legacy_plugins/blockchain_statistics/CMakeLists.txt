file(GLOB HEADERS "include/dpay/blockchain_statistics/*.hpp")

add_library( dpay_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( dpay_blockchain_statistics dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)