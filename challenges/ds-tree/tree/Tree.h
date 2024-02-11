//
// Created by andrescabana86 on 3/2/2023.
//

/*
    Alternatives for containers of a tree
        -> <vector>
            - has a constant time complexity for random access
            - its size is dynamically resized as elements are added or removed
            - inserting or deleting elements in the middle of a vector takes linear time, as all elements after the insertion or
            deletion point need to be shifted.
        -> <deque>
            - has a constant time complexity for random access
            - provides constant time insertions and deletions at both ends
            - it may take longer to resize its size dynamically than a vector
*/
#pragma once
#include <optional>
#include "TreeNode.h"

template<typename T>
class Tree {
public:
    Tree();
    Tree(T root_value);
    std::optional<TreeNode<T>*> Find(T value, bool (*compare)(T, T));
    TreeNode<T>& Insert(T value);
    TreeNode<T>& Insert(T value, TreeNode<T> &node);
    TreeNode<T> root;
private:
    std::optional<TreeNode<T>*> FindHelper(TreeNode<T> &node, T value, bool (*compare)(T, T));
};
