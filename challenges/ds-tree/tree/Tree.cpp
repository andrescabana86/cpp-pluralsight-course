//
// Created by andre on 3/2/2023.
//
#include "Tree.h"

template<typename T>
Tree<T>::Tree() {};

template<typename T>
Tree<T>::Tree(T rootValue): root(TreeNode<T>(rootValue)) {};

template<typename T>
std::optional<TreeNode<T>*> Tree<T>::Find(
        T value,
        bool (*compare)(T, T))
{
    return FindHelper(root, value, compare);
}

template<typename T>
std::optional<TreeNode<T>*> Tree<T>::FindHelper(
    TreeNode<T> &node,
    T value,
    bool (*compare)(T, T))
{
    if (compare(node.data, value)) {
        return &node;
    }

    for (auto &child : node.children) {
        auto result = FindHelper(*child, value, compare);
        if (result.has_value() && result.value()) {
            return result.value();
        }
    }

    return nullptr;
}

template<typename T>
TreeNode<T>& Tree<T>::Insert(T value) {
    return root.Insert(value);
}

template<typename T>
TreeNode<T>& Tree<T>::Insert(T value, TreeNode<T> &root) {
    return root.Insert(value);
}

template class Tree<int>;