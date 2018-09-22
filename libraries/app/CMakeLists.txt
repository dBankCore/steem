file(GLOB HEADERS "include/dpay/app/*.hpp")

add_library( dpay_app
             database_api.cpp
             api.cpp
             application.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
           )

target_link_libraries( dpay_app dpay_chain dpay_protocol dpay_tags dpay_follow dpay_witness dpay_mf_plugins fc graphene_net graphene_utilities )
target_include_directories( dpay_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   dpay_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/dpay/app" )
