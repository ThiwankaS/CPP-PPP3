#include "AST.hpp"

// helper function to create a node
[[nodiscard]]
ASTNode create_node(NodeKind kind, const std::string& value = std::string()) {
    ASTNode node;
    node.kind = kind;
    node.value = value;
    return (node);
}

// parse a line and create corresponding nodes
[[nodiscard]]
ASTNode parse_line(const std::string& line, int line_number) {
    size_t eq_pos = line.find("=");
    if(eq_pos == std::string::npos) {
        throw std::runtime_error (
            "Syntax error on line " + std::to_string(line_number)
            + " : expected '='\n"
        );
    }

    std::string left = trim(line.substr(0, eq_pos));
    std::string right = trim(line.substr(eq_pos + 1));

    if(left.empty()) {
        throw std::runtime_error (
            "Syntax error on line " + std::to_string(line_number)
            + " : empty identifier before '='\n"
        );
    }

    if(right.empty()) {
        throw std::runtime_error (
            "Syntax error on line " + std::to_string(line_number)
            + " : empty value after '='\n"
        );
    }

    ASTNode assignment = create_node(NodeKind::Assignment);
    assignment.children.push_back(create_node(NodeKind::Identifier, left));
    assignment.children.push_back(create_node(getNodeKind(right), right));
    return (assignment);
}

// convert NokeKind value to a string
[[nodiscard]]
std::string conver_to_string(NodeKind kind) {
    switch (kind)
    {
        case (NodeKind::ConfigFile):
            return ("ConfigFile");
        case (NodeKind::Assignment):
            return ("Assignment");
        case (NodeKind::Identifier):
            return ("Identifier");
        case (NodeKind::IntValue):
            return ("IntValue");
        case (NodeKind::BoolValue):
            return ("BoolValue");
        case (NodeKind::StringValue):
            return ("StringValue");
        default:
            return ("Unknown");
    }
}

// recursively print AST with indention
void print_ast(const ASTNode& root, int indent = 0){
    for(int i = 0; i < indent; ++i){
        std::cout << " ";
    }
    std::cout << conver_to_string(root.kind);
    if(!root.value.empty()) {
        std::cout << "(" << root.value << ")";
    }
    std::cout << "\n";
    for(size_t i = 0; i < root.children.size();++i) {
        print_ast(root.children[i], indent + 1);
    }
}


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

    std::string line;
    int line_number = 0;

    ASTNode root = create_node(NodeKind::ConfigFile);

    try
    {
        while(getline(file, line)) {
            ++line_number;
            size_t pos = line.find('#');
            if(pos != std::string::npos){
                line = line.substr(0, pos);
            }
            line = trim(line);
            if(line.empty()) {
                continue;
            }
            ASTNode assignment = parse_line(line, line_number);
            root.children.push_back(assignment);
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (EXIT_FAILURE);
    }

    print_ast(root);

    return (EXIT_SUCCESS);
}
