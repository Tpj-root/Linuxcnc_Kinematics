cmake_minimum_required(VERSION 3.10)
project(VTKExample)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(VTKExample test_VTK.cpp)
target_link_libraries(VTKExample PRIVATE ${VTK_LIBRARIES})
