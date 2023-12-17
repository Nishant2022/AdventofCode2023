#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using std::size_t, std::cout, std::cin, std::string;

auto main() -> int {
    string next {};
    cin >> next;   // Remove "Time:" string

    // Read time
    string time_string {};
    while (cin >> next && next != "Distance:") {
        time_string += next;
    }
    long time { std::stol(time_string) };

    // Read distance
    string distance_string {};
    while (cin >> next) {
        distance_string += next;
    }
    long distance { std::stol(distance_string) };

    // Go though each time
    long win_count = 0;

    // Distance traveled is symetrical over the middle hold time
    // so only search through half the hold times
    for (long hold_time = 1; hold_time <= time / 2; ++hold_time) {
        if (hold_time * (time - hold_time) > distance) win_count++;
    }

    // Multiply count by two to account for only searching half
    win_count *= 2;

    // If the time was even, then we double count the middle time
    if (time % 2 == 0 && (time / 2) * (time / 2) > distance) win_count--;

    cout << "Number of possible wins: " << win_count << std::endl;
}
