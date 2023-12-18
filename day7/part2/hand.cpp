#include "hand.hpp"

#include <string>

auto get_card_value(char card) -> int;

Hand::Hand(const std::string& hand, int bid)
    : _hand(hand)
    , _bid(bid)
    , value(HandValue::HIGH_CARD) {
    // Get counts of all cards
    std::unordered_map<char, int> counts {};
    int num_jacks { 0 };
    for (char l : hand) {
        counts[l]++;
        if (l == 'J') num_jacks++;
    }

    // Go through each count
    for (auto count : counts) {
        // If the count is 5, it is a five of a kind
        if (count.second == 5) {
            value = HandValue::FIVE_OF_A_KIND;
            break;
        }
        // If the count is 4, it is a four of a kind
        if (count.second == 4) {
            value = HandValue::FOUR_OF_A_KIND;
            break;
        }

        // If the count is 3, it can be three of a kind or full house
        if (count.second == 3) {
            // Check for pair
            bool full_house = false;
            for (auto count2 : counts) {
                if (count2.first == count.first) continue;
                if (count2.second == 2) full_house = true;
            }
            // If pair found then full house, otherwise a three of a kind
            if (full_house) {
                value = HandValue::FULL_HOUSE;
                break;
            }
            value = HandValue::THREE_OF_A_KIND;
            break;
        }
        // If the count is 2, it can be full house, two pair, or one pair
        if (count.second == 2) {
            bool full_house = false;
            bool two_pair = false;
            // Check for either a three of a kind or another pair
            for (auto count2 : counts) {
                if (count2.first == count.first) continue;
                if (count2.second == 3) full_house = true;
                if (count2.second == 2) two_pair = true;
            }
            // If three of a kind foun, then full house
            if (full_house) {
                value = HandValue::FULL_HOUSE;
                break;
            } else if (two_pair) {   // If another pair found then two pair
                value = HandValue::TWO_PAIR;
                break;
            }
            // Otherwise one pair
            value = HandValue::ONE_PAIR;
            break;
        }
    }

    if (num_jacks) {
        switch (value) {
        case HandValue::HIGH_CARD:
            value = HandValue::ONE_PAIR;
            break;
        case HandValue::ONE_PAIR:
            value = HandValue::THREE_OF_A_KIND;
            break;
        case HandValue::TWO_PAIR:
            value = num_jacks == 2 ? HandValue::FOUR_OF_A_KIND : HandValue::FULL_HOUSE;
            break;
        case HandValue::THREE_OF_A_KIND:
            value = HandValue::FOUR_OF_A_KIND;
            break;
        case HandValue::FULL_HOUSE:
        case HandValue::FOUR_OF_A_KIND:
        case HandValue::FIVE_OF_A_KIND:
            value = HandValue::FIVE_OF_A_KIND;
            break;
        }
    }
}

auto HandComparitor::operator()(const Hand& lhs, const Hand& rhs) const -> bool {
    if (lhs.value != rhs.value) return lhs.value < rhs.value;
    for (size_t i = 0; i < lhs._hand.size(); ++i) {
        auto left_val = get_card_value(lhs._hand[i]);
        auto right_val = get_card_value(rhs._hand[i]);
        if (left_val != right_val) return left_val < right_val;
    }
    return false;
}

auto get_card_value(char card) -> int {
    switch (card) {
    case 'J':
        return 0;
    case '2':
        return 1;
    case '3':
        return 2;
    case '4':
        return 3;
    case '5':
        return 4;
    case '6':
        return 5;
    case '7':
        return 6;
    case '8':
        return 7;
    case '9':
        return 8;
    case 'T':
        return 9;
    case 'Q':
        return 10;
    case 'K':
        return 11;
    case 'A':
        return 12;
    }
    return -1;
}
