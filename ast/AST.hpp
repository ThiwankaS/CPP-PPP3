#pragma once

#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <initializer_list>
#include <regex>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

enum class Type {
    ConfigFile,
    Assignment,
    Identifier,
    Object,
    Array,
    Value,
    Unknown
};

struct Token {
    Type type;
    std::string value {};
    std::vector<Token>children;
};

bool is_boolean(const std::string& line);
bool is_number(const std::string& line);
bool is_element(std::string_view sv);
bool is_type(Type& target, std::initializer_list<Type>options);
std::string trim(std::string_view sv);
std::vector<std::string> getValues(std::string_view sv, const char* set);

std::string getFileContent(std::ifstream& file);
std::string conver_to_string(Type type);
Token getTokens(std::string& content);
Type getTokenType(const std::string& line);
Token create_token(Type type, const std::string& value = std::string());

void print_token(const Token& root, int indent = 0);
