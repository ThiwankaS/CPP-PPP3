#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

constexpr auto generate_stairs_lookup() {
    std::array<uint64_t, 93> table {};
    table[1] = 1;
    table[2] = 2;

    for(size_t i = 3; i < 93; ++i) {
       table[i] = table[i - 1] + table[i - 2]; 
    }
    return table;
}

constexpr auto STAIRS_LOOKUP = generate_stairs_lookup();

[[nodiscard]] constexpr uint64_t climb_stairs_max_opt(int n) noexcept {
    return STAIRS_LOOKUP[n];
}

int pure_recursion(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    return pure_recursion(n - 1) + pure_recursion(n - 2);
}

int climb_stairs_dp_rec(std::unordered_map<int, int>& history, int n) {

    if(n == 1) return 1;
    if(n == 2) return 2;

    auto it = history.find(n);
    if(it != history.end()) {
        return it->second;
    }

    int result = climb_stairs_dp_rec(history, n - 1) + climb_stairs_dp_rec(history, n - 2);
    history.emplace(n, result);
    return result;
}

int climb_stairs_dp_loop_heap(int n) {

    if(n == 1) return 1;
    if(n == 2) return 2;

    std::vector<int> history (n + 1, 0);
    history[1] = 1;
    history[2] = 2;

    for(int i = 3; i < (n + 1); ++i) {
        history[i] = history[i - 1] + history[i - 2];
    }

    return history[n];
}

int climb_stairs_dp_loop_stack(std::span<int> history, int n) {

    if(n == 1) return 1;
    if(n == 2) return 2;

    history[1] = 1;
    history[2] = 2;

    for(int i = 3; i < (n + 1); ++i) {
        history[i] = history[i - 1] + history[i - 2];
    }

    return history[n];
}

int climb_stairs_dp_loop_two_int(int n) {
    
    if(n == 1) return 1;
    if(n == 2) return 2;

    int prev_n1 = 1, prev_n2 = 2, current = 0;

    for(int i = 3; i < (n + 1); ++i) {
        current = prev_n2 + prev_n1;
        prev_n1 = prev_n2;
        prev_n2 = current;
    }
    return current;
}

int main (void) {
    constexpr int size = 1024;
    int steps = 0;
    std::unordered_map<int, int> history_map;
    std::array<int, size> history_arr { 0 };

    std::cout << "Enter number of steps need to climb : ";
    std::cin >> steps;

    if(steps <= 0) {
        std::cerr << "You are excatly where you want to be!\n";
        return EXIT_FAILURE;
    }

    if(steps > size) {
        std::cerr << "Please use the elevator!\n";
        return EXIT_FAILURE;
    }

    // using pure recursion
    auto start1 = std::chrono::high_resolution_clock::now();
    int r1 = pure_recursion(steps);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d1 = end1 - start1;
   
    
    // using dynamic programming approcah - memoization
    auto start2 = std::chrono::high_resolution_clock::now();
    int r2 = climb_stairs_dp_rec(history_map, steps);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d2 = end2 - start2;


    // using dynamic programming approcah - tabulation <heap>
    auto start3 = std::chrono::high_resolution_clock::now();
    int r3 = climb_stairs_dp_loop_heap(steps);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d3 = end3 - start3;


    // using dynamic programming approcah - tabulation <stack>
    auto start4 = std::chrono::high_resolution_clock::now();
    int r4 = climb_stairs_dp_loop_stack(history_arr,  steps);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d4 = end4 - start4;

    // using dynamic programming approcah - tabulation <ints>
    auto start5 = std::chrono::high_resolution_clock::now();
    int r5 = climb_stairs_dp_loop_two_int(steps);
    auto end5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d5 = end5 - start5;

    // using compile time calculation 
    auto start6 = std::chrono::high_resolution_clock::now();
    int r6 = climb_stairs_max_opt(steps);
    auto end6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> d6 = end6 - start6;

    std::cout << " result <pure recursion>     : " << r1 << " | duration : " << d1.count() << " micro seconds." <<"\n";
    std::cout << " result <memoization>        : " << r2 << " | duration : " << d2.count() << " micro seconds." <<"\n";
    std::cout << " result <tabulation - heap>  : " << r3 << " | duration : " << d3.count() << " micro seconds." <<"\n";
    std::cout << " result <tabulation - stack> : " << r4 << " | duration : " << d4.count() << " micro seconds." <<"\n";
    std::cout << " result <tabulation - ints>  : " << r5 << " | duration : " << d5.count() << " micro seconds." <<"\n";
    std::cout << " result <compile time>       : " << r6 << " | duration : " << d6.count() << " micro seconds." <<"\n";

    return EXIT_SUCCESS;
}
