#include <functional>
#include <iostream>
#include <vector>
using namespace std;

auto firstLevelCurryFn =
[](const int a) {
    return [a](const int b) {
        return [a,b](const int c) {
            return a+b+c;
        };
    };
};

int main() {
    const auto firstLvl = firstLevelCurryFn(1);
    const auto secondLvl = firstLvl(2);
    const int result = secondLvl(3);
    cout << "result is: " << result << endl;
    return 0;
}
