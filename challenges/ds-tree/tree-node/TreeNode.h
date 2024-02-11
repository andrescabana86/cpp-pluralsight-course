//
// Created by andrescabana86 on 1/2/2023.
//
#pragma once
#include <memory>
#include <vector>

template<typename T>
class TreeNode {
public:
    TreeNode();
    TreeNode(T value);
    TreeNode<T>& Insert(T value);
    T data;
    std::vector<std::unique_ptr<TreeNode<T>>> children;
};
