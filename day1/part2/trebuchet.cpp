#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string, std::vector, std::pair;

auto is_number(char l) -> bool;

auto main() -> int {
    const vector<pair<string, int>> number_words = {
        { "zero", 0},
        {  "one", 1},
        {  "two", 2},
        {"three", 3},
        { "four", 4},
        { "five", 5},
        {  "six", 6},
        {"seven", 7},
        {"eight", 8},
        { "nine", 9}
    };

    int total { 0 };
    string line {};
    while (cin >> line) {

        // Look through line for numbers
        vector<int> numbers {};
        size_t first_position { line.size() };
        size_t last_position { 0 };
        for (size_t i = 0; i < line.size(); ++i) {
            if (is_number(line[i])) {
                numbers.push_back(line[i] - '0');
                first_position = std::min(first_position, i);
                last_position = std::max(last_position, i);
            }
        }

        // Look through line for words
        size_t first_word_pos { line.size() };
        int first_word_val { 0 };
        size_t last_word_pos { 0 };
        int last_word_val { 0 };
        for (auto word : number_words) {
            auto first = line.find(word.first);
            if (first == string::npos) continue;
            auto last = line.rfind(word.first);

            if (first <= first_word_pos) {
                first_word_pos = first;
                first_word_val = word.second;
            }
            if (last >= last_word_pos) {
                last_word_pos = last;
                last_word_val = word.second;
            }
        }

        // Compare the position of the first number and first word
        if (first_word_pos < first_position) {
            total += first_word_val * 10;
        } else {
            total += numbers.front() * 10;
        }

        // Compare the position of the last number and last word
        if (last_word_pos > last_position) {
            total += last_word_val;
        } else {
            total += numbers.back();
        }
    }

    cout << "Sum of Calibration Values: " << total << std::endl;
}

auto is_number(char l) -> bool {
    return '0' <= l && l <= '9';
}
