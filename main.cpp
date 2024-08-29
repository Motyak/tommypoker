#include <Standard52CardDeckEnum.h>
#include <Cards.h>

#include <iostream>

int main()
{
    auto cards = CREATE_CARDS();
    auto has_ace_of_spades = HAS_CARD(cards, SPADES_1)? "true" : "false";
    std::cout << has_ace_of_spades << std::endl;

    return 0;
}
