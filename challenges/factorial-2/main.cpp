/**
 * Challenge:
 * create a function that takes an input and returns the factorial
 * use recursion
*/

#include <iostream>
using namespace std;

int factorial(const int input, const int sum=1) {
    if (input > 1) return factorial(input-1, sum*input);
    return sum;
}

int main() {
    int number = 5;
    cout << "factorial of " << number << ": " << factorial(number);
    return 0;
}