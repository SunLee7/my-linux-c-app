cmake_minimum_required(VERSION 3.5)
project(i2c_test)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_C_FLAGS "-lm")

aux_source_directory(. DIR_SRCS)

add_executable(i2c_test ${DIR_SRCS})
