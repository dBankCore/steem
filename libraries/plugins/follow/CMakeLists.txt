file(GLOB HEADERS "include/dpay/follow/*.hpp")

add_library( dpay_follow
             follow_plugin.cpp
             follow_api.cpp
             follow_operations.cpp
             follow_evaluators.cpp
           )

target_link_libraries( dpay_follow dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_follow
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_follow

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
