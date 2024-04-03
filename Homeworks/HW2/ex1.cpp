#include <iostream>

int main(int argc, char const *argv[]) {
    uint n;
    std::cin >> n;

    int* arr = new int[n];
    for (uint i = 0; i < n; i++)
        std::cin >> arr[i];

    for (uint i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
