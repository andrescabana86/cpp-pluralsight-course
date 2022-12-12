#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>
#include <set>
using namespace std;

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * m, int i) { cout << m << ": " << i << endl; }

int main() {
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // type of auto: vector<int>::iterator
    // iterator should be same type
    auto ibegin = vi1.begin();
    auto iend = vi1.end();

    message("print vector using the iterator vi1");
    for(auto it1 = ibegin; it1 < iend; ++it1) {
        cout << *it1 << " ";
    }
    cout << endl;

    message("Input iterator:");
    /*
     * Input iterator is the simplest form of iterator
     * istream uses an input iterator, it receives cin
     * used to read values one time, and then increment
     * it's capable of reading and not writing
     * incrementing but not decrementing
     * once the current value of the iterator is read, it cannot be read again
     */
    double d1 = 0, d2 = 0;

    cout << "Two numeric values: " << flush;
    cin.clear();
    istream_iterator<double> eos;         // default constructor is end-of-stream
    istream_iterator<double> iit(cin);    // stdin iterator

    if(iit == eos) {
        message("no values");
        return 0;
    } else {
        d1 = *iit++;
    }

    if(iit == eos) {
        message("no second value");
        return 0;
    } else {
        d2 = *iit;
    }

    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;

    message("Output iterator:");
    /*
     * Output iterator is the complement of input iterator
     * ostream uses output iterator, it receives cout and a delimiter
     * it acts like a pointer for entry values
     * the delimiter (second argument) is added every iteration
     */
    ostream_iterator<int> output(cout, " "); // construct iterator
    for(int i : { 3, 197, 42 }) {
        *output++ = i; // add every number, on every iteration add " " space
    }
    cout << endl;

    message("Forward iterator:");
    /*
     * Forward iterator is a combination of input-output iterator
     * std::forward_list uses forward iterator
     * it has a few other capabilities
     * it only goes forward, meaning, doesn't have decrement operator
     */
    forward_list<int> fl1 = { 1, 2, 3, 4, 5 };
    forward_list<int>::iterator it1; // forward iterator

    for(it1 = fl1.begin(); it1!= fl1.end(); ++it1) // could also be "auto it1"
    {
        cout << *it1 << " "; // print from 1 to 5
    }
    cout << endl;

    message("Bidirectional iterator:");
    /*
     * Bidirectional iterator can access and iterate over the iterator in both directions
     * std::set container uses a bidirectional iterator
     */

    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int>::iterator bit1; // iterator object

    // iterate forward
    for(bit1 = v1.begin(); bit1 != v1.end(); ++bit1) {
        cout << *bit1 << " ";
    }
    cout << endl;

    // iterate backward
    for(bit1 = v1.end(); bit1 != v1.begin();) {
        cout << *--bit1 << " ";
    }
    cout << endl;

    // range-based for loop works as forward iterator
    for(int i : v1) {
        cout << i << " ";
    }
    cout << endl;

    message("Random Access iterator:");
    /*
     * Random Access iterator is most complete
     * can access to all values at any position
     * does have all functionality of a pointer
     */

    vector<int> rav1 = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    vector<int>::iterator rait1;   // iterator object

    // iterate forward
    for(rait1 = rav1.begin(); rait1 != rav1.end(); ++rait1) {
        cout << *rait1 << " ";
    }
    cout << endl;

    // iterate backward
    for(rait1 = rav1.end(); rait1 != rav1.begin();) {
        cout << *--rait1 << " ";
    }
    cout << endl;

    // range-based for loop
    for(int i : rav1) {
        cout << i << " ";
    }
    cout << endl;

    rait1 = rav1.begin() + 5;
    message("element begin + 5", *rait1);
    message("element [5]", rav1[5]);

    rait1 = rav1.end() - 3;
    message("element end - 3", *rait1);

    return 0;
}
