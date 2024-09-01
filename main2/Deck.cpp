#include <Deck.h>

#include <random>
#include <bitset>
#include <ctime>

// remove and return random '1' bit from the set
static uint64_t randSetBit(std::bitset<52>* bitset) {
    static std::random_device rng;

    auto count = bitset->count();
    if (count == 0) {
        return uint64_t(0);
    }

    auto rand = std::uniform_int_distribution<int>(1, count);
    uint8_t i = 0;
    for(auto r = rand(rng); r != 0; ++i) {
        r -= (*bitset)[i];
    }

    (*bitset)[i - 1] = 0;
    return uint64_t(1) << (i - 1);
}

Cards draw(Cards* inputCards, int nb) {
    auto drawnCards = EMPTY_SET;
    auto bitset = std::bitset<52>{*inputCards};
    for (int i = 1; i <= nb; ++i) {
        drawnCards |= randSetBit(&bitset);
    }

    *inputCards = DIFF(*inputCards, drawnCards);
    return drawnCards;
}
