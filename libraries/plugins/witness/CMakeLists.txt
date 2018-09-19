file(GLOB HEADERS "include/dpay/witness/*.hpp")

add_library( dpay_witness
             witness_plugin.cpp
             witness_evaluators.cpp
             witness_operations.cpp
           )

target_link_libraries( dpay_witness dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
