cmake_minimum_required(VERSION 3.2.2)
project(ds_tree)
set(CMAKE_CXX_STANDARD 20)

include_directories(tree-node)
include_directories(tree)

add_executable(
    ds_tree
    main.cpp
    tree-node/TreeNode.h tree-node/TreeNode.cpp tree/Tree.h tree/Tree.cpp)