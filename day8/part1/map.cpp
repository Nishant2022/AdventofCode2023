#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout, std::cin, std::string, std::unordered_map, std::pair;

auto main() -> int {
    // Read directions
    string directions {};
    cin >> directions;

    // Read map
    unordered_map<string, pair<string, string>> map{};
    string start {}, equal {}, left {}, right {};
    while (cin >> start >> equal >> left >> right) {
        left.pop_back();            // Remove comma
        left.erase(left.begin());   // Remove opening parenthesis
        right.pop_back();           // Remove closing parenthesis
        map.emplace(start, std::make_pair(left, right));
    }

    start = "AAA";
    int count = 0;
    while(true) {
        bool found = false;
        for (auto direction : directions) {
            if (start == "ZZZ") {
                found = true;
                break;
            }
            count++;
            auto [left_direction, right_direction] = map[start];
            if (direction == 'L') start = left_direction;
            else start = right_direction;
        }
        if (found) break;
    }

    cout << "Steps to reach ZZZ: " << count << std::endl;
}
