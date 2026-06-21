add_executable(SpiceMake Main.cpp)

add_subdirectory(pkg)

target_link_directories(SpiceMake PRIVATE ${CMAKE_SOURCE_DIR}/include)
