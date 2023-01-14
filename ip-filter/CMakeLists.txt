cmake_minimum_required(VERSION 3.14)

project(ip-filter LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(ip-filter
  main.cpp
)
target_link_libraries(ip-filter Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS ip-filter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
