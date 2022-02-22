cmake_minimum_required(VERSION 3.10)

project(ClosestPoint)

add_library(Point point.c)

add_executable(ClosestPoint closest_point.c)

target_link_libraries(ClosestPoint m Point)