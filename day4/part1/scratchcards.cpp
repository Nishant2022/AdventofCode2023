#include <iostream>
#include <string>
#include <unordered_set>

using std::cout, std::cin, std::string, std::unordered_set;

auto main() -> int {
    int total_points {};

    string next {};

    // Get rid of first instance of "Card"
    cin >> next;
    while (cin >> next) {
        unordered_set<int> winning_numbers {};
        while (cin >> next) {
            if (next == "|") break;
            winning_numbers.insert(stoi(next));
        }

        int points = 0;
        while(cin >> next) {
            if (next == "Card") break;
            if (winning_numbers.find(stoi(next)) != winning_numbers.end()) {
                if (!points) points = 1;
                else points *= 2;
            }
        }

        total_points += points;
    }

    cout << "Total Points: " << total_points << std::endl;
}
