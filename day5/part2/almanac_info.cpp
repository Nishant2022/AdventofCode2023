#include "almanac_info.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto read_almanac_info(std::vector<AlmanacInfo>& almanac, std::string end_condition) -> void {
    std::string next {};
    long source {};
    long len {};
    std::cin >> next;   // Get rid of "map:"
    while (std::cin >> next && next != end_condition) {
        std::cin >> source >> len;
        almanac.emplace_back(std::stol(next), source, len);
    }

    std::sort(almanac.begin(), almanac.end(), AlmanacInfoComparitor());
}

auto index_almanac(const std::vector<AlmanacInfo>& almanac, long search) -> long {
    AlmanacInfo temp { 0, search, 0 };
    auto index = std::lower_bound(almanac.begin(), almanac.end(), temp, AlmanacInfoComparitor());
    if (index != almanac.end() && index->source() == search) return index->dest();
    if (index == almanac.begin()) return search;
    index--;
    if (index->source() + index->len() > search) return search - index->source() + index->dest();
    return search;
}
