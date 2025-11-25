#include "JSON.hpp"


Token get_tokens(std::string& str) {

    Token root = create_token(str);
    return (root);
}

int main(int argc, char *argv[]){
    if(argc != 2) {
        std::cerr << "Incorrect usage!\n";
    }
    std::ifstream file(argv[1]);
    if(!file) {
        std::cerr << "Can not open the file!\n";
    }

    std::string line;
    std::string output;

    while(getline(file, line)) {
        line = trim(line);

        if(line.empty()) { continue; }

        output.append(line);
        line.clear();
    }

    output = trim(output);

    Token root = get_tokens(output);
    print_token(root);
    return (EXIT_SUCCESS);
}
