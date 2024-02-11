//
// Created by andrescabana86 on 5/2/2023.
//
#pragma once
#include <memory>

template<typename T>
class Node {
public:
    Node();
    Node(T value);
    void InstertLeft(T value);
    void InstertRight(T value);
    T data;
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;
};
