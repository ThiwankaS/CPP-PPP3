#include "foo.h"
#include <functional>
#include <iostream>
#include <stdlib.h>

int main(void) {
    
    [out = std::ref(std::cout << "Result from C code : " << add(1, 2))](){
        out.get() << ".\n";
    }();

    return EXIT_SUCCESS;
}
