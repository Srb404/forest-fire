cmake_minimum_required(VERSION 4.1)
project(forest-fire C)

set(CMAKE_C_STANDARD 11)

add_executable(forest-fire main.c grid.c)
target_compile_options(forest-fire PRIVATE -Wall -Wextra)
