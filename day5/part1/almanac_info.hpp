#ifndef ALMANAC_INFO
#define ALMANAC_INFO

#include <string>
#include <vector>

class AlmanacInfoComparitor;

class AlmanacInfo {
private:
    long destination_start;
    long source_start;
    long range_length;

public:
    AlmanacInfo(long dest, long source, long len)
        : destination_start(dest)
        , source_start(source)
        , range_length(len) {}

    auto dest() const -> long { return destination_start; }
    auto source() const -> long { return source_start; }
    auto len() const -> long { return range_length; }

    friend AlmanacInfoComparitor;
};

class AlmanacInfoComparitor {
public:
    auto operator()(const AlmanacInfo& lhs, const AlmanacInfo& rhs) const -> bool {
        return lhs.source_start < rhs.source_start;
    }
};

auto read_almanac_info(std::vector<AlmanacInfo>& almanac, std::string end_condition) -> void;
auto index_almanac(const std::vector<AlmanacInfo>& almanac, long search) -> long;

#endif   // ALMANAC_INFO
