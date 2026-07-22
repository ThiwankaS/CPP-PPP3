#include <algorithm>
#include <array>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <span>
#include <vector>

class InvalidData : public std::invalid_argument {
    public:
        explicit InvalidData(const std::string& msg) : std::invalid_argument(msg) {}
};

class Matrix2x2 {
    private:
        std::array<int, 4> data { 0 };
    public:
        // parameretized construtor wich take 04 distinct ints
        explicit Matrix2x2(int a1, int a2, int b1, int b2) : data { a1, a2, b1, b2 } {}
        // parameterized constructor using existing int array with size of 04
        explicit Matrix2x2(std::span<int> v) {
            if(v.size() != data.size()) {
                throw InvalidData("invalid input data buffer size");
            }
            std::copy(v.begin(), v.end(), data.begin());
        }
        // default copy construtors
        Matrix2x2(const Matrix2x2& other) = default;
        // default assigment operator
        Matrix2x2& operator=(const Matrix2x2& other) = default;
        // >> operator overloaded to read data from span
        Matrix2x2& operator<<(std::span<const int> v) {
            if(v.size() != data.size()) {
                throw InvalidData("invalid input data buffer size");
            }
            std::copy(v.begin(), v.end(), data.begin());
            return *this;
        }
        // << operator overloaded to write the data to span
        Matrix2x2& operator>>(std::span<int> v) {
            if(v.size() != data.size()) {
                throw InvalidData("out put data buffer size mis-match");
            }
            std::copy(data.begin(), data.end(), v.begin());
            return *this;
        }
};

void print_data(std::span<const int> data) {
    bool first_element = true;
    if(data.empty()) {
        std::cout << "empty!\n";
        return;
    }

    std::cout << "{";
    for(int value : data) {
        if(first_element) {     
            std::cout << value;
            first_element = false;
            continue;
        }
        std::cout << ", " << value;
    }
    std::cout << "}\n";
}

int main(void) {

    std::vector<Matrix2x2> vertices;
    std::array<int, 4> data = { 0 };
    int i = 0;

    try {
        while(std::cin >> data[i % 4]) {
            if(i && ((i + 1) % 4) == 0) {
                vertices.emplace_back(data);
            }
            i++;
        }

        std::cout << "user data sucessfully added <" << vertices.size() << "> objects created!\n";

        int special[4] = {95, 96, 97, 98};
        Matrix2x2 m(0, 0, 0, 0);
        m << special;
        vertices.push_back(m);
        std::cout << "special Matrix also sucessfully added <" << vertices.size() << "> objects created!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
        return EXIT_FAILURE;
    } catch(...) {
        std::cout << "unhandled exception occurred!\n";
        return EXIT_FAILURE;
    }

    std::cout << "printing all the matrices : \n";
    int output[4];
    for(auto& matrix : vertices) {
        matrix >> output;
        print_data(output);
    }
    return EXIT_SUCCESS;
}
