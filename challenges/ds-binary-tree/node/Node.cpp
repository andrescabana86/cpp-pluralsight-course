//
// Created by andrescabana86 on 5/2/2023.
//
#include "Node.h"

template<typename T>
Node<T>::Node() {};

template<typename T>
Node<T>::Node(T data)
    : data(data), left(nullptr), right(nullptr) {};

template<typename T>
void Node<T>::InstertLeft(T value) {
    auto node = std::make_unique<Node<T>>(value);
    return left = std::move(node);
}

template<typename T>
void Node<T>::InstertRight(T value) {
    auto node = std::make_unique<Node<T>>(value);
    return right = std::move(node);
}