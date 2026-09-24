#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>

int main(void) {

    std::string str, result;
    std::getline(std::cin, str);

    size_t start = 0, end;

    do {

        start = str.find_first_not_of(' ', start);

        if(start == std::string::npos) {
            break;
        }

        end = str.find_first_of(' ', start);

        if(end == std::string::npos) {
            end = str.size();
        }
        
        std::string temp = str.substr(start, end - start);
        
        if(!result.empty()) {
            size_t it = result.find(temp);
            bool is_duplicate = false;

            while(it != std::string::npos) {
                bool left   = (it == 0 || result[it - 1] == ' ');
                bool right  = (it + temp.size() ==  result.size() || result[it + temp.size()] == ' ');

                if(left && right) {
                    is_duplicate = true;
                }

                it = result.find(temp, it + 1);
            }
            
            if(!is_duplicate) {
                result.push_back(' ');
                result.append(temp);
            }

        } else {
            result.append(temp);
        }

        start = end;

    } while (start < str.size());

    std::cout << "result : " << result << "\n";

    return EXIT_SUCCESS;
}
