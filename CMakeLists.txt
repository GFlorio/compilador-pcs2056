cmake_minimum_required(VERSION 3.8)
project(lexico)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c lexico.c lexico.h valor.h valor.c)
add_executable(lexico ${SOURCE_FILES})