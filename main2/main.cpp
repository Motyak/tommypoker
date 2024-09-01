#include <Cards.h>
#include <Deck.h>

// g++ Deck.cpp main.cpp --std=c++20 -Wall -Wextra -I . -I ..
int main()
{
    std::cout << "DRAW" << std::endl;
    {
        auto cards = FULL_SET;
        auto drawnCards = draw(&cards, 13);
        PRINT(cards);
        PRINT(drawnCards);
        std::cout << std::boolalpha 
                  << (LENGTH(drawnCards) == 13) << std::endl; // true
        if (HAS_ANY_CARD(drawnCards, ALL_1)) {
            std::cout << "you win" << std::endl;
        }
        else {
            std::cout << "you lose" << std::endl;
        }
    }
}
