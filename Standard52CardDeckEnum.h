#ifndef STANDARD_52_CARD_DECK_ENUM_H
#define STANDARD_52_CARD_DECK_ENUM_H

#include <stdint.h>

enum Standard52CardDeckEnum : uint64_t {
    begin = uint64_t(1) << 1,

    CLUBS_1  = uint64_t(1) << ( 0),
    CLUBS_2  = uint64_t(1) << ( 1),
    CLUBS_3  = uint64_t(1) << ( 2),
    CLUBS_4  = uint64_t(1) << ( 3),
    CLUBS_5  = uint64_t(1) << ( 4),
    CLUBS_6  = uint64_t(1) << ( 5),
    CLUBS_7  = uint64_t(1) << ( 6),
    CLUBS_8  = uint64_t(1) << ( 7),
    CLUBS_9  = uint64_t(1) << ( 8),
    CLUBS_10 = uint64_t(1) << ( 9),
    CLUBS_J  = uint64_t(1) << (10),
    CLUBS_Q  = uint64_t(1) << (11),
    CLUBS_K  = uint64_t(1) << (12),

    DIAMONDS_1  = uint64_t(1) << ( 0 + 13),
    DIAMONDS_2  = uint64_t(1) << ( 1 + 13),
    DIAMONDS_3  = uint64_t(1) << ( 2 + 13),
    DIAMONDS_4  = uint64_t(1) << ( 3 + 13),
    DIAMONDS_5  = uint64_t(1) << ( 4 + 13),
    DIAMONDS_6  = uint64_t(1) << ( 5 + 13),
    DIAMONDS_7  = uint64_t(1) << ( 6 + 13),
    DIAMONDS_8  = uint64_t(1) << ( 7 + 13),
    DIAMONDS_9  = uint64_t(1) << ( 8 + 13),
    DIAMONDS_10 = uint64_t(1) << ( 9 + 13),
    DIAMONDS_J  = uint64_t(1) << (10 + 13),
    DIAMONDS_Q  = uint64_t(1) << (11 + 13),
    DIAMONDS_K  = uint64_t(1) << (12 + 13),

    HEARTS_1  = uint64_t(1) << ( 0 + 26),
    HEARTS_2  = uint64_t(1) << ( 1 + 26),
    HEARTS_3  = uint64_t(1) << ( 2 + 26),
    HEARTS_4  = uint64_t(1) << ( 3 + 26),
    HEARTS_5  = uint64_t(1) << ( 4 + 26),
    HEARTS_6  = uint64_t(1) << ( 5 + 26),
    HEARTS_7  = uint64_t(1) << ( 6 + 26),
    HEARTS_8  = uint64_t(1) << ( 7 + 26),
    HEARTS_9  = uint64_t(1) << ( 8 + 26),
    HEARTS_10 = uint64_t(1) << ( 9 + 26),
    HEARTS_J  = uint64_t(1) << (10 + 26),
    HEARTS_Q  = uint64_t(1) << (11 + 26),
    HEARTS_K  = uint64_t(1) << (12 + 26),

    SPADES_1  = uint64_t(1) << ( 0 + 39),
    SPADES_2  = uint64_t(1) << ( 1 + 39),
    SPADES_3  = uint64_t(1) << ( 2 + 39),
    SPADES_4  = uint64_t(1) << ( 3 + 39),
    SPADES_5  = uint64_t(1) << ( 4 + 39),
    SPADES_6  = uint64_t(1) << ( 5 + 39),
    SPADES_7  = uint64_t(1) << ( 6 + 39),
    SPADES_8  = uint64_t(1) << ( 7 + 39),
    SPADES_9  = uint64_t(1) << ( 8 + 39),
    SPADES_10 = uint64_t(1) << ( 9 + 39),
    SPADES_J  = uint64_t(1) << (10 + 39),
    SPADES_Q  = uint64_t(1) << (11 + 39),
    SPADES_K  = uint64_t(1) << (12 + 39),

    end,
    len = end,
}; // enum Standard52CardDeckEnum

#endif // STANDARD_52_CARD_DECK_ENUM_H
