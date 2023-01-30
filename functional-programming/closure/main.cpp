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

int main() {
    auto counter = closureFunction();
    cout << "increment result is: " << counter() << endl;
    cout << "increment result is: " << counter() << endl;
    cout << "increment result is: " << counter() << endl;
    return 0;
}
