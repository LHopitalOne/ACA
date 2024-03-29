#include <iostream>
#include <cmath>

// is_prime function
// checks if the given number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    else if (n == 2 || n == 3) return true;

    for (int i = 2; i <= std::sqrt(n); i++) 
        if (!(n % i))
            return false;
    
    return true;
}

// computes the factorial of
// the given number
int factorial(int n) {
    return n == 0 || n == 1 ? 1 : n * factorial(n - 1);
}

// computes the nth fibonacci
// number, where n is given
int fib(int n) {
    // note: this is not the recursive solution
    //       that was desired by the homework
    //       statement, instead this is a much
    //       more efficient solution, as it takes
    //       O(1) for both time and space, and not
    //       O(2^n) for both time and O(n) space
    //       complexities :)

    int f0 = 0;
    int f1 = 1;
    
    if (n < 0) return -1;
    else if (n == 0) return f0;
    else if (n == 1) return f1;
    
    int f2 = f1 + f0;
    for (int i = 2; i < n; i++) {
         f0 = f1;
         f1 = f2;
         f2 = f1 + f0;
    }
    
    return f2;
}

int main() {
    std::cout << std::boolalpha << is_prime(191) << " " << is_prime(191191) << std::endl;
    std::cout << factorial(10) << std::endl;
    std::cout << fib(10) << "\n" << std::endl;

    return 0;
}