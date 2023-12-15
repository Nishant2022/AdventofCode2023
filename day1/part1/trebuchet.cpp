#include <iostream>
#include <string>
#include <vector>

using std::cout, std::cin, std::string, std::vector;

auto is_number(char l) -> bool;

auto main() -> int {
    int total { 0 };
    string line {};
    while (cin >> line) {
        vector<int> numbers {};
        for (auto l : line) {
            if (is_number(l)) numbers.push_back(l - '0');
        }
        total += numbers.front() * 10 + numbers.back();
    }
    cout << "Sum of Calibration Values: " << total << std::endl;
}

auto is_number(char l) -> bool {
    return '0' <= l && l <= '9';
}
