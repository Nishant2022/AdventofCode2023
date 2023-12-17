#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using std::size_t, std::cout, std::cin, std::string, std::vector;

auto main() -> int {
    string next {};
    cin >> next;   // Remove "Time:" string

    // Read times
    vector<int> times {};
    while (cin >> next && next != "Distance:") {
        times.push_back(std::stoi(next));
    }

    // Read distances
    vector<int> distances {};
    while (cin >> next) {
        distances.push_back(std::stoi(next));
    }

    // Go though each time
    int wins_multiplied = 1;
    for (size_t i = 0; i < times.size(); ++i) {
        int win_count = 0;

        // Distance traveled is symetrical over the middle hold time
        // so only search through half the hold times
        for (int hold_time = 1; hold_time <= times[i] / 2; ++hold_time) {
            if (hold_time * (times[i] - hold_time) > distances[i]) win_count++;
        }

        // Multiply count by two to account for only searching half
        win_count *= 2;

        // If the time was even, then we double count the middle time
        if (times[i] % 2 == 0 && (times[i] / 2) * (times[i] / 2) > distances[i]) win_count--;
        wins_multiplied *= win_count;
    }

    cout << "Number of possible wins multplied: " << wins_multiplied << std::endl;
}
