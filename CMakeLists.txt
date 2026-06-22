cmake_minimum_required(VERSION 4.1)
project(ff C)

set(CMAKE_C_STANDARD 11)

add_executable(ff main.c grid.c)
target_compile_options(ff PRIVATE -Wall -Wextra)
