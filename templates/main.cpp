/**
 * Templates are a way of abstraction
 * template <template params>
 * typeReturned fnName(...) {}
 */
#include <iostream>

template <size_t rows, size_t cols>
void printArray(int array[rows][cols])
{
    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < cols; ++j) {
            std::cout << array[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <size_t rows, size_t cols>
int ** transpose(const int array[rows][cols])
{
    int **result;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << i << j << " ";
            result[j][i] = array[i][j];
        }
        std::cout << std::endl;
    }
    return result;
}

int main() {
    const int rows = 4;
    const int cols = 4;
    int twoDimArr[rows][cols] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };

    return 0;
}