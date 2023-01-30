#include <iostream>
#include <functional>
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

bool greater_than(const int& first, const int& second) {
    return first >= second;
}

int main() {
    message("===============BIND EXAMPLE===============");
    vector<int> v1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(v1);
    message("bind() function into a lambda");
    // count_if expects unary (one argument) predicate
    // greater_than() is a binary predicate
    // we apply bind() to pass only one argument and replace the other
    int count = count_if(v1.begin(), v1.end(), bind(&greater_than, placeholders::_1, 21));
    message("result of count: ", count);

    return 0;
}
