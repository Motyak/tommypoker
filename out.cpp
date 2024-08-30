#ifndef STANDARD_52_CARD_DECK_ENUM_H
#define STANDARD_52_CARD_DECK_ENUM_H

#include <stdint.h>

enum Standard52CardDeckEnum : uint8_t {
    begin = 0,

    CLUBS_1 =  0,
    CLUBS_2 =  1,
    CLUBS_3 =  2,
    CLUBS_4 =  3,
    CLUBS_5 =  4,
    CLUBS_6 =  5,
    CLUBS_7 =  6,
    CLUBS_8 =  7,
    CLUBS_9 =  8,
    CLUBS_10 = 9,
    CLUBS_J = 10,
    CLUBS_Q = 11,
    CLUBS_K = 12,

    DIAMONDS_1 =  0 + 13,
    DIAMONDS_2 =  1 + 13,
    DIAMONDS_3 =  2 + 13,
    DIAMONDS_4 =  3 + 13,
    DIAMONDS_5 =  4 + 13,
    DIAMONDS_6 =  5 + 13,
    DIAMONDS_7 =  6 + 13,
    DIAMONDS_8 =  7 + 13,
    DIAMONDS_9 =  8 + 13,
    DIAMONDS_10 = 9 + 13,
    DIAMONDS_J = 10 + 13,
    DIAMONDS_Q = 11 + 13,
    DIAMONDS_K = 12 + 13,

    HEARTS_1 =  0 + 26,
    HEARTS_2 =  1 + 26,
    HEARTS_3 =  2 + 26,
    HEARTS_4 =  3 + 26,
    HEARTS_5 =  4 + 26,
    HEARTS_6 =  5 + 26,
    HEARTS_7 =  6 + 26,
    HEARTS_8 =  7 + 26,
    HEARTS_9 =  8 + 26,
    HEARTS_10 = 9 + 26,
    HEARTS_J = 10 + 26,
    HEARTS_Q = 11 + 26,
    HEARTS_K = 12 + 26,

    SPADES_1 =  0 + 39,
    SPADES_2 =  1 + 39,
    SPADES_3 =  2 + 39,
    SPADES_4 =  3 + 39,
    SPADES_5 =  4 + 39,
    SPADES_6 =  5 + 39,
    SPADES_7 =  6 + 39,
    SPADES_8 =  7 + 39,
    SPADES_9 =  8 + 39,
    SPADES_10 = 9 + 39,
    SPADES_J = 10 + 39,
    SPADES_Q = 11 + 39,
    SPADES_K = 12 + 39,

    end,
    len = end,
}; // enum Standard52CardDeckEnum

#endif // STANDARD_52_CARD_DECK_ENUM_H

#ifndef CARDS_H
#define CARDS_H

#include <stdint.h>
#include <initializer_list>
#include <iostream>
#include <bitset>
#include <bit>
#include <numeric>

#endif // CARDS_H

// g++ --std=c++20 out.cpp -Wall -Wextra
int main()
{
    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = (0x340f'ffff'ffff'ffff);
        auto res = ((cards) & (uint64_t(1) << (CLUBS_1)))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = ({auto list = {HEARTS_1, SPADES_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto res = ((cards) & (uint64_t(1) << (CLUBS_1)))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = ({auto list = {HEARTS_1, SPADES_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & ((({auto list = {HEARTS_1, SPADES_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));})) & 0xf'ffff'ffff'ffff)) == ((({auto list = {HEARTS_1, SPADES_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));})) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = ({auto list = {HEARTS_1, SPADES_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & ((({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));})) & 0xf'ffff'ffff'ffff)) == ((({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));})) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = ({auto list = {HEARTS_1, CLUBS_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_B = ({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_C = (uint64_t(std::popcount(((cards_A & cards_B) & 0xf'ffff'ffff'ffff))) << 56 | (((cards_A & cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = ({auto list = {HEARTS_1, CLUBS_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_B = ({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_C = (uint64_t(std::popcount(((cards_A | cards_B) & 0xf'ffff'ffff'ffff))) << 56 | (((cards_A | cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = ({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_B = ({auto list = {HEARTS_1, CLUBS_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_C = (uint64_t(std::popcount(((cards_A) & 0xf'ffff'ffff'ffff) - ((cards_A & cards_B) & 0xf'ffff'ffff'ffff))) << 56 | (((cards_A) & 0xf'ffff'ffff'ffff) - ((cards_A & cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = ({auto list = {HEARTS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_B = ({auto list = {HEARTS_1, CLUBS_1, DIAMONDS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto cards_C = (uint64_t(std::popcount(((cards_A ^ cards_B) & 0xf'ffff'ffff'ffff))) << 56 | (((cards_A ^ cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "MISSING" << std::endl;
    {
        auto cards = ({auto list = {HEARTS_1, SPADES_1, DIAMONDS_1, CLUBS_1}; (uint64_t(list.size()) << 56 | (std::accumulate(list.begin(), list.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);})));});
        auto res = (uint64_t(52 - ((cards) >> 56)) << 56 | (((~cards) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{res} << std::endl);
    }
}
