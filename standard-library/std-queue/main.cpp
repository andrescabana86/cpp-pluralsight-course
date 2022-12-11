#include <iostream>
#include <list>
#include <queue>
#include <string>
using namespace std;

template <typename T>
void report_queue(T & q) {
    size_t sz = q.size();
    cout << "size: " << sz;
    if(sz) cout << " front: " << q.front() << " back: " << q.back();
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

/*
 * first in - first out structured
 * optimized with a deque as accumulator
 */
int main()
{
    // queue from list
    message("initialize queue from list");
    list<int> l1 = {1, 2, 3, 4, 5};
    queue<int, list<int>> q1(l1);    // constructor copies to new list
    report_queue(q1); // size: 5 front: 1 back: 5

    message("pop all from q1");
    while(!q1.empty()) {
        cout << q1.front() << " "; // 1 2 3 4 5
        q1.pop();
    }
    cout << endl;
    report_queue(q1); // size: 0

    // default queue (deque)
    queue<string> q2;
    message("push strings onto q2");
    for( string s : {"one", "two", "three", "four", "five"} ) {
        q2.push(s);
    }
    report_queue(q2); // size: 5 front: one back: five

    message("pop all from q2");
    while(!q2.empty()) {
        cout << q2.front() << " "; // one two three four five
        q2.pop();
    }
    cout << endl;
    report_queue(q2); // size: 0

    return 0;
}
