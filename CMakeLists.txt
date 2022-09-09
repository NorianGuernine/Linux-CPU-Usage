cmake_minimum_required(VERSION 3.13)

project(cpu_utilization)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpu_utilization src/cpu_utilization.cpp)

target_include_directories(cpu_utilization PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
