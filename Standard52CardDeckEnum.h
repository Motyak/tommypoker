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
