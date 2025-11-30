#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <sstream>

int main(void){
    std::vector<int> numbers = {
        10, 12, 13, 22, 24, 26, 11, 20, 17, 9
    };
    std::ranges::sort(numbers);

    auto results = numbers
                // filtering only odd numbers
                | std::views::filter([](int n) { return (n % 2 == 1); })
                // multiply all the numebrs by 3
                | std::views::transform([](int n) { return (n * 3); })
                // select only first two elements
                | std::views::take(2);

    std::ostringstream os;

    const char* seperator = "";

    for(auto it : results) {
        os << seperator << it;
        seperator = ", ";
    }
    std::cout << "{ " << os.str() << " }\n";
    return (EXIT_SUCCESS);
}
