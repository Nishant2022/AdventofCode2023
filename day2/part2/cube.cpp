#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string, std::tuple, std::max;

auto minimum_set(string game) -> std::tuple<int, int, int>;

auto main() -> int {
    int power_total { 0 };

    // Go through each game
    while (cin.good()) {
        string line {};
        std::getline(cin, line);
        if (line.empty()) break;

        // Minimum variables
        int min_red { 0 }, min_green { 0 }, min_blue { 0 };

        // Get first pick
        auto begin = line.find(":") + 1;

        // Go through each pick and update minimum cubes needed
        while (begin != string::npos) {
            auto end = line.find(";", begin);
            if (end == string::npos) {
                auto [red, green, blue] = minimum_set(line.substr(begin));
                min_red = max(min_red, red);
                min_green = max(min_green, green);
                min_blue = max(min_blue, blue);
                begin = end;
            } else {
                auto [red, green, blue] = minimum_set(line.substr(begin, end - begin));
                min_red = max(min_red, red);
                min_green = max(min_green, green);
                min_blue = max(min_blue, blue);
                begin = end + 1;
            }
        }
        power_total += min_red * min_green * min_blue;
    }

    cout << "Sum of Power is " << power_total << std::endl;
}

auto minimum_set(string game) -> tuple<int, int, int> {
    std::stringstream sstream { game };
    int red { 0 }, green { 0 }, blue { 0 };
    int num { 0 };
    string color {};
    while (sstream >> num >> color) {
        if (color.find("red") != string::npos) red = num;
        if (color.find("green") != string::npos) green = num;
        if (color.find("blue") != string::npos) blue = num;
    }
    return { red, green, blue };
}
