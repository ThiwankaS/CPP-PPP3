#include <iostream>
#include <vector>
#include <string>

/**
 * output will be similar to below
 * {null}
 * {3,}
 * {2,}
 * {2,3,}
 * {1,}
 * {1,3,}
 * {1,2,}
 * {1,2,3,}
*/

void determine_subset(
    const std::string& str,
    std::vector<std::string>& sub_sets,
    std::string seen,
    size_t index) {
        if(index == str.size()) {
            if(seen.empty()) {
                sub_sets.emplace_back("{null}");
            } else {
                sub_sets.emplace_back("{" + seen + "}");
            }
            return;
        }
        // compare current subset with next character
        determine_subset(str, sub_sets, seen, index + 1);
        // compare current subset + next character with, next character
        determine_subset(str, sub_sets, seen + str[index] + ",", index + 1);
}

int main(void) {
    std::string str = "123";
    std::vector<std::string>sub_sets;

    determine_subset(str, sub_sets, "", 0);

    for(auto it : sub_sets) {
        std::cout << it << "\n";
    }
    return (EXIT_SUCCESS);
}
