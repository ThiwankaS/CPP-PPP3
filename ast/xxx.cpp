#include <iostream>
#include <string_view>
#include <string>
#include <vector>

bool is_element(std::string_view sv) {

    bool in_quote = false;

    for(size_t i = 0; i < sv.size(); ++i) {
        char c = sv[i];
        if(c == '"' && (i == 0 || sv[i - 1] != '\\')) {
            in_quote = !in_quote;
        }
        if(!in_quote && c == ':') {
            return (true);
        }
    }
    return (false);
}

int main(void) {
    std::string str = "\"server name\" : \"test.srever\"";

    std::cout << "str : " << str << "\n";

    if(is_element(str)) {
        std::cout << " is an element\n";
    }

    return (EXIT_SUCCESS);
}
