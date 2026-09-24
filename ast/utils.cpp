#include "AST.hpp"

std::string toLower(std::string line = std::string()) {
    std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){
        return (std::tolower(c));
    });
    return (line);
}

bool is_boolean(const std::string& line) {
    std::string str = toLower(line);
    return (str == "true" || str == "false" || str == "1" || str == "0");
}

bool is_number(const std::string& line) {
    return (
        std::regex_match(line, std::regex(R"([+-]?[0-9]+)"))
    );
}

bool is_type(Type& target, std::initializer_list<Type>options) {
    return (
        std::ranges::find(options, target) != options.end()
    );
}

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

// removing whitespoaces
[[nodiscard]]
std::string trim(std::string_view sv) {
    // return the first position of the not matching pattern
    const size_t start = sv.find_first_not_of(" \t\r\n");
    // if it is the last postion the string is empty
    if(start == std::string::npos) { return (""); }
    // return the first position of the not matching pattern
    const size_t end   = sv.find_last_not_of(" \t\r\n");
    // return the substring
    return (std::string(sv.substr(start, end - start + 1)));
}

[[nodiscard]]
std::vector<std::string> getValues(std::string_view sv, const char* set) {

    std::vector<std::string> values;
    std::string buffer;

    const size_t start  = sv.find_first_of(set[0]);
    if(start == std::string::npos) { return (values); }
    const size_t end    = sv.find_last_of(set[1]);

    std::string trimmed = std::string(sv.substr(start + 1, end - start - 1));

    int brace_depth = 0;
    bool in_quotes = false;
    for(size_t i = 0; i < trimmed.size(); ++i) {
        // iterating through the string char by char
        char c = trimmed[i];
        // set the flag in_quote if it is inside quote
        if(c == '"' && (i == 0 || trimmed[i -1] != '\\')) {
            in_quotes = !in_quotes;
        }
        // tracking the dept of the braces
        if(!in_quotes) {
            if(c == set[2])
                brace_depth++;
            else if (c == set[3])
                brace_depth--;
        }
        // if un quoted comma, strring split form here
        if(c == ',' && !in_quotes && brace_depth == 0) {
            if(!buffer.empty()) {
                values.push_back(trim(buffer));
                buffer.clear();
            }
        } else {
            buffer += c;
        }
    }
    // adding last part of the string
    if(!buffer.empty()) {
        values.push_back(buffer);
        buffer.clear();
    }
    return (values);
}
