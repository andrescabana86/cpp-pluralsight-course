#include <iostream>

int main() {
    const int num = 3;
    const int *pNum = &num;

    std::cout << "size of num: " << sizeof(num) << std::endl;
    // a pointer is an address, and does not have the sizeof the value
    // the sizeof a pointer depends on the local architecture
    // 4 bytes on 32-bits arch
    // 8 bytes on 64-bits arch
    std::cout << "size of num ptr: " << sizeof(pNum) << std::endl;

    // Array address names are pointer
    // the diff is that pointers values can be change on run time whereas array names always target the same memory space

    double arr[3] = {1,2,3};
    double *pArr = arr; // arr is actually a ptr
    std::cout << "arr memory address: " << &arr << std::endl;
    std::cout << "pArr memory address: " << pArr << std::endl;

    // memory space in an array are adjacents
    // it's a 4 bytes spaced alloc
    int arrAdj[5] = {1,2,3,4,5};
    for (int i=0; i<5; i++) {
        std::cout << "arrAdj memory address: " << &arrAdj[i] << std::endl;
    }

    // casting a ptr
    std::cout << "arr memory cast ptr: " << (void *)arr << std::endl;
    std::cout << "arr memory cast ptr: " << static_cast<void *>(arr) << std::endl;

    // string literals are char pointer list
    // here an example
    const char *strLit = { "this is a string" };
    std::cout << "strLit memory ptr deref: " << (void *)strLit << std::endl;
    std::cout << "strLit memory ptr: " << &strLit << std::endl;


    // observe how pointers dereference works
    double testScores[5] = {1,2,3,4,5}; // array name is a pointer
    double* pTestScores = testScores; // we can initialize a ptr pointing to array name

    std::cout << "testScores arr name address: "<<testScores<<std::endl;
    // this is pointing to first element
    // remember arr is memory alloc adjacent
    // so, the next element is right next to the first
    std::cout << "pTestScores ptr first element: "<<*pTestScores<<std::endl;
    std::cout << "pTestScores ptr first element memory address: "<<&(*pTestScores)<<std::endl;
    // next element memory address is 8 bytes after
    // remember 4 bytes on 32bits arch, 8 bytes on 64bits arch
    std::cout << "pTestScores ptr second element: "<<*(pTestScores+1)<<std::endl;
    std::cout << "pTestScores ptr second element memory address: "<<&(*(pTestScores+1))<<std::endl;
    // casting to deref shows the same memory address as arr name
    std::cout << "pTestScores ptr address: "<<(double *)pTestScores<<std::endl;

    // pointing pointers to other pointers
    int num2 = 10;
    int *pNum2 = &num2;
    int **ppNum2 = &pNum2;

    std::cout << "num2 memory address: "<<&num2<<std::endl;
    std::cout << "pNum2 memory address: "<<&pNum2<<std::endl;
    std::cout << "pNum2 ptr memory address: "<<pNum2<<std::endl;
    std::cout << "ppNum2 memory address: "<<&ppNum2<<std::endl;
    std::cout << "ppNum2 ptr memory address: "<<ppNum2<<std::endl;

    return 0;
}