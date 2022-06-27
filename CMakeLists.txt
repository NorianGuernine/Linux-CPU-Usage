cmake_minimum_required(VERSION 3.13)

project(CPU_Widget)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPU_infos src/main.cpp src/CPU.cpp)

target_include_directories(CPU_infos PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")