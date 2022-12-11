#include <iostream>
#include <deque>
#include <string>
using namespace std;

// report deque info
template <typename T>
void reportdeq(T & d) {
    size_t sz = d.size();
    cout << "size: " << sz;
    if (sz) cout << " front: " << d.front() << " back: " << d.back();
    cout << endl;
}

// print deque
template <typename T>
void printdeq(T & d) {
    if (d.empty()) return;
    for (auto v : d) cout << v << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

/*
 * Similar to vector
 * where vector is optimized for random access
 * deque is optimized for rapid push and pop from its ends
 */
int main() {
    message("create deque");
    deque<string> d1 = {"one", "two", "three"};
    printdeq(d1); // one two three

    message("push back values");
    d1.push_back("four");
    d1.push_back("five");

    reportdeq(d1); // size: 5 front: one back: five
    printdeq(d1); // one two three four five

    message("pop from front");
    d1.pop_front();
    printdeq(d1); // two three four five

    message("pop from back");
    d1.pop_back();
    printdeq(d1); // two three four

    message("push front");
    d1.push_front("newfront");
    printdeq(d1); // newfront two three four

    message("push back");
    d1.push_back("newback");
    printdeq(d1); // newfront two three four newback

    return 0;
}
