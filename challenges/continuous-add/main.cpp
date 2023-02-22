/**
 * Challenge:
 * create a lambda called continuousAdd
 * it takes 2 args: initial, and addBy
 * each call successsively adds addBy to initial
 * lambda should be mutable
*/

#include <iostream>
using namespace std;

auto continuousAdd = [](int initial, int addBy) {
    int total = initial;
    return [total, addBy]() mutable {
        total += addBy;
        return total;
    };
};

int main() {
    auto x = continuousAdd(10, 10);
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    cout << x() << endl;
    return 0;
}