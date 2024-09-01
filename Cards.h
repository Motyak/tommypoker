#ifndef CARDS_H
#define CARDS_H

#include <Standard52CardDeckEnum.h>

#include <cstdint>
#include <iostream>
#include <bitset>

using Card = uint64_t; // any "Card" enum in {2^0, 2^1, ..., 2^51}
                       // LENGTH(Card) should always be 1
using Cards = uint64_t; // a set of Card
 
/* constructors/builders */
#define Cards(set) (set)

/* operations */

#define REMAINING(Cards) (Cards)
#define MISSING(Cards) (~(Cards) & FULL_SET)
#define LENGTH(Cards) std::popcount(Cards)

#define INTER(Cards_A, Cards_B) ((Cards_A) & (Cards_B))
#define UNION(Cards_A, Cards_B) ((Cards_A) | (Cards_B))
// A - B (non-commutative operation)
#define DIFF(Cards_A, Cards_B) ((Cards_A) - ((Cards_A) & (Cards_B)))
// each set characteristics (commutative, as opposed to DIFF)
#define SYMDIFF(Cards_A, Cards_B) ((Cards_A) ^ (Cards_B))

#define HAS_CARDS(_Cards, Cards) (((_Cards) & (Cards)) == (Cards))
#define HAS_CARD HAS_CARDS
#define HAS_ANY_CARD INTER

/* debug procedures */
#define PRINT(Cards) (std::cout << std::bitset<52>{uint64_t(Cards)} << std::endl)

#endif // CARDS_H
