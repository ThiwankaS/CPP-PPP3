#include <iostream>
#include <vector>
#include <cstdlib>

template <typename T>
struct LoggingAllocator {
    // 1. Required type alias
    using value_type = T;

    LoggingAllocator() noexcept = default;

    // Standard requirement: Copy constructor for different types
    template <typename U>
    LoggingAllocator(const LoggingAllocator<U>&) noexcept {}

    // 2. Allocate uninitialized memory for 'n' objects of type T
    T* allocate(std::size_t n) {
        std::size_t bytes = n * sizeof(T);
        std::cout << "[Custom Allocator] Allocating " << bytes 
                  << " bytes (" << n << " element(s))\n";

        if (auto p = static_cast<T*>(std::malloc(bytes))) {
            return p;
        }
        throw std::bad_alloc();
    }

    // 3. Deallocate memory pointed to by 'p'
    void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "[Custom Allocator] Deallocating " 
                  << n * sizeof(T) << " bytes\n";
        std::free(p);
    }
};

// Allocators of the same type with no state are equal
template <typename T, typename U>
bool operator==(const LoggingAllocator<T>&, const LoggingAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const LoggingAllocator<T>&, const LoggingAllocator<U>&) { return false; }

int main() {
    // Pass your custom allocator type as the second template argument
    std::vector<int, LoggingAllocator<int>> myVec;

    std::cout << "--- Adding elements ---\n";
    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);

    std::cout << "--- Vector going out of scope ---\n";
    return 0;
}
