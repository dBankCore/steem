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
      appbase
      dpay_utilities
      dpay_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( DPAY_STATIC_BUILD )
   target_link_libraries( dpayd PRIVATE
      appbase
      dpay_utilities
      dpay_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( DPAY_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      dpayd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   dpayd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
