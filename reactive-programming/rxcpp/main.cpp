//
// Created by andrescabana86 on 1/3/2023.
//
/*
 * ReactiveX extensions implements observer pattern
 * components:
 * - observables: composable streams of events
 * - observers: those interested on observables events
 * - operators: manipulate observables
 * - schedulers: execute actions related to operators
 * The RxCpp Library:
 * - it's a header only, c++ implementation
 * - can convert from STL containers to observables
 * - supports either a chaining or a pipe interface
 */
#include <iostream>
#include "rx.hpp"

int main() {
    auto fib =
            rxcpp::observable<>::create<long long>([](rxcpp::subscriber<long long> s) {
                long long a = 0, b = 1;
                for (int i = 0; i < 10; i++) {
                    s.on_next(b);
                    long long temp = b;
                    b += a;
                    a = temp;
                }
                s.on_completed();
            });

    fib.subscribe([](long long val) {
        std::cout << val << " ";
    });

    return 0;
}


