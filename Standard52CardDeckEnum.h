#ifndef STANDARD_52_CARD_DECK_ENUM_H
#define STANDARD_52_CARD_DECK_ENUM_H

#include <cstdint>

/// ENUMERATES ////////////////////////////////////////////////

#define CLUBS_1  (uint64_t(1) << ( 0))
#define CLUBS_2  (uint64_t(1) << ( 1))
#define CLUBS_3  (uint64_t(1) << ( 2))
#define CLUBS_4  (uint64_t(1) << ( 3))
#define CLUBS_5  (uint64_t(1) << ( 4))
#define CLUBS_6  (uint64_t(1) << ( 5))
#define CLUBS_7  (uint64_t(1) << ( 6))
#define CLUBS_8  (uint64_t(1) << ( 7))
#define CLUBS_9  (uint64_t(1) << ( 8))
#define CLUBS_10 (uint64_t(1) << ( 9))
#define CLUBS_J  (uint64_t(1) << (10))
#define CLUBS_Q  (uint64_t(1) << (11))
#define CLUBS_K  (uint64_t(1) << (12))

#define DIAMONDS_1  (uint64_t(1) << ( 0 + 13))
#define DIAMONDS_2  (uint64_t(1) << ( 1 + 13))
#define DIAMONDS_3  (uint64_t(1) << ( 2 + 13))
#define DIAMONDS_4  (uint64_t(1) << ( 3 + 13))
#define DIAMONDS_5  (uint64_t(1) << ( 4 + 13))
#define DIAMONDS_6  (uint64_t(1) << ( 5 + 13))
#define DIAMONDS_7  (uint64_t(1) << ( 6 + 13))
#define DIAMONDS_8  (uint64_t(1) << ( 7 + 13))
#define DIAMONDS_9  (uint64_t(1) << ( 8 + 13))
#define DIAMONDS_10 (uint64_t(1) << ( 9 + 13))
#define DIAMONDS_J  (uint64_t(1) << (10 + 13))
#define DIAMONDS_Q  (uint64_t(1) << (11 + 13))
#define DIAMONDS_K  (uint64_t(1) << (12 + 13))

#define HEARTS_1  (uint64_t(1) << ( 0 + 26))
#define HEARTS_2  (uint64_t(1) << ( 1 + 26))
#define HEARTS_3  (uint64_t(1) << ( 2 + 26))
#define HEARTS_4  (uint64_t(1) << ( 3 + 26))
#define HEARTS_5  (uint64_t(1) << ( 4 + 26))
#define HEARTS_6  (uint64_t(1) << ( 5 + 26))
#define HEARTS_7  (uint64_t(1) << ( 6 + 26))
#define HEARTS_8  (uint64_t(1) << ( 7 + 26))
#define HEARTS_9  (uint64_t(1) << ( 8 + 26))
#define HEARTS_10 (uint64_t(1) << ( 9 + 26))
#define HEARTS_J  (uint64_t(1) << (10 + 26))
#define HEARTS_Q  (uint64_t(1) << (11 + 26))
#define HEARTS_K  (uint64_t(1) << (12 + 26))

#define SPADES_1  (uint64_t(1) << ( 0 + 39))
#define SPADES_2  (uint64_t(1) << ( 1 + 39))
#define SPADES_3  (uint64_t(1) << ( 2 + 39))
#define SPADES_4  (uint64_t(1) << ( 3 + 39))
#define SPADES_5  (uint64_t(1) << ( 4 + 39))
#define SPADES_6  (uint64_t(1) << ( 5 + 39))
#define SPADES_7  (uint64_t(1) << ( 6 + 39))
#define SPADES_8  (uint64_t(1) << ( 7 + 39))
#define SPADES_9  (uint64_t(1) << ( 8 + 39))
#define SPADES_10 (uint64_t(1) << ( 9 + 39))
#define SPADES_J  (uint64_t(1) << (10 + 39))
#define SPADES_Q  (uint64_t(1) << (11 + 39))
#define SPADES_K  (uint64_t(1) << (12 + 39))

/// SUB-SET CONSTANTS /////////////////////////////////////////

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

#endif // STANDARD_52_CARD_DECK_ENUM_H
