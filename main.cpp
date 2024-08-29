#include <Standard52CardDeckEnum.h>
#include <Cards.h>

// g++ --std=c++20 main.cpp Cards.cpp -Wall -Wextra -I .
int main()
{
    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = FULL_SET;
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1, SPADES_1))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1, CLUBS_1))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1);
        auto cards_C = INTER(cards_A, cards_B);
        PRINT(cards_C);
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1);
        auto cards_C = UNION(cards_A, cards_B);
        PRINT(cards_C);
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_C = DIFF(cards_A, cards_B);
        PRINT(cards_C);
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_C = SYMDIFF(cards_A, cards_B);
        PRINT(cards_C);
    }

    std::cout << "MISSING" << std::endl;
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1, CLUBS_1);
        auto res = MISSING(cards);
        PRINT(res);
    }
}
