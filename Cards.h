
#include <stdint.h>
#include <initializer_list>
#include <iostream>
#include <bitset>
#include <bit>

using Card = uint8_t; // any "Card" enum which values lie between 0 and 51

/*
* We are using 8 bytes to store both the set of cards (52 bits..
* ..for each card enum) and the set length (8 bits for up to 52).
* Chosen bytes format:
*
* length (bit 0-7)
*       |
*       | unused (bit 8-11)        actual set of cards (bit 12-63)
*       |       |                               |
*    -------   --   --------------------------------------------------------------
*   |       | |  | |                                                              |
*   XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX XXXX'XXXX
*   0    4    8   12   16        24        32        40        48        56         (64)
*/
using Cards = uint64_t;

/* constants */
#define EMPTY_SET (0x0000'0000'0000'0000)
#define FULL_SET (0x340f'ffff'ffff'ffff)

/* constructors/builders */
#define _CREATE_CARDS(length, set) (uint64_t(length) << 56 | (set))
#define _CREATE_CARDS_v2(set) _CREATE_CARDS(std::popcount(set), set)
Cards _createCards(std::initializer_list<Card> cards);
#define Cards(...) _createCards({__VA_ARGS__})

/* selectors */
#define LENGTH(Cards) ((Cards) >> 56)
#define UNUSED(Cards) (((Cards) >> 52) & 0xf)
#define SET(Cards) ((Cards) & 0xf'ffff'ffff'ffff) // 52 last bits <=> 13 last hex-digits

#define HAS_CARD(_Cards, Card) (SET(_Cards) & (uint64_t(1) << (Card)))
#define HAS_CARDS(_Cards, Cards) ((SET(_Cards) & SET(Cards)) == SET(Cards))

#define INTER(Cards_A, Cards_B) _CREATE_CARDS_v2(SET(Cards_A) & SET(Cards_B))
#define UNION(Cards_A, Cards_B) _CREATE_CARDS_v2(SET(Cards_A) | SET(Cards_B))
// #define DIFF(Cards_A, Cards_B) 

// Cards inter(Cards A, Cards B);
// Cards union_(Cards A, Cards B);
// Cards diff(Cards A, Cards B);
// Cards symdiff(Cards A, Cards B);

// Cards remaining(Cards);
// Cards missing(Cards);

#define PRINT(Cards) (std::cout << std::bitset<64>{Cards} << std::endl)
