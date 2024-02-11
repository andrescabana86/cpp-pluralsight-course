//
// Created by andrescabana86 on 1/2/2023.
//
#include "TreeNode.h"

template<typename T>
TreeNode<T>::TreeNode() {};

template<typename T>
TreeNode<T>::TreeNode(T value): data(value) {};

template<typename T>
TreeNode<T> &TreeNode<T>::Insert(T value) {
    auto node = std::make_unique<TreeNode<T>>(value);
    children.push_back(std::move(node));
    return *node;
}

template class TreeNode<int>;