#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout, std::cin, std::string, std::vector;

auto main() -> int {
    long extrapolated_total { 0 };

    // Go through all lines
    string line {};
    std::getline(cin, line);
    while (line != "") {
        std::stringstream ss { line };
        vector<vector<int>> sequence { vector<int>() };

        // Get all numbers in line
        int val { 0 };
        while (ss >> val) sequence[0].push_back(val);

        // Resize sequence vector to be able to hold extrapolation
        sequence.resize(sequence[0].size());

        // Go through and find difference between each value
        // Once differences are all zero, we are done extrapolating
        int zero_row = 0;
        for (size_t i = 1; i < sequence.size(); ++i) {
            sequence[i].resize(sequence[i - 1].size() - 1);
            bool all_zeros = true;
            for (size_t j = 0; j < sequence[i].size(); ++j) {
                sequence[i][j] = sequence[i - 1][j + 1] - sequence[i - 1][j];
                all_zeros = all_zeros && !sequence[i][j];
            }
            if (all_zeros) {
                zero_row = static_cast<int>(i);
                break;
            }
        }

        // Add extrapolated data to total
        long extrapolated_val { 0 };
        for (; zero_row >= 0; --zero_row) {
            extrapolated_val = sequence[zero_row].front() - extrapolated_val;
        }
        extrapolated_total += extrapolated_val;

        // Get next line
        std::getline(cin, line);
    }

    cout << "Sum of extrapolated values: " << extrapolated_total << std::endl;
}
