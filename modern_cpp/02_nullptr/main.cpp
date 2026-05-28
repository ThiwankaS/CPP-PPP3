#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <type_traits>

void foo(char*);
void foo(int);

int main(void) {

    if(std::is_same<decltype(NULL), decltype(0)>::value) {
        std::cout << " NULL == 0 " << std::endl;
    } else {
        std::cout << " NULL != 0 " << std::endl;
    }

    if(std::is_same<decltype(NULL), decltype((void*)0)>::value) {
        std::cout << " NULL == (void*)0 " << std::endl;
    } else {
        std::cout << " NULL != (void*)0 " << std::endl;
    }

    if(std::is_same<decltype(NULL), std::nullptr_t>::value) {
        std::cout << " NULL == nullptr " << std::endl;
    } else {
        std::cout << " NULL != nullptr " << std::endl;
    }

    foo(0);
    foo(nullptr);
    // foo(NULL) doesn't compile

    return EXIT_SUCCESS;
}

void foo(char* str) {
    std::cout << "foo(char*) is called : [" << str << "]\n";
}

void foo(int i) {
    std::cout << "foo(int) is called : [" << i << "]\n";
}
