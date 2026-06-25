add_library(SpiceMakeIo PkgFile.cpp)
target_include_directories(SpiceMakeIo PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR}/generated)
