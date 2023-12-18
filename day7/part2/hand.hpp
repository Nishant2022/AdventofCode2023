#ifndef HAND
#define HAND

#include <cstddef>
#include <string>
#include <unordered_map>

enum class HandValue { HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, FULL_HOUSE, FOUR_OF_A_KIND, FIVE_OF_A_KIND };

class HandComparitor;

class Hand {
    std::string _hand;
    int _bid;
    HandValue value;

public:
    Hand(const std::string& hand, int bid);

    auto get_bid() const -> int { return _bid; }
    friend HandComparitor;
};

class HandComparitor {
public:
    auto operator()(const Hand& lhs, const Hand& rhs) const -> bool;
};

#endif   // HAND
