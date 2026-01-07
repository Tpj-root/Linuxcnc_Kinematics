cmake_minimum_required(VERSION 3.10)
project(TestRL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# RL include path
include_directories(
    /home/where/Desktop/BUILD_FILES/rl/src
    /usr/include/eigen3
)

# RL library path
link_directories(
    /home/where/Desktop/BUILD_FILES/rl/build/lib
)

add_executable(rl_test myMdlDemo.cpp)

target_link_libraries(rl_test
    rlkin
    rlmdl
    rlplan
    rlsg
    rlhal
)

