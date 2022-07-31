cmake_minimum_required(VERSION 3.10)

# set the project name
project(SFM)

# Find Torch
set(CMAKE_PREFIX_PATH libtorch)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# add the executable
add_executable(SFM main.cpp)



