cmake_minimum_required(VERSION 2.8.11)
project(myMdlDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# RL paths
set(RL_INCLUDE_DIR "/home/cnc/Desktop/BUILD3/rl/src")
set(RL_LIBRARY_DIR "/home/cnc/Desktop/BUILD3/rl/build/lib")

include_directories(
    ${RL_INCLUDE_DIR}
    /usr/include/eigen3
    /home/cnc/Desktop/BUILD3/rl/build/src/
)

link_directories(${RL_LIBRARY_DIR})

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

find_library(COIN_LIBRARY coin)


add_executable(myMdlDemo myMdlDemo.cpp)

target_link_libraries(myMdlDemo
    rlmdl
    rlkin
    rlsg
    rlhal
    rlplan
    xml2
    xslt
    Qt5::Widgets
)

target_link_libraries(myMdlDemo PRIVATE ${COIN_LIBRARY} SoQt Qt5::Gui Qt5::Core GL)


find_library(SOQT_LIB SoQt)
target_link_libraries(
    myViewDemo
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
    ${QT_QTOPENGL_LIBRARY}
    ${RL_LIBRARIES}
    ${SOQT_LIB}
)


