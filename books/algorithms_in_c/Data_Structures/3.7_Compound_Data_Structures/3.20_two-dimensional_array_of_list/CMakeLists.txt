cmake_minimum_required(VERSION 3.5)

project(TwoDimensionalArrayOfList)

add_library(Point point.c)

add_executable(TwoDimensionalArrayOfList main.c)

target_link_libraries(TwoDimensionalArrayOfList m Point)