#include <Standard52CardDeckEnum.h>
#include <Cards.h>

// g++ --std=c++20 main.cpp -Wall -Wextra -I .
int main()
{
    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = FULL_SET;
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl; // true
    }
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl; // false
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1, SPADES_1))? "true" : "false";
        std::cout << res << std::endl; // true
    }
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1, CLUBS_1))? "true" : "false";
        std::cout << res << std::endl; // false
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1);
        auto cards_C = INTER(cards_A, cards_B);
        PRINT(cards_C); // 0000001000000000000000000000000000000100000000000000000000000001
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1);
        auto cards_C = UNION(cards_A, cards_B);
        PRINT(cards_C); // 0000001100000000000000000000000000000100000000000010000000000001
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_C = DIFF(cards_A, cards_B);
        PRINT(cards_C); // 0000000000000000000000000000000000000000000000000000000000000000
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1, CLUBS_1);
        auto cards_B = Cards(HEARTS_1, CLUBS_1, DIAMONDS_1);
        auto cards_C = SYMDIFF(cards_A, cards_B);
        PRINT(cards_C); // 0000000100000000000000000000000000000000000000000010000000000000
    }

    std::cout << "MISSING" << std::endl;
    {
        auto cards = Cards(HEARTS_1, SPADES_1, DIAMONDS_1, CLUBS_1);
        auto res = MISSING(cards);
        PRINT(res); // 0011000000001111111111110111111111111011111111111101111111111110
    }
}
