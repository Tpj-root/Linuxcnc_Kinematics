cmake_minimum_required(VERSION 3.10)
project(MainApp)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/build)

add_executable(main main.cpp)
target_link_libraries(main own_lib)
