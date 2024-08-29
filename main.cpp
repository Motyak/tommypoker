#include <Standard52CardDeckEnum.h>
#include <Cards.h>

int main()
{
    {
        auto cards = FULL_SET;
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl;
    }

    {
        auto cards = createCards({HEARTS_1, SPADES_1, DIAMONDS_1});
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl;
    }

    {
        auto cards = createCards({HEARTS_1, SPADES_1, DIAMONDS_1});
        auto res = HAS_CARDS(cards, createCards({HEARTS_1, SPADES_1}))? "true" : "false";
        std::cout << res << std::endl;
    }

    {
        auto cards = createCards({HEARTS_1, SPADES_1, DIAMONDS_1});
        auto res = HAS_CARDS(cards, createCards({HEARTS_1, CLUBS_1}))? "true" : "false";
        std::cout << res << std::endl;
    }
}
