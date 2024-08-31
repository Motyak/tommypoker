#ifndef CARDS_H
#define CARDS_H

#include <stdint.h>
#include <initializer_list>
#include <iostream>
#include <bitset>
#include <bit>
#include <numeric>

using Card = uint64_t; // any "Card" enum in {2^0, 2^1, ..., 2^51}

/*
* We are using 8 bytes to store both the set of cards (52 bits..
* ..for each card enum) and the set length (6 bits for up to 52).
* Chosen bytes format:
*
* length (bit 0-5)
*      |
*      | unused (bit 6-11)         actual set of cards (bit 12-63)
*      |      |                                 |
*    -----  -----   --------------------------------------------------------------
*   |     ||     | |                                                              |
*   XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX
*   0    4    8   12   16        24        32        40        48        56         (64)
*/
using Cards = uint64_t;

/* constants */
#define EMPTY_SET 0x0000'0000'0000'0000
#define FULL_SET 0xd00f'ffff'ffff'ffff

/* constructors/builders */
#define _CREATE_CARDS(length, set) (uint64_t(length) << 58 | (set))
#define Cards(set) _CREATE_CARDS(std::popcount(set), set)

/* selectors */
#define LENGTH(Cards) ((Cards) >> 58)
#define UNUSED(Cards) (((Cards) >> 52) & 0x3f)
#define SET(Cards) ((Cards) & 0xf'ffff'ffff'ffff) // 52 last bits <=> 13 last hex-digits

#define HAS_CARDS(_Cards, Cards) ((SET(_Cards) & SET(Cards)) == SET(Cards))
#define HAS_CARD HAS_CARDS

#define INTER(Cards_A, Cards_B) Cards(SET(Cards_A & Cards_B))
#define UNION(Cards_A, Cards_B) Cards(SET(Cards_A | Cards_B))
// A - B (non-commutative operation)
#define DIFF(Cards_A, Cards_B) Cards(SET(Cards_A) - SET(Cards_A & Cards_B))
// each set characteristics (commutative, as opposed to DIFF)
#define SYMDIFF(Cards_A, Cards_B) Cards(SET(Cards_A ^ Cards_B))

#define REMAINING(Cards) (Cards)
#define MISSING(Cards) _CREATE_CARDS(52 - LENGTH(Cards), SET(~Cards))

#define PRINT(Cards) (std::cout << std::bitset<64>{Cards} << std::endl)

#endif // CARDS_H
