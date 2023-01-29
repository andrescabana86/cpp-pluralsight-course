#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;

// print the elements of the array
template<typename T>
void printv(vector<T> & a) {
    for(T &i : a) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
template<typename T>
void message(const char * s, const T & v) { cout << s << ": " << v << endl; }


int main() {
    message("===============ACCUMULATE EXAMPLE===============");
    vector<int> acc1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(acc1);
    message("accumulate() from one container to another, this is similar to reduce on other languages");
    int result = accumulate(acc1.begin(), acc1.end(), 0, [](int total, int current)->int { return total += current; });
    message("result is: ", result);

    return 0;
}
