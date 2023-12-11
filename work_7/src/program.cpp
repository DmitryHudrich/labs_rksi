#include "../program.h"

#include <fstream>
#include <filesystem>
#include <map>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <string>

namespace {
char findMostPopularSymbol(std::vector<std::string> strings) {
    std::map<char, int32_t> symbols;
    for (size_t i = 0; i < strings.size(); i++) {
        for (size_t j = 0; j < strings[i].size(); j++) {
            symbols[strings[i][j]]++;
        }
    }

    std::map<char, int>::iterator max_value =
        std::max_element(symbols.begin(), symbols.end(),
                         [](const std::pair<char, int>& a,
                            const std::pair<char, int>& b) -> bool {
                             return a.second < b.second;
                         });
    return max_value->first;
}

std::vector<std::string> findStringsWithChar(std::vector<std::string> strings,
                                             char c) {
    std::vector<std::string> output_strings;
    for (size_t i = 0; i < strings.size(); i++) {
        std::string current_string = strings[i];
        for (size_t j = 0; j < current_string.size(); j++) {
            if (current_string[j] == c) {
                output_strings.push_back(current_string);
                break;
            }
        }
    }

    return output_strings;
}

std::vector<std::string> readStrings(std::ifstream& file_stream) {
    std::vector<std::string> all_strings;
    std::string one_string;
    while (std::getline(file_stream, one_string)) {
        all_strings.push_back(one_string);
    }

    return all_strings;
}
} // namespace

Program::Program() {
    std::filesystem::path filePath(old_file_name);
    if (!std::filesystem::exists(filePath)) {
        throw std::ios_base::failure("File isn't exist.");
    }
}

Program::~Program() {
}

std::string Program::outputFileName() {
    return new_file_name;
}

void Program::outputFileName(std::string new_file_name) {
    this->new_file_name = new_file_name;
}

bool Program::createFile() {
    std::ifstream init_file_stream;
    std::ofstream write_stream;
    char most_popular_symbol;

    init_file_stream.open(old_file_name);
    if (!init_file_stream.is_open()) {
        return false;
    }

    std::vector<std::string> strings;
    strings = readStrings(init_file_stream);
    most_popular_symbol = findMostPopularSymbol(strings);
    strings = findStringsWithChar(strings, most_popular_symbol);

    write_stream.open(new_file_name);

    for (size_t i = 0; i < strings.size(); i++) {
        write_stream << strings[i] << '\n';
    }

    return true;
}