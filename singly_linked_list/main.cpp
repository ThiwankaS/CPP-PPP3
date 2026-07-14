#include "List.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(void) {

    std::vector<std::vector<int>> complex;

    complex.push_back({ 91, 92, 93, 94, 95});
    complex.push_back({ 26, 27, 28, 29, 30});
    complex.push_back({ 11, 12, 13, 14, 15});
    complex.push_back({ 16, 17, 18, 19, 20});

    List<std::vector<int>> simple_list;

    simple_list.push_front(complex[1]);
    simple_list.push_front(complex[2]);
    simple_list.push_front(complex[0]);

    auto temp = simple_list.pop_front(); 

    for(auto value : temp) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return EXIT_SUCCESS;
}
