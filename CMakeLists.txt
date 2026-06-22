cmake_minimum_required(VERSION 3.16)
project(SpiceMake C CXX)

set(CMAKE_CXX_STANDARD 20)

include(cmake/Deps.cmake)

add_subdirectory(src)
