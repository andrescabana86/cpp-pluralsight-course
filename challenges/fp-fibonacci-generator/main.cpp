//
// Created by andrescabana86 on 1/3/2023.
//
/*
 * Fibonacci generator using Template programming
 * - specializations for the numbers 0 and 1
 * - function returns the number corresponding to the position we sent
 * - eg: the number in position 4 inside fib series is 3
 */

#include <iostream>
using namespace std;

// this is generic generator for fibonacci
// it iterates using recursiv
// it stops with 1 or 0, that's where it uses specializations
template<int n>
struct fibonacci {
    enum {
        // static_cast to avoid arithmetic operations on enums deprecated warning
        value = static_cast<int>(fibonacci<n-1>::value) + static_cast<int>(fibonacci<n-2>::value)
    };
};
// this is specialization for 0
template<>
struct fibonacci<0> {
    enum {
        value = 0
    };
};
// this is specialization for 1
template<>
struct fibonacci<1> {
    enum {
        value = 1
    };
};

int main() {
    cout << "fib(4) = " << fibonacci<4>::value << endl;
    cout << "fib(7) = " << fibonacci<7>::value << endl;
    cout << "fib(12) = " << fibonacci<12>::value << endl;
    return 0;
}
