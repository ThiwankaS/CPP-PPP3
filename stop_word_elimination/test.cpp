#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>

int main(void) {
    
    std::string stop_words;
    std::getline(std::cin, stop_words);

    std::string sentence;
    std::getline(std::cin, sentence);
   
    size_t start = 0, end;
    std::string result;

    while(start < sentence.size()) {
        
        start = sentence.find_first_not_of(' ', start);
        if(start == std::string::npos) {
            break;
        }

        end = sentence.find_first_of(' ', start);
        if(end == std::string::npos) {
            end = sentence.size();
        }

        std::string word = sentence.substr(start, end - start);
        std::cout << word << "\n";

        size_t it = stop_words.find(word);
        if(it == std::string::npos) {
            if(!result.empty())
                result.push_back(' ');
            result.append(word);
        }
        start = end;
    }

    std::cout << result << "\n";

    return EXIT_SUCCESS;
}
