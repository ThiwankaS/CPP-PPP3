#include <iostream>
#include <vector>
#include <string>
#include <string_view>

// Helper to trim whitespace (since your input has spaces after commas)
std::string trim(std::string_view str) {
    const auto strBegin = str.find_first_not_of(" \t\n\r");
    if (strBegin == std::string::npos) return ""; // Empty string

    const auto strEnd = str.find_last_not_of(" \t\n\r");
    const auto strRange = strEnd - strBegin + 1;

    return std::string(str.substr(strBegin, strRange));
}

std::vector<std::string> safe_split_json_objects(std::string_view input) {
    std::vector<std::string> result;
    int brace_depth = 0;
    bool in_quote = false;
    std::string current_buffer;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        // 1. Handle Quotes (Ignore braces/commas inside quotes)
        if (c == '"' && (i == 0 || input[i-1] != '\\')) {
            in_quote = !in_quote;
        }

        // 2. Handle Braces (Only if not inside quotes)
        if (!in_quote) {
            if (c == '{') brace_depth++;
            else if (c == '}') brace_depth--;
        }

        // 3. Split condition: Comma found, Not in quotes, Depth is 0
        if (c == ',' && !in_quote && brace_depth == 0) {
            // Push the accumulated string (trimmed)
            if (!current_buffer.empty()) {
                result.push_back(trim(current_buffer));
                current_buffer.clear();
            }
        } else {
            // Otherwise, keep adding to buffer
            current_buffer += c;
        }
    }

    // Don't forget the last chunk!
    if (!current_buffer.empty()) {
        result.push_back(trim(current_buffer));
    }

    return result;
}

int main() {
    // Your example string
    std::string raw = R"({ "key1" : "value1" }, { "key2" : "value2" }, { "key3" : "value3" })";

    // Edge case example: contains nested comma and spaces
    std::string complex = R"({ "a": [1, 2] }, { "b": "comma, inside, string" })";

    auto parts = safe_split_json_objects(complex);

    std::cout << "--- Result ---" << std::endl;
    for (const auto& part : parts) {
        std::cout << "Object: " << part << std::endl;
    }

    return 0;
}
