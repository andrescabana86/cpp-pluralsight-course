cmake_minimum_required(VERSION 3.2.2)
project(ds_binary_tree)
set(CMAKE_CXX_STANDARD 20)

include_directories(node)
include_directories(binary-tree)

add_executable(
    ds_binary_tree
    main.cpp
    node/Node.h node/Node.cpp binary-tree/BinaryTree.h binary-tree/BinaryTree.cpp)