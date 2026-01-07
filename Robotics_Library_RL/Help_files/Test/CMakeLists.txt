cmake_minimum_required(VERSION 2.8.11)
project(myMdlDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Paths
set(RL_SRC_DIR "/home/where/Desktop/BUILD_FILES/rl/src/")
set(RL_BUILD_DIR "/home/where/Desktop/BUILD_FILES/rl/build/")
set(RL_LIBRARY_DIR "${RL_BUILD_DIR}/lib")

include_directories(
    /home/where/Desktop/BUILD_FILES/rl/src/
    /home/where/Desktop/BUILD_FILES/rl/build/include   # <-- add this
    /usr/include/eigen3
)


link_directories(${RL_LIBRARY_DIR})

add_executable(myMdlDemo myMdlDemo.cpp)

target_link_libraries(myMdlDemo
    rlmdl
    rlkin
    rlsg
    rlhal
    rlplan
    xml2
    xslt
)

