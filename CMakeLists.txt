cmake_minimum_required(VERSION 3.10)

# set the project name
project(SFM)
set (CMAKE_CXX_STANDARD 17)

# Find Torch
set(CMAKE_PREFIX_PATH libtorch)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# Find SFML
find_package(SFML COMPONENTS graphics REQUIRED)

include_directories(include)
add_subdirectory(src)
enable_testing()
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
add_subdirectory(tests)

# add the executable
add_executable(SFM main.cpp)



