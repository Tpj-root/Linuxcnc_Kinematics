cmake_minimum_required(VERSION 3.10)
project(MainApp)
set(CMAKE_CXX_STANDARD 17)

# Include headers from ../include
include_directories(${CMAKE_SOURCE_DIR}/../include)

# Link the static library from ../lib
link_directories(${CMAKE_SOURCE_DIR}/../lib)

# Add executable
add_executable(main main.cpp)

# Link with static library
target_link_libraries(main own_lib)
