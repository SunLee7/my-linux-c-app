cmake_minimum_required(VERSION 3.5)
project(e2000-test)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_C_FLAGS "-lm")

aux_source_directory(. DIR_SRCS)

add_executable(e2000-test ${DIR_SRCS})
