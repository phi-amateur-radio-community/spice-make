cmake_minimum_required(VERSION 3.16)
project(
        SpiceMake
        VERSION 0.1.0
        LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)

include(cmake/Deps.cmake)
configure_file(
        cmake/Metadata.hpp.in
        ${CMAKE_BINARY_DIR}/generated/Metadata.hpp
        @ONLY
)

add_subdirectory(src)
