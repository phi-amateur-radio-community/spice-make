add_library(SpiceMakeUtil Checksum.cpp Reader.cpp)
target_include_directories(SpiceMakeUtil PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/generated)
