cmake_minimum_required(VERSION 3.14)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(VEditorMVC VERSION ${PROJECT_VERSION})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(primitives)

add_executable(VEditorMVC
    imodel.h
    observable.h
    observable.cpp
    iobserver.h
    main.cpp
)

target_link_libraries(VEditorMVC PRIVATE graph_primitives)

if (MSVC)
    target_compile_options(VEditorMVC PRIVATE
        /W4
    )
else ()
    target_compile_options(VEditorMVC PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS VEditorMVC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
