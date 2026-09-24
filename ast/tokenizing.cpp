#include "AST.hpp"

[[nodiscard]]
std::string getFileContent(std::ifstream& file) {

    std::string line, output;
    int line_number = 0;

    output.clear();

    while(getline(file, line)) {
        ++line_number;

        size_t pos = line.find('#');

        if(pos != std::string::npos) {
            line = line.substr(0, pos);
        }

        line = trim(line);

        if(line.empty()) {
            continue;
        }
        output.append(line);
        line.clear();
    }

    return (output);
}

[[nodiscard]]
Token create_token(Type type, const std::string& value) {
    Token token;

    if(is_type(type , {
        Type::ConfigFile, Type::Identifier, Type::Value
    })) {
            token.type = type;
            token.value = value;
    }

    if(is_type(type, {
        Type::Array
    })) {
            token.type = type;
            if(value.size() > 2) {
                std::vector<std::string> values = getValues(value, "[]{}");
                for(auto it : values) {
                    token.children.push_back(create_token(getTokenType(it), it));
                }
            } else {
                token.value = value;
            }
    }

    if(is_type(type, {
        Type::Object
    })) {
            token.type = type;
            if(value.size() > 2) {
                std::vector<std::string> values = getValues(trim(value), "{}[]");
                for(auto it : values) {
                    token.children.push_back(create_token(getTokenType(it), it));
                }
            } else {
                token.value = value;
            }
    }

    if(is_type(type, {
        Type::Assignment
    })) {
            token.type = type;
            const size_t pos = value.find(':');
            if(pos != std::string::npos) {
                std::string left    = trim(value.substr(0, pos));
                std::string right   = trim(value.substr(pos + 1));
                token.children.push_back(create_token(Type::Identifier, left));
                token.children.push_back(create_token(getTokenType(right), right));
            }
    }

    return (token);
}

[[nodiscard]]
Type getTokenType(const std::string& line) {

    std::string str = trim(line);
    if(str.empty()) {
        return (Type::Unknown);
    }
    if(str[0] == '{' && str[str.size() - 1] == '}') {
        return (Type::Object);
    }
    if(str[0] == '[' && str[str.size() - 1] == ']') {
        return (Type::Array);
    }
    if(is_element(str)) {
        return (Type::Assignment);
    }
    if (str[0] == '"' && str[str.size() - 1] == '"') {
        return (Type::Value);
    }
    return (Type::Unknown);
}

[[nodiscard]]
Token getTokens(std::string& content) {
    Token root = create_token(Type::ConfigFile);
    if (content.size() <= 2) {
        throw std::runtime_error (
            "Syntax error : empty configuration file\n"
        );
    }

    std::string str = content.substr(1, content.size() - 2);

    size_t pos = str.find(":");
    if(pos == std::string::npos) {
        throw std::runtime_error (
            "Syntax error : expected ':'\n"
        );
    }

    std::string left    = trim(str.substr(0, pos));
    std::string right   = trim(str.substr(pos + 1));

    if(left.empty()) {
        throw std::runtime_error (
            "Syntax error : empty identifier before ':'\n"
        );
    }

    if(right.empty()) {
        throw std::runtime_error (
            "Syntax error : empty value after ':'\n"
        );
    }

    Token assignment = create_token(Type::Assignment);

    assignment.children.push_back(create_token(Type::Identifier, left));
    assignment.children.push_back(create_token(getTokenType(right), right));
    root.children.push_back(assignment);

    return (root);
}

// convert NokeKind value to a string
[[nodiscard]]
std::string conver_to_string(Type type) {
    switch (type)
    {
        case (Type::ConfigFile):
            return ("ConfigFile");
        case (Type::Assignment):
            return ("Assignment");
        case (Type::Identifier):
            return ("Identifier");
        case (Type::Array):
            return ("Array");
        case (Type::Object):
            return ("Object");
        case (Type::Value):
            return ("Value");
        default:
            return ("Unknown");
    }
}

// recursively print AST with indention
void print_token(const Token& root, int indent) {
    for(int i = 0; i < indent; ++i){
        std::cout << " ";
    }
    std::cout << conver_to_string(root.type);
    if(!root.value.empty()) {
        std::cout << "(" << root.value << ")";
    }
    std::cout << "\n";
    for(size_t i = 0; i < root.children.size();++i) {
        print_token(root.children[i], indent + 1);
    }
}
