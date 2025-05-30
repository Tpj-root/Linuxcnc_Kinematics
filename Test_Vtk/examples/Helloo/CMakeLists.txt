cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VTKExamples)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersSources
  IOInfovis
  InfovisLayout
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  RenderingAnnotation
  InteractionWidgets
  ViewsCore
  ViewsInfovis

)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Unable to find the VTK build folder.")
endif()

# Prevent "command line too long" on Windows
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

# CylinderExample
add_executable(CylinderExample MACOSX_BUNDLE CylinderExample.cxx)
target_link_libraries(CylinderExample PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(TARGETS CylinderExample MODULES ${VTK_LIBRARIES})

# PointViewer
add_executable(PointViewer MACOSX_BUNDLE PointViewer.cxx)
target_link_libraries(PointViewer PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(TARGETS PointViewer MODULES ${VTK_LIBRARIES})

# XGMLReader.cxx
add_executable(XGMLReader MACOSX_BUNDLE XGMLReader.cxx)
target_link_libraries(XGMLReader PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(TARGETS XGMLReader MODULES ${VTK_LIBRARIES})