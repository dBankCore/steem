add_executable( dpayd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling dpayd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( DPAY_STATIC_BUILD )
   target_link_libraries( dpayd PRIVATE
      "-static-libstdc++ -static-libgcc"
      dpay_plugins
      dpay_mf_plugins
      dpay_app
      dpay_witness
      dpay_account_history
      dpay_chain
      dpay_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( DPAY_STATIC_BUILD )
   target_link_libraries( dpayd PRIVATE
      dpay_plugins
      dpay_mf_plugins
      dpay_app
      dpay_witness
      dpay_account_history
      dpay_chain
      dpay_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( DPAY_STATIC_BUILD )

install( TARGETS
   dpayd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
