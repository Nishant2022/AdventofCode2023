#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "almanac_info.hpp"

using std::cout, std::cin, std::string, std::vector;

auto main() -> int {
    // List of seeds
    vector<long> seeds {};

    // Get seeds
    string next {};
    cin >> next;   // Get rid of "seeds:"
    while (cin >> next && next != "seed-to-soil") {
        seeds.push_back(std::stol(next));
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

    vector<long> locations {};
    for (auto seed : seeds) {
        auto soil = index_almanac(seed_to_soil, seed);
        auto fertilizer = index_almanac(soil_to_fertilizer, soil);
        auto water = index_almanac(fertilizer_to_water, fertilizer);
        auto light = index_almanac(water_to_light, water);
        auto temp = index_almanac(light_to_temperature, light);
        auto humidity = index_almanac(temperature_to_humidity, temp);
        auto location = index_almanac(humidity_to_location, humidity);

        locations.push_back(location);
    }
    std::sort(locations.begin(), locations.end());
    cout << "Lowest Location number is " << locations.front() << std::endl;
}
