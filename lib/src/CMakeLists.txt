

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( smolpack.cc )
ot_add_source_file ( SmolyakExperiment.cxx )

ot_install_header_file ( SmolyakExperiment.hxx )

include_directories (${INTERNAL_INCLUDE_DIRS})

add_library (otsmolyak ${SOURCEFILES})
set_target_properties (otsmolyak PROPERTIES POSITION_INDEPENDENT_CODE ON)
if (BUILD_SHARED_LIBS)
  set_target_properties (otsmolyak PROPERTIES COMPILE_DEFINITIONS "OTSMOLYAK_DLL_EXPORTS")
endif ()

if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( otsmolyak PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( otsmolyak PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (otsmolyak ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS otsmolyak FILE ${PROJECT_BINARY_DIR}/OtSmolyak-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT OtSmolyak-Targets
        DESTINATION "${OTSMOLYAK_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS otsmolyak
        EXPORT  OtSmolyak-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${OTSMOLYAK_LIBRARY_PATH}
        ARCHIVE DESTINATION ${OTSMOLYAK_LIBRARY_PATH}
)

