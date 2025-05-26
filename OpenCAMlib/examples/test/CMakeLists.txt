cmake_minimum_required(VERSION 3.10)
project(opencamlib_test VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# === Include Directories ===
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    /home/cnc/Desktop/MY_GIT/Linuxcnc_Kinematics/OpenCAMlib/prebuilds/linux-cxx-x86_64/include/
)

# === First Executable (main.cpp) ===
add_executable(opencamlib_test_exec1 test_example.cpp)
target_link_libraries(opencamlib_test_exec1
    /home/cnc/Desktop/MY_GIT/Linuxcnc_Kinematics/OpenCAMlib/prebuilds/linux-cxx-x86_64/lib/opencamlib/libocl.so
)