#include <cstdlib>
#include <iostream>

#define LEN 10

int len_foo() {
    int i = 2;
    return i;
}

constexpr int len_foo_constexpr() {
    return 5;
}

constexpr int fibonacci(const int n) {
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {

    char arr_1[10];                         // legal and allowed
    char arr_2[LEN];                        // legal and allowed

    int len_1 = 10;

    // char arr_3[len_1];                   // illegal and not-allowed

    const int len_2 = len_1 + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;

    // char arr_4[len_2];                   // illegal and but some compilers allowed
    char arr_5[len_2_constexpr];            // legal and allowed
    //char arr_6[len_foo() + 1];            // illegale and not allowed
    char arr_6[len_foo_constexpr() + 1];    // legal and allowed

    std::cout << fibonacci(10) << std::endl;

    // silencing the compiler error for unused varibales
    arr_1[len_2 - 11] = arr_2 [len_2 - 11] = arr_5[len_2 - 11] = arr_6[len_2 - 11] = 'A';
    std::cout << arr_1[0] << std::endl; 

    return EXIT_SUCCESS;
}
