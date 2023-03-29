cmake_minimum_required(VERSION 3.14)

set(NAME_EXECUTABLE "sparsematrix")
set(NAME_TESTS "sparsematrix-tests")

set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(${NAME_EXECUTABLE} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

option(WITH_GTEST "Whether to build google test" ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${NAME_EXECUTABLE}
    key.h
    hash.h
    extypes.h

    sparsematrix.h
    main.cpp
)

target_include_directories(${NAME_EXECUTABLE}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if(WITH_GTEST)
    find_package(GTest)

    add_executable(${NAME_TESTS}
        sparsematrix-tests.cpp
    )

    target_link_libraries(${NAME_TESTS}
        GTest::gtest_main)
endif()

if(MSVC)
    target_compile_options(${NANE_EXECUTABLE} PRIVATE
        /W4
    )
    if(WITH_GTEST)
        target_compile_options(${NAME_TESTS} PRIVATE
            /W4
        )
    endif()
else()
    target_compile_options(${NAME_EXECUTABLE} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GTEST)
        target_compile_options(${NAME_TESTS} PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()


install(TARGETS ${NAME_EXECUTABLE}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GTEST)
    enable_testing()
    add_test(${NAME_TESTS} sparsematrix-tests)
endif()
