/**
 * Templates are a way of abstraction
 * template <template params>
 * typeReturned fnName(...) {}
 * characteristics
 * - template variables are always immutable
 * - template doesn't have loops, so we use recursion
 * - template doesn't have branching, we use specialization
 * - You also must use class when explicitly instantiating a template: template class Foo<int>;
 * - typename is used to declare when you are referencing a nested type that depends on another template parameter,
 * such as the typedef, this is a case where template<class T> is not applicable
 */
#include <iostream>
#include <vector>

template <size_t size>
void print(const int (&array)[size][size])
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < size; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <size_t size>
void printPtr(int **array)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < size; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <size_t size>
void transpose(const int (&array)[size][size], int (&result)[size][size])
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j) {
            result[j][i] = array[i][j];
        }
    }
}

template <size_t size>
void transposePtr(const int (&array)[size][size], int **result)
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j) {
            result[j][i] = array[i][j];
        }
    }
}

template <int num>
struct Cube {
    enum {
        value = num * num * num
    };
};

int main() {
    // using a fixed size two dim array
    const int size = 3;
    int twoDimArr[size][size] = {
        1,2,3,4,
        5,6,7,8,
        9
    };
    int result[size][size];

    print<size>(twoDimArr);
    transpose(twoDimArr, result);
    print<size>(result);

    // using two dim pointer array
    int ** ptrResult = new int*[size];
    for (size_t i = 0; i < size; ++i)
    {
        ptrResult[i] = new int[size];
    }

    transposePtr<size>(twoDimArr, ptrResult);
    printPtr<size>(ptrResult);
    std::cout << std::endl;

    // instantiating with meta programming a class
    std::cout << Cube<5>::value << std::endl;


    return 0;
}