# CMakeLists.txt

cmake_minimum_required(VERSION 3.22)
project(CPP03)

set(CLANG_TIDY_COMMAND "/usr/bin/clang-tidy -config=.clang-tidy")
set(CMAKE_CXX_STANDARD 98)

add_subdirectory(ex00)
add_subdirectory(ex01)
add_subdirectory(ex02)
add_subdirectory(ex03)