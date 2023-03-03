//
// Created by andrescabana86 on 3/3/2023.
//
#include <iostream>

// base case
template<typename T>
T summer(T value) {
    return value;
}
// recursive variadic template
template<typename T, typename ... Args>
T summer(T first, Args ... args) {
    return first + summer(args ...);
}

int main() {
    std::cout << "sum of (1,2,3,4,5): " << summer(1,2,3,4,5) << std::endl;
    return 0;
}