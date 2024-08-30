#include <Cards.h>

#include <numeric>

Cards _createCards(std::initializer_list<Card> cards) {
    auto length = cards.size();
    auto set = std::accumulate(cards.begin(), cards.end(), uint64_t(0), [](auto set, auto card){return set | (uint64_t(1) << card);});
    return _CREATE_CARDS(length, set);
}
