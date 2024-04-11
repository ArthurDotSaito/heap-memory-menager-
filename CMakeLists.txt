cmake_minimum_required(VERSION 3.28)
project(LinuxMemoryMenager C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(LinuxMemoryMenager
        mm.c
        mm.h)
