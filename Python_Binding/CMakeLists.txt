cmake_minimum_required(VERSION 3.5)
project(simplemath)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} src)

# Build Python module
add_library(simplemath SHARED
    src/lib.cpp
    src/lib_py.cpp
)

set_target_properties(simplemath PROPERTIES PREFIX "" SUFFIX ".so")

target_link_libraries(simplemath ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Build C++ test executable
add_executable(test_cpp test/main.cpp src/lib.cpp)
target_include_directories(test_cpp PRIVATE src)
target_link_libraries(test_cpp)

# Build Python embedding test executable
add_executable(test_py test/main_py.cpp)
target_include_directories(test_py PRIVATE src ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
target_link_libraries(test_py ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Set RPATH so test_py and test_cpp can find simplemath.so if needed
set_target_properties(test_py PROPERTIES
    BUILD_RPATH $ORIGIN/../src
)
set_target_properties(test_cpp PROPERTIES
    BUILD_RPATH $ORIGIN/../src
)
