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


int main() {
    message("===============COUNT EXAMPLE===============");
    vector<int> s1 = {
        1,2,3,4,5
    };
    printv(s1);
    message("use count()");
    auto c = count(s1.begin(), s1.end(), 5); // count occurrences of a number
    cout << "found " << c << " occurrences" << endl;
    message("use count_if()");
    auto cif = count_if(s1.begin(), s1.end(), [](const int& value)->bool { return value%2!=0; }); // count occurrences of a number that matches the unary condition
    cout << "found " << cif << " is_odd occurrences" << endl;

    return 0;
}
