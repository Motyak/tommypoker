
#include <stdint.h>

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
*   XXXX_XXXX XXXX_XXXX XXXX_XXXX XXXX_XXXX XXXX_XXXX XXXX_XXXX XXXX_XXXX XXXX_XXXX
*   0    4    8   12   16        24        32        40        48        56         (64)
*/
using Cards = uint64_t;

#define CREATE_CARDS() (0xffff'ffff'ffff'ffff)

#define LENGTH(Cards) (Cards >> 56)
#define UNUSED(Cards) ((Cards >> 52) & 0xf)
#define CARDS(Cards) (Cards & 0xf'ffff'ffff'ffff) // 52 last bits <=> 13 last hex-digits

#define HAS_CARD(_Cards, Card) (CARDS(_Cards) & Card)

// bool hasCard(Cards, Card);
// bool hasCards(Cards, Cards);

// Cards inter(Cards A, Cards B);
// Cards union_(Cards A, Cards B);
// Cards diff(Cards A, Cards B);
// Cards symdiff(Cards A, Cards B);

// Cards remaining(Cards);
// Cards missing(Cards);
