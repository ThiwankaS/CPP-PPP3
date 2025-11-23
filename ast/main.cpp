#include "AST.hpp"

int main(int argc, char *argv[]){

    if(argc != 2) {
        std::cerr << "Incorrect uasge!\n";
        return (EXIT_FAILURE);
    }

    std::ifstream file(argv[1]);
    if(!file) {
        std::cerr << "File can not open!\n";
        return (EXIT_FAILURE);
    }

    std::string content = getFileContent(file);
    content = trim(content);
    Token root = getTokens(content);

    print_token(root);

    return (EXIT_SUCCESS);
}

