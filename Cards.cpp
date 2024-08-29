#include <Cards.h>

Cards _createCards(std::initializer_list<Card> cards) {
    auto length = cards.size();
    auto set = uint64_t(0);
    for (auto card: cards) {
        set |= uint64_t(1) << card;
    }
    return _CREATE_CARDS(length, set);
}
