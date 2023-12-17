#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::cout, std::cin, std::string, std::vector, std::unordered_set;

auto main() -> int {
    int total_copies {};
    vector<int> copies(300, 1);   // Should be enough to hold input plus buffer
    size_t card_id { 0 };

    string next {};

    // Get rid of first instance of "Card"
    cin >> next;
    while (cin >> next) {
        // Collect winning numbers
        unordered_set<int> winning_numbers {};
        while (cin >> next) {
            if (next == "|") break;
            winning_numbers.insert(stoi(next));
        }

        // Count winning numbers
        int count = 0;
        while (cin >> next) {
            if (next == "Card") break;
            if (winning_numbers.find(stoi(next)) != winning_numbers.end()) count++;
        }

        // Distribute copies
        for (auto i = card_id + 1; i <= card_id + count; ++i) {
            copies[i] += copies[card_id];
        }
        card_id++;
    }

    // Total copies
    for (size_t i = 0; i < card_id; ++i) {
        total_copies += copies[i];
    }

    cout << "Total Cards: " << total_copies << std::endl;
}
