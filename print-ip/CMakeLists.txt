cmake_minimum_required(VERSION 3.14)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(print-ip VERSION ${PROJECT_VERSION})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(print-ip
  main.cpp
)

if(WITH_GTEST)
    find_package(GTest)

    add_executable(print-ip-tests print-ip-tests.cpp)

    target_link_libraries(print-ip-tests
        GTest::gtest_main
    )
endif()

if (MSVC)
    target_compile_options(print-ip PRIVATE
        /W4
    )
    if(WITH_GTEST)
        target_compile_options(print-ip-test PRIVATE
            /W4
    )
    endif()
else ()
    target_compile_options(print-ip PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GTEST)
        target_compile_options(print-ip-tests PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    endif()
endif()

install(TARGETS print-ip
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_GTEST)
    enable_testing()
    add_test(print-ip-test print-ip-test)
endif()
