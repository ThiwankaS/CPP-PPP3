#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <vector>

class MagicFoo {
    public:
        MagicFoo(std::initializer_list<int> list) {
            for(auto it = list.begin(); it != list.end(); ++it) {
                data.push_back(*it);
            }
        }
        void print_data(void) {
            for(int value : data) {
                std::cout << value << std::endl;
            }
        }
    private:
        std::vector<int> data;
};

std::vector<int> foo (std::initializer_list<int> list) {
    std::vector<int> vec;
    for(auto it = list.begin(); it != list.end(); ++it) {
        vec.push_back(*it);
    }
    return vec;
}

int main(void) {
    MagicFoo obj({1, 2, 3, 4 });
    obj.print_data();

    std::vector<int> temp;

    temp = foo({5, 6, 7, 8});

    for(int value : temp) {
        std::cout << value << std::endl;
    }

    return EXIT_SUCCESS;
}
