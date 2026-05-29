#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<int> vec = { 1, 2, 3, 4 };

    // general way of accessing and update the value
    auto itr = std::find(vec.begin(), vec.end(), 2);
    if(itr != vec.end()) {
        *itr = 3;
    }

    /**
      * itr was declared in main scope but ptr was declared in local scope
      */
    // modern way of doing the same
    if(auto ptr = std::find(vec.begin(), vec.end(), 3); ptr != vec.end()) {
        *ptr = 4;
    }

    // expected out put 1,4,3,4
    for(auto ptr = vec.begin(); ptr != vec.end(); ++ptr) {
        std::cout << *ptr << std::endl;
    }

    return EXIT_SUCCESS;
}
