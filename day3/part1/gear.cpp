#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string, std::vector;

auto is_number(char l) -> bool;
auto is_period(char l) -> bool;
auto is_symbol(char l) -> bool;

auto main() -> int {
    int total_part_num { 0 };

    vector<string> schematic {};

    // Read all input
    string line {};
    while (cin >> line) schematic.push_back(line);

    // Go through input and check for par numbers
    for (size_t i = 0; i < schematic.size(); ++i) {
        int num = 0;
        bool part_num = false;
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
                        part_num = part_num || is_symbol(schematic[i + k][j + l]);
                    }
                }
            } else {
                total_part_num += part_num ? num : 0;
                part_num = false;
                num = 0;
            }
        }
        total_part_num += part_num ? num : 0;
    }

    cout << "Total Part Number: " << total_part_num << std::endl;
}

auto is_number(char l) -> bool {
    return '0' <= l && l <= '9';
}

auto is_period(char l) -> bool {
    return l == '.';
}

auto is_symbol(char l) -> bool {
    return !is_period(l) && !is_number(l);
}
