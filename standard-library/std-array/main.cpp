#include <iostream>
#include <array>
#include <string>
using namespace std;

// print the elements of the array
template<typename T, size_t N>
void printa(array<T, N> & a) {
    for(T &i : a) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
template<typename T>
void message(const char * s, const T & v) { cout << s << ": " << v << endl; }

int main() {
    // initializer list
    message("initializer array");
    array<int, 5> a1 = { 1, 2, 3, 4, 5 };
    printa(a1); // 1 2 3 4 5

    // default constructor
    message("default constructor");
    array<string, 5> a2;
    a2 = {"one", "two", "three"};
    printa(a2); // one two three

    // check the size
    message("size of a1", (int) a1.size());
    message("size of a2", (int) a2.size());

    // access elements
    message("a1 element 3 is", a1[3]); // a1 element 3 is: 4
    message("a2 element 2 is", a2[2]); // a2 element 2 is: three
    message("a1 element 3 is", a1.at(3)); // a1 element 3 is: 4
    message("a2 element 2 is", a2.at(2)); // a2 element 2 is: three

    // direct access data
    int * ip1 = a1.data();
    for (size_t i = 0; i < a1.size(); ++i) {
        cout << "element " << i << " is " << *ip1++ << endl;
    }
    /*
        element 0 is 1
        element 1 is 2
        element 2 is 3
        element 3 is 4
        element 4 is 5
    */

    string * ip2 = a2.data();
    for (size_t i = 0; i < a2.size(); ++i) {
        cout << "element " << i << " is " << *ip2++ << endl;
    }
    /*
        element 0 is one
        element 1 is two
        element 2 is three
        element 3 is
        element 4 is
    */

    return 0;
}
