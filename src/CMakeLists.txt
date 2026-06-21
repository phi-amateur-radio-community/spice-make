add_executable(SpiceMake Main.cpp)

add_subdirectory(pkg)

target_include_directories(SpiceMake PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(SpiceMake PRIVATE SpiceMakePkg)
