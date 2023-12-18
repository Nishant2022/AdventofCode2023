#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout, std::cin, std::string, std::unordered_map, std::pair, std::vector;

auto main() -> int {
    // Read directions
    string directions {};
    cin >> directions;

    // Read map
    unordered_map<string, pair<string, string>> map {};
    vector<string> starting_locations {};
    string start {}, equal {}, left {}, right {};
    while (cin >> start >> equal >> left >> right) {
        left.pop_back();            // Remove comma
        left.erase(left.begin());   // Remove opening parenthesis
        right.pop_back();           // Remove closing parenthesis
        map.emplace(start, std::make_pair(left, right));
        if (start.back() == 'A') starting_locations.push_back(start);
    }

    long least_multiple = 1;
    for (auto& start_loc : starting_locations) {
        long count = 0;
        while (true) {
            bool found = false;
            for (auto direction : directions) {
                if (start_loc.back() == 'Z') {
                    found = true;
                    break;
                }
                count++;
                auto [left_direction, right_direction] = map[start_loc];
                if (direction == 'L')
                    start_loc = left_direction;
                else
                    start_loc = right_direction;
            }
            if (found) break;
        }
        least_multiple = std::lcm(least_multiple, count);
    }

    cout << "Steps to simultaneously reach nodes that end with Z: " << least_multiple << std::endl;
}
