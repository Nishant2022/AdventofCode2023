#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string;

constexpr int MAX_RED = 12;
constexpr int MAX_GREEN = 13;
constexpr int MAX_BLUE = 14;

auto is_valid_game(string game) -> bool;

auto main() -> int {
    int id_total { 0 };
    int id = 1;

    // Go through each game
    while (cin.good()) {
        string line {};
        std::getline(cin, line);
        if (line.empty()) break;

        // Get first pick
        auto begin = line.find(":") + 1;
        bool valid_games { true };

        // Go through each pick and check if it is valid
        while (begin != string::npos) {
            auto end = line.find(";", begin);
            if (end == string::npos) {
                valid_games = valid_games && is_valid_game(line.substr(begin));
                begin = end;
            } else {
                valid_games = valid_games && is_valid_game(line.substr(begin, end - begin));
                begin = end + 1;
            }
            if (!valid_games) break;
        }
        if (valid_games) id_total += id;
        ++id;
    }

    cout << "Sum of IDs is " << id_total << std::endl;
}

auto is_valid_game(string game) -> bool {
    std::stringstream sstream { game };
    int num { 0 };
    string color {};
    while (sstream >> num >> color) {
        if (color.find("red") != string::npos && num > MAX_RED) return false;
        if (color.find("green") != string::npos && num > MAX_GREEN) return false;
        if (color.find("blue") != string::npos && num > MAX_BLUE) return false;
    }
    return true;
}
