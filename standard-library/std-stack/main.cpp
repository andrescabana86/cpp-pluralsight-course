#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

template <typename T>
void report_stack(T & stk) {
    cout << "size: " << stk.size() << " top: " << stk.top() << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main()
{
    // stack with a vector as initializer
    message("stk1");
    vector<int> v1 = {1, 2, 3, 4, 5};
    stack<int, vector<int>> stk1(v1);
    report_stack(stk1); // size: 5 top: 5

    message("stk1 push 42");
    stk1.push(42);
    report_stack(stk1); // size: 6 top: 42

    message("stk1 pop");
    stk1.pop();
    report_stack(stk1); // size: 5 top: 5

    message("pop all from sk1");
    while(!stk1.empty())
    {
        cout << stk1.top() << " ";
        stk1.pop();
    }
    cout << endl;

    message("stk2 default stack (deque used by default)");
    stack<string> stk2;
    for(string s : {"one", "two", "three", "four", "five"}) {
        stk2.push(s);
    }
    report_stack(stk2); // size: 5 top: five

    message("stk2 push forty-two");
    stk2.push("forty-two");
    report_stack(stk2); // size: 6 top: forty-two

    message("stk2 pop");
    stk2.pop();
    report_stack(stk2); // size: 5 top: five

    return 0;
}
