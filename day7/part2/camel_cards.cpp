#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "hand.hpp"

using std::cout, std::cin, std::vector, std::string;

auto main() -> int {
    vector<Hand> hands {};
    string cards {};
    int bid { 0 };

    while (cin >> cards >> bid) hands.emplace_back(cards, bid);

    std::sort(hands.begin(), hands.end(), HandComparitor());

    size_t total_winnings { 0 };
    for (size_t i = 0; i < hands.size(); ++i) {
        total_winnings += hands[i].get_bid() * (i + 1);
    }

    cout << "Total winnings: " << total_winnings << std::endl;
}
