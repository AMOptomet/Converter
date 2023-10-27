# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.6)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.21)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget TKService TKV3d TKOpenGl TKOpenGles TKMeshVS TKIVtk TKD3DHost)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target TKService
add_library(TKService SHARED IMPORTED)

set_target_properties(TKService PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKernel;TKMath;user32.lib;advapi32.lib;C:/occt-3rdparty/Windows-64-VC141/openvr-1.14.15-64/lib/win64/openvr_api.lib;advapi32.lib;user32.lib;C:/occt-3rdparty/Windows-64-VC141/freeimage-3.17.0-vc14-64/lib/FreeImage.lib;C:/occt-3rdparty/Windows-64-VC141/freetype-2.5.5-vc14-64/lib/freetype.lib;C:/occt-3rdparty/Windows-64-VC141/ffmpeg-3.3.4-64/lib/avcodec.lib;C:/occt-3rdparty/Windows-64-VC141/ffmpeg-3.3.4-64/lib/avformat.lib;C:/occt-3rdparty/Windows-64-VC141/ffmpeg-3.3.4-64/lib/swscale.lib;C:/occt-3rdparty/Windows-64-VC141/ffmpeg-3.3.4-64/lib/avutil.lib;winmm.lib"
)

# Create imported target TKV3d
add_library(TKV3d SHARED IMPORTED)

set_target_properties(TKV3d PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKBRep;TKMath;TKernel;TKService;TKShHealing;TKTopAlgo;TKG2d;TKG3d;TKGeomBase;TKMesh;TKGeomAlgo;TKHLR;user32.lib;gdi32.lib;opengl32.lib;C:/occt-3rdparty/Windows-64-VC141/freetype-2.5.5-vc14-64/lib/freetype.lib;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbb12.lib;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbbmalloc.lib"
)

# Create imported target TKOpenGl
add_library(TKOpenGl SHARED IMPORTED)

set_target_properties(TKOpenGl PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKernel;TKService;TKMath;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbb12.lib;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbbmalloc.lib;opengl32.lib;user32.lib;gdi32.lib"
)

# Create imported target TKOpenGles
add_library(TKOpenGles SHARED IMPORTED)

set_target_properties(TKOpenGles PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKernel;TKService;TKMath;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbb12.lib;C:/occt-3rdparty/Windows-64-VC141/tbb2021.5-install-vc140-x64/lib/tbbmalloc.lib;C:/occt-3rdparty/Windows-64-VC141/freetype-2.5.5-vc14-64/lib/freetype.lib;C:/occt-3rdparty/Windows-64-VC141/angle-gles2-2.1.0-46ad513f4e5b-vc14-64/lib/libEGL.lib;C:/occt-3rdparty/Windows-64-VC141/angle-gles2-2.1.0-46ad513f4e5b-vc14-64/lib/libEGL.lib;C:/occt-3rdparty/Windows-64-VC141/angle-gles2-2.1.0-46ad513f4e5b-vc14-64/lib/libGLESv2.lib;C:/occt-3rdparty/Windows-64-VC141/angle-gles2-2.1.0-46ad513f4e5b-vc14-64/lib/libGLESv2.lib;user32.lib;gdi32.lib"
)

# Create imported target TKMeshVS
add_library(TKMeshVS SHARED IMPORTED)

set_target_properties(TKMeshVS PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKV3d;TKMath;TKService;TKernel;TKG3d;TKG2d"
)

# Create imported target TKIVtk
add_library(TKIVtk SHARED IMPORTED)

set_target_properties(TKIVtk PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKernel;TKBRep;TKG2d;TKG3d;TKGeomAlgo;TKGeomBase;TKMath;TKMesh;TKService;TKTopAlgo;TKV3d;vtkCommonCore;vtkRenderingCore;vtkRenderingOpenGL;vtkRenderingFreeType;vtkRenderingFreeTypeOpenGL;vtkFiltersGeneral;vtkInteractionStyle"
)

# Create imported target TKD3DHost
add_library(TKD3DHost SHARED IMPORTED)

set_target_properties(TKD3DHost PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/inc"
  INTERFACE_LINK_LIBRARIES "TKernel;TKService;TKMath;TKV3d;TKOpenGl;opengl32.lib;user32.lib;gdi32.lib;D3D9.lib"
)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/OpenCASCADEVisualizationTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# Make sure the targets which have been exported in some other
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "TKernel" "TKMath" "TKBRep" "TKShHealing" "TKTopAlgo" "TKG2d" "TKG3d" "TKGeomBase" "TKMesh" "TKGeomAlgo" "TKHLR" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
