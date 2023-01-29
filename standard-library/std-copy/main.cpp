#include <iostream>
#include <functional>
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
    message("===============MODIFY AND COPY EXAMPLE===============");
    vector<int> cp1 = {
        71,85,87,94,49,76,59,25,35,15,47,85,96,32,15,76,91,61,37,48,86,62,24,11,37
    };
    printv(cp1);
    message("copy() from one container to another");
    vector<int> copy1(cp1.size(), 0);
    printv(copy1);
    copy(cp1.begin(),cp1.end(),copy1.begin());
    printv(copy1);
    message("copy_n() from one container to another");
    vector<int> copy2(cp1.size(), 0);
    printv(copy2);
    copy_n(cp1.begin(),5,copy2.begin());
    printv(copy2);
    message("copy_if() from one container to another if it matches the unary condition, same as filter");
    vector<int> copyif1;
    copy_if(cp1.begin(),cp1.end(), back_inserter(copyif1), [](int& value)->bool { return value%2==0; });
    printv(copyif1);
    message("copy_backward() from one container to another");
    vector<int> copy3(cp1.size(), 0);
    printv(copy3);
    copy_backward(cp1.begin(),cp1.end(),copy3.end());
    printv(copy3);
    message("reverse_copy() from one container to another");
    vector<int> copy4(cp1.size(), 0);
    printv(copy4);
    reverse_copy(cp1.begin(),cp1.end(),copy4.begin());
    printv(copy4);

    return 0;
}
