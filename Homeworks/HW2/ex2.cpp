#include <iostream>
#include <random>

// NOTE:
// -------------------------------------------
//  I know that this is a very bad practice,
//  as I did not deallocate the oddArr
//  dynamic array. However, if I did, I could
//  not be sure that the place it owned, won't
//  be taken by other data. If it was up to
//  me, I would use std::vector instead of
//  a dynamic array, but sadly the assignment
//  was to do it with the latter option :(
// -------------------------------------------
int* getOddArray(int* arr, uint size, uint& oddSize) {
    oddSize = 0;
    
    for (uint i = 0; i < size; i++)
        if (arr[i] % 2)
            oddSize++;
    
    int* oddArr = new int[oddSize];

    for (uint i = 0, j = 0; i < size; i++)
        if (arr[i] % 2)
            oddArr[j++] = arr[i];

    return oddArr;
}

void print(int* arr, uint size) {
    for (uint i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    srand((uint)time(0)); // to change the seed per every run

    uint size;
     std::cin >> size;

    int* arr = new int[size];
    for (uint i = 0; i < size; i++)
        arr[i] = rand() % 100; // to make it easy to debug

    uint oddSize;
    int* oddArray = getOddArray(arr, size, oddSize);

    print(arr, size);
    print(oddArray, oddSize);

    delete[] oddArray;
    return 0;
}
