#include "List.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

int main(void) {
    
    // ---- Test Suite 1: Fundamental Operations (Vectors) ----
    std::cout << "[Test 1: Core Operations]\n";
    std::vector<std::vector<int>> complex = {
        {91, 92, 93, 94, 95},
        {26, 27, 28, 29, 30},
        {11, 12, 13, 14, 15}
    };

    List<std::vector<int>> simple_list;
    std::cout << "initial size : " << simple_list.size() << "\n";

    simple_list.push_front(complex[1]);
    simple_list.push_front(complex[0]);

    std::cout << "peek front : " << simple_list.peek()[0] << "\n";
    auto temp = simple_list.pop_front(); 
    std::cout << "size after pop : " << simple_list.size() << "\n";
    
    // ---- Test Suite 2: Exception Handling (Edge Cases) ----
    std::cout << "[Test 2: Bounds Checking]\n";
    List<int> empty_list;
    
    try {
        empty_list.pop_front();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    // ---- Test Suite 3: Copy Constructor (Deep Copy Verification) ----
    std::cout << "[Test 3: Deep Copying]\n";
    List<std::string> original_strings;
    original_strings.push_front("C++");
    original_strings.push_front("Python");

    List<std::string> copied_strings(original_strings); // Trigger deep copy
    std::cout << "Original size: " << original_strings.size() 
              << ", Copied size: " << copied_strings.size() << "\n";
    
    // Modify copy to prove it doesn't hurt the original
    copied_strings.pop_front();
    std::cout << "After modifying copy - Original peek: " << original_strings.peek() 
              << ", Copied peek: " << copied_strings.peek() << "\n";

    // ---- Test Suite 4: Move Semantics (Resource Theft Verification) ----
    std::cout << "[Test 4: Move Semantics]\n";
    List<std::string> moved_strings(std::move(original_strings));
    std::cout << "Moved-to size: " << moved_strings.size() 
              << ", Moved-from empty: " << (original_strings.empty() ? "true" : "false") << "\n";

    return EXIT_SUCCESS;
}
