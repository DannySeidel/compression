cmake_minimum_required(VERSION 3.21)
project(compression C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-lz")

add_executable(compression
        main.c)
