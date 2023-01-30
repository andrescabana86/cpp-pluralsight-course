#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void demoFunction() {
  cout << "called demoFunction" << endl;
}

void adder(int a, int b) {
    cout << "called adder, a+b=" << a+b << endl;
}

class functor {
public:
    void operator()() const {
        cout << "called functor" << endl;
    }
};

int main() {
    vector<function<void()>> funcs;
    funcs.push_back(demoFunction);
    funcs.push_back([]() { cout << "called anonymous lambda function" << endl; });
    functor functor_instance;
    funcs.push_back(functor_instance);
    funcs.push_back(bind(&adder, 10, 15));
    // any callable object can be saved as std::function type inside containers
    for (auto& f : funcs) {
        f();
    }

    return 0;
}
