#include <iostream>

int main() {
    int integer = 8; // 4 bytes large (32bits total) range -2b < 0 < 2b
    std::cout << "signed integer: " << integer << std::endl;
    // unsigned numbers are only positive numbers, using 1 bit more by removing the sign
    unsigned unsigned_integer = 8; // 4 bytes large (32bits total) range 0 < 4b
    std::cout << "unsigned number (always positive): " << unsigned_integer << std::endl;

    // other types of numbers, all values primitives
    /*
     * char 1 byte of data
     * short 2 bytes of data
     * int 4 bytes of data
     * long usually 4 bytes of data, depending on the compiler
     * long long 8 bytes of data
     * float 4 bytes of data
     * double 8 bytes of data
     * bool 1 byte
     */

    // type char is numeric, if you save a number or a letter it will always be interpreted as a letter
    char letter = 'A';
    std::cout << "this is a letter inside a char: " << letter << std::endl;
    letter = 65;
    std::cout << "this is a number inside a char: " << letter << std::endl;

    /*
     * float a double are decimals representations
     * the way we decide which one to use is
     * to append an 'f' at the end of the number
     */
    float float_number = 5.5; // this is a double
    std::cout << "this is a float compiled as double: " << float_number << std::endl;
    float real_float_number = 5.5f; // this is a float
    std::cout << "this is a float compiled as float: " << real_float_number << std::endl;
    double double_number = 5.5; // this is also a double
    std::cout << "this is a double: " << double_number << std::endl;

    // bool uses 1 byte, meaning 8 bits
    // we could use 1 bit by doing optimizations
    // in general, computer cannot manage bits so
    // bool will always ocupy 1 byte
    bool bool_value = true;
    std::cout << "this is a bool: " << bool_value << std::endl;

    /*
     * if we want to check the size of a data type
     * we can use sizeof() function
     */
    std::cout << "size (in bytes) of an char: " << sizeof(char) << std::endl;
    std::cout << "size (in bytes) of an short: " << sizeof(short) << std::endl;
    std::cout << "size (in bytes) of an int: " << sizeof(int) << std::endl;
    std::cout << "size (in bytes) of an long: " << sizeof(long) << std::endl;
    std::cout << "size (in bytes) of an long long: " << sizeof(long long) << std::endl;
    std::cout << "size (in bytes) of an float: " << sizeof(float) << std::endl;
    std::cout << "size (in bytes) of an double: " << sizeof(double) << std::endl;
    std::cout << "size (in bytes) of an bool: " << sizeof(bool) << std::endl;
    std::cout << "size (in bytes) of an long int: " << sizeof(long int) << std::endl;

    // all of the varialbes can be represented using pointers and or references
    // pointers using '*' character
    // references using '&' character
    bool* bool_pointer = new bool(false);
    int& int_reference = integer;
    std::cout << "this is a bool pointer: " << bool_pointer << std::endl;
    std::cout << "this is an int reference: " << int_reference << std::endl;

    return 0;
}