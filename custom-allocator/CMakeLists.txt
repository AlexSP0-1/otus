cmake_minimum_required(VERSION 3.14)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(custom-allocator${PROJECT_VERSION})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(custom-allocator
  main.cpp
)
target_link_libraries(custom-allocator PRIVATE Qt5::Core c_alloc_lib)

add_library(c_alloc_lib c_alloc_lib.cpp)
target_link_libraries(c_alloc_lib PRIVATE Qt5::Core)


install(TARGETS custom-allocator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
