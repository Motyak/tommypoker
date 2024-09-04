#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>

// g++ --std=c++20 out.cpp -Wall -Wextra
int main()
{
    std::cout << "MISSING" << std::endl;
    {
        auto cards = ((uint64_t(1) << ( 0)) | ((uint64_t(1) << ( 0)) << 13) | ((uint64_t(1) << ( 0)) << 26) | ((uint64_t(1) << ( 0)) << 39));
        auto res = (~(cards) & ((uint64_t(1) << 52) - 1));
        (std::cout << std::bitset<52>{uint64_t(res)} << std::endl);
    }

    std::cout << "LENGTH" << std::endl;
    {
        auto cards = ((uint64_t(1) << ( 0)) | ((uint64_t(1) << ( 0)) << 13) | ((uint64_t(1) << ( 0)) << 26) | ((uint64_t(1) << ( 0)) << 39));
        auto res = std::popcount(cards);
        std::cout << res << std::endl;
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)));
        auto cards_B = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)));
        auto cards_C = ((cards_A) & (cards_B));
        (std::cout << std::bitset<52>{uint64_t(cards_C)} << std::endl);
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)));
        auto cards_B = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)));
        auto cards_C = ((cards_A) | (cards_B));
        (std::cout << std::bitset<52>{uint64_t(cards_C)} << std::endl);
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)));
        auto cards_B = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)));
        auto cards_C = ((cards_A) - ((cards_A) & (cards_B)));
        (std::cout << std::bitset<52>{uint64_t(cards_C)} << std::endl);
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)));
        auto cards_B = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)));
        auto cards_C = ((cards_A) ^ (cards_B));
        (std::cout << std::bitset<52>{uint64_t(cards_C)} << std::endl);
    }

    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = ((uint64_t(1) << 52) - 1);
        auto res = (((cards) & ((uint64_t(1) << ( 0)))) == ((uint64_t(1) << ( 0))))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)));
        auto res = (((cards) & ((uint64_t(1) << ( 0)))) == ((uint64_t(1) << ( 0))))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)));
        auto res = (((cards) & (((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39))))) == (((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)))))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)));
        auto res = (((cards) & (((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))))) == (((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "HAS_ANY_CARD" << std::endl;
    {
        auto cards = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)));
        auto res = ((cards) & ((((uint64_t(1) << 13) - 1) << 26)))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)));
        auto res = ((cards) & (((uint64_t(1) << 13) - 1)))? "true" : "false";
        std::cout << res << std::endl;
    }
}
