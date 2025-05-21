cmake_minimum_required(VERSION 2.8.11)
project(myMdlDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set your local rl paths
set(RL_INCLUDE_DIR "/home/cnc/Desktop/BUILD3/rl/src")
set(RL_LIBRARY_DIR "/home/cnc/Desktop/BUILD3/rl/build/lib")

include_directories(
    ${RL_INCLUDE_DIR}
    /usr/include/eigen3
    /home/cnc/Desktop/BUILD3/rl/build/src/
)

link_directories(${RL_LIBRARY_DIR})

add_executable(myMdlDemo myMdlDemo.cpp)

target_link_libraries(myMdlDemo
    rlmdl
    rlkin
    rlsg
    rlhal
    rlplan
    xml2     # <-- Add this
    xslt     # <-- And this
)



