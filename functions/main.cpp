#include <iostream>
/*
 * Functions has a name, a return type and definition body
 * We don't necessary need parameters, it's optional, when it is present, it should has a type definition
 * We do need a return type, but if we don't return a type we can define it as 'void'
 * The primary function of a function is to prevent duplication
 */

int MultiplyTwoNumbers(int a, int b)
{
    return a * b;
}

void MultiplyAndLog(int a, int b)
{
    int result = MultiplyTwoNumbers(a,b);
    std::cout << "Result: " << result << std::endl;
}

int main() {
    MultiplyAndLog(4,2);
    MultiplyAndLog(43,22);
    MultiplyAndLog(142,32);
    return 0;
}