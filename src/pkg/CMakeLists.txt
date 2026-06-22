add_library(SpiceMakePkg SpiceMakePkg.cpp)
target_include_directories(SpiceMakePkg PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(SpiceMakePkg PRIVATE SpiceMakeUtil)
