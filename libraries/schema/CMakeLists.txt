file(GLOB HEADERS "include/dpay/schema/*.hpp")
add_library( dpay_schema schema.cpp ${HEADERS} )
target_link_libraries( dpay_schema fc )
target_include_directories( dpay_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/dpay/schema" )
