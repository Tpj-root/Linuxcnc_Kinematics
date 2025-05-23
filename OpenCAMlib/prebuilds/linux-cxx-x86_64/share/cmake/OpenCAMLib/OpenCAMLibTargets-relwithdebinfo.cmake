#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OpenCAMLib::ocl" for configuration "RelWithDebInfo"
set_property(TARGET OpenCAMLib::ocl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(OpenCAMLib::ocl PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/opencamlib/libocl.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libocl.so"
  )

list(APPEND _cmake_import_check_targets OpenCAMLib::ocl )
list(APPEND _cmake_import_check_files_for_OpenCAMLib::ocl "${_IMPORT_PREFIX}/lib/opencamlib/libocl.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
