cmake_minimum_required(VERSION 3.10)

project(JosephusPorblem)

add_library(List list.c)

add_executable(JosephusPorblem main.c)

target_link_libraries(JosephusPorblem List)