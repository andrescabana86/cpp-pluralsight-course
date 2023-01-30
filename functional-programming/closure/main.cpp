#include <functional>
#include <iostream>
#include <vector>
using namespace std;

auto closureFunction = []() {
    int increment = 0;
    return [increment]() mutable {
        return ++increment;
    };
};

auto closureWithInitial = [](const int initial, const int add) {
    int increment = initial;
    return [increment,add]() mutable {
        return increment += add;
    };
};

int main() {
    auto counter = closureFunction();
    cout << "increment result is: " << counter() << endl;
    cout << "increment result is: " << counter() << endl;
    cout << "increment result is: " << counter() << endl;

    auto adder = closureWithInitial(0, 5);
    cout << "increment result is: " << adder() << endl;
    cout << "increment result is: " << adder() << endl;
    cout << "increment result is: " << adder() << endl;
    return 0;
}
