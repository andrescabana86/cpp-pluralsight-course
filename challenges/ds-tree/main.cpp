//
// Created by andrescabana86 on 1/2/2023.
//
#include <iostream>
#include "Tree.h"

int main() {
    Tree<int> tree(1);
    auto one = tree.Find(1, [](const int a, const int b)->bool { return a == b; } );
    if (one.value()) {
        std::cout << "Found node with value: " << one.value()->data << std::endl;
    } else {
        std::cout << "Node with the specified value was not found" << std::endl;
    }

    tree.Insert(2);
    auto two = tree.Find(2, [](const int a, const int b)->bool { return a == b; } );
    if (two.value()) {
        std::cout << "Found node with value: " << two.value()->data << std::endl;
    } else {
        std::cout << "Node with the specified value was not found" << std::endl;
    }

    auto three = tree.Find(3, [](const int a, const int b)->bool { return a == b; } );
    if (three.value()) {
        std::cout << "Found node with value: " << three.value()->data << std::endl;
    } else {
        std::cout << "Node with the " << 3 << " value was not found" << std::endl;
    }

    std::cout << "Insert child node under node with value 2: " << std::endl;
    tree.Insert(3, *two.value());
    three = tree.Find(3, [](const int a, const int b)->bool { return a == b; } );
    if (three.value()) {
        std::cout << "Found node with value: " << three.value()->data << std::endl;
    } else {
        std::cout << "Node with the " << 3 << " value was not found" << std::endl;
    }

    std::cout << "Insert child node under root with value 4: " << std::endl;
    tree.Insert(4);

    auto four = tree.Find(4, [](const int a, const int b)->bool { return a == b; } );
    if (four.value()) {
        std::cout << "Found node with value: " << four.value()->data << std::endl;
    } else {
        std::cout << "Node with the " << 4 << " value was not found" << std::endl;
    }

    return 0;
}
