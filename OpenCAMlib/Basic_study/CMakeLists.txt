cmake_minimum_required(VERSION 3.10)
project(OwnLib)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB LIB_SOURCES src/*.cpp)

add_library(own_lib STATIC ${LIB_SOURCES})
