#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <typeinfo>
#include "BadFromString.h"

std::map<std::string, std::string> typeName;

template<class T>
T fromString(const std::string& input) {
    T result;
    std::istringstream reader (input);
    reader >> std::noskipws >> result;
    bool failed = reader.fail();
    char remainder;
    reader >> std::noskipws >> remainder;
    if (failed || !reader.eof()) {
        std::string message = "Failed to read a variable of type " + typeName[typeid(T).name()] + " for an input string '" + input + "'";
        throw BadFromString(message);
    }
    return result;
}

int main() {
    std::vector<std::string> strings = {"123", "12.3", "abc"};
    for (const auto &input : strings) {
        try {
            auto result = fromString<int>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<double>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<std::string>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<char>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<long>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<short>(input);
            std::cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
        try {
            auto result = fromString<bool>(input);
            std::cout << (result ? "true" : "false") << std::endl;
        } catch (BadFromString &badFromString) {
            std::cerr << badFromString.what() << std::endl;
        }
    }
    return 0;
}