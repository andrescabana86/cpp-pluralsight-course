#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

// print the elements of the set
template<typename T>
void print_set(T & s) {
    if(s.empty()) return;
    for(auto x : s) cout << x << " ";
    cout << endl;
}

// print a simple message
void message(const char * m) { cout << m << endl; }
template <typename T>
void message(const char * m, const T & v) { cout << m << ": " << v << endl; }

int main() {
    message("construct set set1");
    set<string> set1 = { "one", "two", "three", "four", "five" };
    message("size of set", set1.size()); // size of set: 5
    message("ordered set is alphabetical");
    print_set(set1); // five four one three two

    message("insert element six");
    set1.insert("six");
    print_set(set1); // five four one six three two

    message("find and erase element six");
    set<string>::iterator it = set1.find("six");
    if(it != set1.end()) {
        message("erasing", *it); // erasing: six
        set1.erase(it);
    } else {
        cout << "not found" << endl;
    }
    print_set(set1); // five four one three two

    message("inserting duplicate element five");
    set1.insert("five");
    print_set(set1); // five four one three two
    cout << endl;

    message("inserting duplicate element five, handling failed");
    auto maybeFailed = set1.insert("one");
    // insert() returns a pair where the .second value is either true/false
    // indicating if the operation succeed or failed
    if (!maybeFailed.second) message("insert(one) failed");
    print_set(set1); // five four one three two
    cout << endl;

    message("inserting duplicate element five, using multiset succeed");
    message("construct multiset1");
    multiset<string> multiset1 = { "one", "two", "three", "four", "five" };
    multiset1.insert("one");
    print_set(multiset1); // five four one one three two
    cout << endl;

    message("construct unordered set set1");
    unordered_set<string> set2 = { "one", "two", "three", "four", "five" };
    message("size of set", set2.size()); // size of set: 5
    message("unordered set has no defined order");
    print_set(set2); // five four three two one
    cout << endl;

    message("insert element six");
    set2.insert("six");
    print_set(set2); // six five four three two one
    cout << endl;

    message("find and erase element six");
    auto it2 = set2.find("six");
    if(it2 != set2.end()) {
        message("erasing", *it2);
        set2.erase(it2);
    } else {
        cout << "not found" << endl;
    }
    print_set(set2); // five four three two one
    cout << endl;

    message("inserting duplicate element five");
    set2.insert("five");
    print_set(set2); // five four three two one
    cout << endl;

    message("construct unordered multiset umultiset1");
    unordered_multiset<string> umultiset1 = { "one", "two", "three", "four", "five" };
    umultiset1.insert("five");
    print_set(umultiset1); // five four three two one
    cout << endl;

    return 0;
}
