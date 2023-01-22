#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// print vector
template<typename T>
void printv(std::vector<T> & v) {
    if(!v.size()) return;
    if (typeid(T) == typeid(bool))
        for (bool e : v) { cout << (e ? "T" : "F") << " "; }
    else
        for(T e : v) std::cout << e << " ";
    std::cout << std::endl;
}

// print message
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s, const int n) { std::cout << s << ": " << n << std::endl; }

int main() {
    message("========== ARITHMETIC FUNCTORS ==========");
    message("plus() functor");
    vector<long> v1 = { 26, 52, 79, 114, 183 };
    vector<long> v2 = { 1, 2, 3, 4 ,5 };
    vector<long> v3(v1.size(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    plus<long> pl; // sum v1 and v2, result in v3
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), pl);
    printv(v3); // 27 54 82 118 188
    cout << endl;

    message("minus() functor");
    std::fill(v3.begin(), v3.end(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    minus<long> mn; // rest v1 and v2, result in v3
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), mn);
    printv(v3); // 25 50 76 110 178
    cout << endl;

    message("multiply() functor");
    std::fill(v3.begin(), v3.end(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    multiplies<long> mul; // multiply v1 and v2, result in v3
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), mul);
    printv(v3); // 26 104 237 456 915
    cout << endl;

    message("divides() functor");
    std::fill(v3.begin(), v3.end(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    divides<long> div; // divides v1 and v2, result in v3
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), div);
    printv(v3); // 26 26 26 28 36
    cout << endl;

    message("modulus() functor");
    std::fill(v3.begin(), v3.end(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    modulus<long> mod; // extract module % of v1 and v2, result in v3
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), mod);
    printv(v3); // 0 0 1 2 3
    cout << endl;

    message("negate() functor");
    std::fill(v3.begin(), v3.end(), 0);
    printv(v1); // 26 52 79 114 183
    printv(v2); // 1 2 3 4 5
    printv(v3); // 0 0 0 0 0
    negate<long> neg; // turn into negative v1, result in v3 (unary operator)
    transform(v1.begin(), v1.end(), v3.begin(), neg);
    printv(v3); // -26 -52 -79 -114 -183
    cout << endl;

    message("========== RELATIONAL FUNCTORS ==========");
    message("greater() functor");
    v1 = { 1,23,45,67,8 };
    v2 = { 2,11,34,68,2 };
    vector<bool> b3 = { false,false,false,false,false };
    printv(v1); // 1 23 45 67 8
    printv(v2); // 2 11 34 68 2
    printv(b3); // F F F F F
    greater<long> gt; // compare v1 and v2 gt, result in v3, there is also greater_equal
    transform(v1.begin(), v1.end(), v2.begin(), b3.begin(), gt);
    printv(b3); // F T T F T
    cout << endl;

    message("less() functor");
    v1 = { 1,23,45,67,8 };
    v2 = { 2,11,34,68,2 };
    std::fill(b3.begin(), b3.end(), false);
    printv(v1); // 1 23 45 67 8
    printv(v2); // 2 11 34 68 2
    printv(b3); // F F F F F
    less<long> ls; // compare v1 and v2 less, result in v3, there is also less_equal
    transform(v1.begin(), v1.end(), v2.begin(), b3.begin(), ls);
    printv(b3); // F T T F T
    cout << endl;

    message("equal_to() functor");
    v1 = { 1,23,45,67,8 };
    v2 = { 2,11,34,68,8 };
    std::fill(b3.begin(), b3.end(), false);
    printv(v1); // 1 23 45 67 8
    printv(v2); // 2 11 34 68 2
    printv(b3); // F F F F F
    equal_to<long> eq; // compare v1 and v2 equal, result in v3, there is also not_equal_to
    transform(v1.begin(), v1.end(), v2.begin(), b3.begin(), eq);
    printv(b3); // F T T F T
    cout << endl;

    message("use functor for sorting, sort()");
    vector<int> s1 = { 1,23,45,67,8 };
    vector<int> s2(s1.begin(), s1.end());
    printv(s1); // 1 23 45 67 8
    printv(s2); // 1 23 45 67 8
    greater<long> sort_gt; // compare v1 and v2, sort by greater
    less<long> sort_ls; // compare v1 and v2, sort by less
    sort(s1.begin(), s1.end(), sort_gt);
    sort(s2.begin(), s2.end(), sort_ls);
    printv(s1); // 67 45 23 8 1
    printv(s2); // 1 8 23 45 67
    cout << endl;

    message("========== LOGICAL FUNCTORS ==========");
    message("logical_and() functor");
    vector<int> l1 = { 1,0,1,0,1,0,1,0 };
    vector<int> l2 = { 1,1,1,1,0,0,0,0 };
    vector<int> l3(l1.size(), 0);
    printv(l1); // 1 0 1 0 1 0 1 0
    printv(l2); // 1 1 1 1 0 0 0 0
    logical_and<int> la; // applies logical AND to result from l1 and l2
    transform(l1.begin(), l1.end(), l2.begin(), l3.begin(), la);
    printv(l3); // 1 0 1 0 0 0 0 0
    cout << endl;

    message("logical_or() functor");
    l1 = { 1,0,1,0,1,0,1,0 };
    l2 = { 1,1,1,1,0,0,0,0 };
    fill(l3.begin(), l3.end(), 0);
    printv(l1); // 1 0 1 0 1 0 1 0
    printv(l2); // 1 1 1 1 0 0 0 0
    logical_or<int> lor; // applies logical OR to result from l1 and l2
    transform(l1.begin(), l1.end(), l2.begin(), l3.begin(), lor);
    printv(l3); // 1 1 1 1 1 0 1 0
    cout << endl;

    message("logical_not() functor");
    l1 = { 1,0,1,0,1,0,1,0 };
    fill(l3.begin(), l3.end(), 0);
    printv(l1); // 1 0 1 0 1 0 1 0
    logical_not<int> lnot; // applies logical NOT to result from l1 (unary operator)
    transform(l1.begin(), l1.end(), l3.begin(), lnot);
    printv(l3); // 1 1 1 1 1 0 1 0
    cout << endl;

    return 0;
}
