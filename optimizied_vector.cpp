#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

static int created_default_count = 0;
static int created_int_count = 0;
static int copied_count = 0;
static int moved_count = 0;
static int allocation_count = 0;
static int destroyed_count = 0;

void* operator new(size_t size) {
    allocation_count++;
    std::cout << "allocated : " << size << " bytes \n";
    return malloc(size);
}

class Data {
    public: 
        int value;

        Data() : value(0) {
            created_default_count++;
        }

        Data(int x) : value(x) {
            created_int_count++;
        }

        Data(const Data& other) : value(other.value) {
            copied_count++;
        }

        Data(Data&& other) : value(std::move(other.value)) {
            moved_count++;
        }

        ~Data() {
            destroyed_count++;
        }
};

static void print_data(const std::vector<Data>& values) {
    if(values.size() == 0) {
        std::cout << "empty \n";
    }

    std::cout << "Elements { ";
    for(int i = 0; i < values.size(); ++i){
        std::cout << values[i].value << ", ";
    }
    std::cout << " }\n";
}

void Task(void) {
    std::vector<Data> values;
    values.reserve(20);

    for(int i = 0; i < 20; i++) {
        values.emplace_back(i + 1);
    }
    print_data(values);
}

int main(void) {

    Task();
    std::cout << "created <default> : " << created_default_count << "\n";
    std::cout << "created <int> : " << created_int_count << "\n";
    std::cout << "copied count : " << copied_count << "\n";
    std::cout << "moved count : " << moved_count << "\n";
    std::cout << "destroyed count : " << destroyed_count << "\n";  
    std::cout << "allocated count : " << allocation_count << "\n";
    return EXIT_SUCCESS;
}
