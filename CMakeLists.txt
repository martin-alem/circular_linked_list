cmake_minimum_required(VERSION 3.18)
project(circular_linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(circular_linked_list main.c circular_linked_list.c circular_linked_list.h)