#ifndef CARDS_H
#define CARDS_H

#include <Standard52CardDeckEnum.h>

#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <bitset>
#include <bit>
#include <numeric>

using Card = uint64_t; // any "Card" enum in {2^0, 2^1, ..., 2^51}
                       // LENGTH(Card) should always be 1
using Cards = uint64_t; // a set of Card

/* constants */

#define EMPTY_SET 0
#define FULL_SET ((uint64_t(1) << 52) - 1)

#define ALL_CLUBS ((uint64_t(1) << 13) - 1)
#define ALL_DIAMONDS (ALL_CLUBS << 13)
#define ALL_HEARTS   (ALL_CLUBS << 26)
#define ALL_SPADES   (ALL_CLUBS << 39)

#define _ALL_4_OF(Card) (Card | (Card << 13) | (Card << 26) | (Card << 39))
#define ALL_1  _ALL_4_OF(CLUBS_1 )
#define ALL_2  _ALL_4_OF(CLUBS_2 )
#define ALL_3  _ALL_4_OF(CLUBS_3 )
#define ALL_4  _ALL_4_OF(CLUBS_4 )
#define ALL_5  _ALL_4_OF(CLUBS_5 )
#define ALL_6  _ALL_4_OF(CLUBS_6 )
#define ALL_7  _ALL_4_OF(CLUBS_7 )
#define ALL_8  _ALL_4_OF(CLUBS_8 )
#define ALL_9  _ALL_4_OF(CLUBS_9 )
#define ALL_10 _ALL_4_OF(CLUBS_10)
#define ALL_J  _ALL_4_OF(CLUBS_J )
#define ALL_Q  _ALL_4_OF(CLUBS_Q )
#define ALL_K  _ALL_4_OF(CLUBS_K )
 
/* constructors/builders */
#define Cards(set) (set)

/* operations */

#define REMAINING(Cards) (Cards)
#define MISSING(Cards) (~Cards & FULL_SET)
#define LENGTH(Cards) std::popcount(Cards)

#define INTER(Cards_A, Cards_B) (Cards_A & Cards_B)
#define UNION(Cards_A, Cards_B) (Cards_A | Cards_B)
// A - B (non-commutative operation)
#define DIFF(Cards_A, Cards_B) ((Cards_A) - (Cards_A & Cards_B))
// each set characteristics (commutative, as opposed to DIFF)
#define SYMDIFF(Cards_A, Cards_B) (Cards_A ^ Cards_B)

#define HAS_CARDS(_Cards, Cards) (((_Cards) & (Cards)) == (Cards))
#define HAS_CARD HAS_CARDS
#define HAS_ANY_CARD INTER

/* debug procedures */
#define PRINT(Cards) (std::cout << std::bitset<52>{Cards} << std::endl)

#endif // CARDS_H
