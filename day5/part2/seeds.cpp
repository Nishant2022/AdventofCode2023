#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "almanac_info.hpp"

using std::cout, std::cin, std::string, std::vector, std::pair;

auto main() -> int {
    // List of seeds
    vector<pair<long, long>> seed_ranges {};

    // Get seeds
    string next {};
    cin >> next;   // Get rid of "seeds:"
    while (cin >> next && next != "seed-to-soil") {
        long range{};
        cin >> range;
        seed_ranges.emplace_back(std::stol(next), range);
    }

    // Almanac Info vectors
    vector<AlmanacInfo> seed_to_soil {};
    read_almanac_info(seed_to_soil, "soil-to-fertilizer");

    vector<AlmanacInfo> soil_to_fertilizer {};
    read_almanac_info(soil_to_fertilizer, "fertilizer-to-water");

    vector<AlmanacInfo> fertilizer_to_water {};
    read_almanac_info(fertilizer_to_water, "water-to-light");

    vector<AlmanacInfo> water_to_light {};
    read_almanac_info(water_to_light, "light-to-temperature");

    vector<AlmanacInfo> light_to_temperature {};
    read_almanac_info(light_to_temperature, "temperature-to-humidity");

    vector<AlmanacInfo> temperature_to_humidity {};
    read_almanac_info(temperature_to_humidity, "humidity-to-location");

    vector<AlmanacInfo> humidity_to_location {};
    read_almanac_info(humidity_to_location, "");

    long min_loc = std::numeric_limits<long>::max();
    for (auto range : seed_ranges) {
        cout << "Range: [" << range.first << ", " << range.first + range.second << ")" << std::endl;
        for (auto seed = range.first; seed < range.first + range.second; ++seed) {
            auto soil = index_almanac(seed_to_soil, seed);
            auto fertilizer = index_almanac(soil_to_fertilizer, soil);
            auto water = index_almanac(fertilizer_to_water, fertilizer);
            auto light = index_almanac(water_to_light, water);
            auto temp = index_almanac(light_to_temperature, light);
            auto humidity = index_almanac(temperature_to_humidity, temp);
            auto location = index_almanac(humidity_to_location, humidity);

            min_loc = std::min(location, min_loc);
        }
    }
    cout << "Lowest Location number is " << min_loc << std::endl;
}
