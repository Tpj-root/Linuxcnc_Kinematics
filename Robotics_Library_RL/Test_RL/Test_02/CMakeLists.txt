cmake_minimum_required(VERSION 3.10)
project(AdvancedRLDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    /home/where/Desktop/BUILD_FILES/rl/src          # main RL headers
    /home/where/Desktop/BUILD_FILES/rl/build/src    # generated export.h
    /usr/include/eigen3
)

link_directories(
    /home/where/Desktop/BUILD_FILES/rl/build/lib
)

add_executable(advanced_ik myAdvancedIkDemo.cpp)

target_link_libraries(advanced_ik
    rlkin
    rlmdl
    rlplan
    rlsg
    rlhal
)

