#include <iostream>
#include <list>
using namespace std;

// print the elements of the list
template<typename T>
void printl(list<T> & l) {
    if(l.empty()) return;
    for(T &i : l) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * s, const int n) { cout << s << ": " << n << endl; }

int main() {
    list<int> l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printl(l1); // 1 2 3 4 5 6 7 8 9 10
    message("size", (int) l1.size()); // size: 10
    message("front", l1.front()); // front: 1
    message("back", l1.back()); // back: 10

    message("push back 47");
    l1.push_back(47);
    printl(l1); // 1 2 3 4 5 6 7 8 9 10 47

    // need an iterator to insert and erase
    message("insert:");
    list<int>::iterator it1 = l1.begin();
    while((*++it1 != 5) && (it1 != l1.end()));
    if (it1 != l1.end()) {
        message("insert 112 before 5");
        l1.insert(it1, 112);
    }
    printl(l1); // 1 2 3 4 112 5 6 7 8 9 10 47

    // find element value 7
    while((*++it1 != 7) && (it1 != l1.end()));
    if (it1 != l1.end()) {
        message("erase 7");
        l1.erase(it1);
    }
    printl(l1); // 1 2 3 4 112 5 6 8 9 10 47

    // remove all elements with value 8
    l1.remove(8);
    message("remove 8");
    printl(l1); // 1 2 3 4 112 5 6 9 10 47

    message("erase 112 to 9");
    auto it2 = it1 = l1.begin();
    while( ( *++it1 != 112) && (it1 != l1.end() ) );
    while( ( *++it2 != 9) && (it2 != l1.end() ) );
    if (it1 != l1.end() && it2 != l1.end()) {
        l1.erase(it1, it2);
        printl(l1); // 1 2 3 4 9 10 47
    }

    cout << endl;

    return 0;
}
