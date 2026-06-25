add_library(SpiceMakePkg SpiceMakePkg.cpp)
target_include_directories(SpiceMakePkg PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/generated)
target_link_libraries(SpiceMakePkg PRIVATE SpiceMakeUtil SpiceMakeDeps)
