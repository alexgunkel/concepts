cmake_minimum_required(VERSION 3.16)
project(c__20)

set(CMAKE_CXX_STANDARD 20)

include(ExternalProject)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external-test)

ExternalProject_Add(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG 78fdd6c00b8fa5dd67066fbb796affc87ba0e075
        GIT_PROGRESS true
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${TEST_INSTALL_LOCATION} -DCMAKE_INSTALL_LIBDIR=lib64 -DCMAKE_CXX_FLAGS="-w"
        )

add_executable(c__20 main.cpp)

enable_testing()

add_subdirectory(test)
