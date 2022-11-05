/**
 * Templates are a way of abstraction
 * template <template params>
 * typeReturned fnName(...) {}
 */
#include <iostream>

template <size_t size>
void print(int array[size][size])
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
int ** transpose(const int array[size][size])
{
    int **result;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j) {
            std::cout << i << j << " ";
            result[j][i] = array[i][j];
        }
        std::cout << std::endl;
    }
    return result;
}

int main() {
    const int size = 4;
    int twoDimArr[size][size] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };

    print<size>(twoDimArr);

    return 0;
}