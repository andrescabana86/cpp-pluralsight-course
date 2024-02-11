cmake_minimum_required(VERSION 3.2.2)
project(ds_linked_list)
set(CMAKE_CXX_STANDARD 20)

add_executable(
        ds_linked_list
        main.cpp linked-list-node/LinkedListNode.cpp linked-list-node/LinkedListNode.h)