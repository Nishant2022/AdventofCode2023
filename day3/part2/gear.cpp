#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string, std::vector, std::pair, std::unordered_map;

auto is_number(char l) -> bool;
auto is_gear(char l) -> bool;

auto hash_pair(pair<size_t, size_t> &key) -> size_t;

auto main() -> int {
    int total_part_num { 0 };

    vector<string> schematic {};
    unordered_map<size_t, vector<int>> gears; // Map to hold numbers next to gears

    // Read all input
    string line {};
    while (cin >> line) schematic.push_back(line);

    // Go through input and check for all numbers next to gears
    for (size_t i = 0; i < schematic.size(); ++i) {
        int num = 0;
        bool part_num = false;
        pair<size_t, size_t> gear_coords {};
        for (size_t j = 0; j < schematic[i].size(); ++j) {
            if (is_number(schematic[i][j])) {
                num *= 10;
                num += schematic[i][j] - '0';
                for (int k = -1; k < 2; ++k) {
                    for (int l = -1; l < 2; ++l) {
                        if (i == 0 && k == -1) break;
                        if (i == schematic.size() - 1 && k == 1) break;
                        if (j == 0 && l == -1) continue;
                        if (j == schematic[i].size() - 1 && l == 1) continue;
                        
                        // If the number is next to a gear, mark it
                        if (is_gear(schematic[i + k][j + l])) {
                            part_num = true;
                            gear_coords = { i + k, j + l };
                        }
                    }
                }
            } else {
                if (part_num) gears[hash_pair(gear_coords)].push_back(num);
                part_num = false;
                num = 0;
            }
        }
        if (part_num) gears[hash_pair(gear_coords)].push_back(num);
    }

    // Go through all gears with numbers next to them and only add part numbers from gears with two parts
    for (auto& gear_set : gears) {
        if (gear_set.second.size() == 2) {
            total_part_num += gear_set.second.front() * gear_set.second.back();
        }
    }

    cout << "Total Part Number: " << total_part_num << std::endl;
}

auto is_number(char l) -> bool {
    return '0' <= l && l <= '9';
}

auto is_gear(char l) -> bool {
    return l == '*';
}

// Hash function for pair of numbers
// Function found at:
// https://stackoverflow.com/questions/682438/hash-function-providing-unique-uint-from-an-integer-coordinate-pair
auto hash_pair(pair<size_t, size_t> &key) -> size_t {
    return (key.first + key.second) * (key.first + key.second + 1) / 2 + key.second;
}

