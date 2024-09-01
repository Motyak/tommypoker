#include <Cards.h>

// g++ --std=c++20 main.cpp -Wall -Wextra -I .
int main()
{
    std::cout << "MISSING" << std::endl;
    {
        auto cards = ALL_1;
        auto res = MISSING(cards);
        PRINT(res); // 1111111111110111111111111011111111111101111111111110
    }

    std::cout << "LENGTH" << std::endl;
    {
        auto cards = ALL_1;
        auto res = LENGTH(cards);
        std::cout << res << std::endl; // 4
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1 | CLUBS_1 | DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1 | CLUBS_1);
        auto cards_C = INTER(cards_A, cards_B);
        PRINT(cards_C); // 0000000000000000000000000100000000000000000000000001
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1 | CLUBS_1 | DIAMONDS_1);
        auto cards_B = Cards(HEARTS_1 | CLUBS_1);
        auto cards_C = UNION(cards_A, cards_B);
        PRINT(cards_C); // 0000000000000000000000000100000000000010000000000001
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1 | CLUBS_1);
        auto cards_B = Cards(HEARTS_1 | CLUBS_1 | DIAMONDS_1);
        auto cards_C = DIFF(cards_A, cards_B);
        PRINT(cards_C); // 0000000000000000000000000000000000000000000000000000
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = Cards(HEARTS_1 | CLUBS_1);
        auto cards_B = Cards(HEARTS_1 | CLUBS_1 | DIAMONDS_1);
        auto cards_C = SYMDIFF(cards_A, cards_B);
        PRINT(cards_C); // 0000000000000000000000000000000000000010000000000000
    }

    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = FULL_SET;
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl; // true
    }
    {
        auto cards = Cards(HEARTS_1 | SPADES_1 | DIAMONDS_1);
        auto res = HAS_CARD(cards, CLUBS_1)? "true" : "false";
        std::cout << res << std::endl; // false
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = Cards(HEARTS_1 | SPADES_1 | DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1 | SPADES_1))? "true" : "false";
        std::cout << res << std::endl; // true
    }
    {
        auto cards = Cards(HEARTS_1 | SPADES_1 | DIAMONDS_1);
        auto res = HAS_CARDS(cards, Cards(HEARTS_1 | CLUBS_1))? "true" : "false";
        std::cout << res << std::endl; // false
    }

    std::cout << "HAS_ANY_CARD" << std::endl;
    {
        auto cards = Cards(HEARTS_1 | SPADES_1 | DIAMONDS_1);
        auto res = HAS_ANY_CARD(cards, ALL_HEARTS)? "true" : "false";
        std::cout << res << std::endl; // true
    }
    {
        auto cards = Cards(HEARTS_1 | SPADES_1 | DIAMONDS_1);
        auto res = HAS_ANY_CARD(cards, ALL_CLUBS)? "true" : "false";
        std::cout << res << std::endl; // false
    }
}
