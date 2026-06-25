add_library(SpiceMakeArg Command.cpp)
target_include_directories(SpiceMakeArg PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(SpiceMakeArg PRIVATE SpiceMakeDeps)
