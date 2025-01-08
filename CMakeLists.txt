cmake_minimum_required(VERSION 3.22.1) # my version
project(by VERSION 0.0.0)

include(GNUInstallDirs)

add_library(by SHARED
src/io.c
# out  
  src/out/global.c
  src/out/program_memory.c
# in
  src/in/global.c
  src/in/parser.c
)
add_library(by::by ALIAS by)

target_link_libraries(by PRIVATE)

target_include_directories(
  by
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS by
  EXPORT byTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Include the CMakePackageConfigHelpers module
include(CMakePackageConfigHelpers)

# Set some properties for your library target
set_property(TARGET by PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET by PROPERTY SOVERSION 1)
set_property(TARGET by PROPERTY
  mNTERFACE_by_MAJOR_VERSION 1)
set_property(TARGET by APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING by_MAJOR_VERSION
)

# Generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/byConfigVersion.cmake"
  VERSION "${PROJECT_VERSION}"
  COMPATIBILITY AnyNewerVersion
)

# Create the config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/byConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/byConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/by
)

# Install the config and version files
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/byConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/byConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/by
)

# Export the targets for the build tree
export(EXPORT byTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/byTargets.cmake"
  NAMESPACE by::
)

# Install the export set for the install tree
install(EXPORT byTargets
  FILE byTargets.cmake
  NAMESPACE by::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/by
)




