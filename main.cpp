#include <Standard52CardDeckEnum.h>
#include <Cards.h>

int main()
{
    {
        auto cards = FULL_SET;
        auto has_ace_of_spades = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << has_ace_of_spades << std::endl;
    }

    {
        auto cards = createCards({HEARTS_1, SPADES_1, DIAMONDS_1});
        auto has_ace_of_spades = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << has_ace_of_spades << std::endl;
    }

    return 0;
}
