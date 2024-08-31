#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <numeric>

// g++ --std=c++20 out.cpp -Wall -Wextra
int main()
{
    std::cout << "HAS_CARD" << std::endl;
    {
        auto cards = 0xd00f'ffff'ffff'ffff;
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & (((uint64_t(1) << ( 0))) & 0xf'ffff'ffff'ffff)) == (((uint64_t(1) << ( 0))) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13))));
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & (((uint64_t(1) << ( 0))) & 0xf'ffff'ffff'ffff)) == (((uint64_t(1) << ( 0))) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "HAS_CARDS" << std::endl;
    {
        auto cards = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13))));
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & (((uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39))))) & 0xf'ffff'ffff'ffff)) == (((uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39))))) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }
    {
        auto cards = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13))));
        auto res = ((((cards) & 0xf'ffff'ffff'ffff) & (((uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))))) & 0xf'ffff'ffff'ffff)) == (((uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))))) & 0xf'ffff'ffff'ffff))? "true" : "false";
        std::cout << res << std::endl;
    }

    std::cout << "INTER" << std::endl;
    {
        auto cards_A = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13))));
        auto cards_B = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))));
        auto cards_C = (uint64_t(std::popcount(((cards_A & cards_B) & 0xf'ffff'ffff'ffff))) << 58 | (((cards_A & cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "UNION" << std::endl;
    {
        auto cards_A = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13))));
        auto cards_B = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))));
        auto cards_C = (uint64_t(std::popcount(((cards_A | cards_B) & 0xf'ffff'ffff'ffff))) << 58 | (((cards_A | cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "DIFF" << std::endl;
    {
        auto cards_A = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))));
        auto cards_B = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13))));
        auto cards_C = (uint64_t(std::popcount(((cards_A) & 0xf'ffff'ffff'ffff) - ((cards_A & cards_B) & 0xf'ffff'ffff'ffff))) << 58 | (((cards_A) & 0xf'ffff'ffff'ffff) - ((cards_A & cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "SYMDIFF" << std::endl;
    {
        auto cards_A = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0))));
        auto cards_B = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0)) | (uint64_t(1) << ( 0 + 13))));
        auto cards_C = (uint64_t(std::popcount(((cards_A ^ cards_B) & 0xf'ffff'ffff'ffff))) << 58 | (((cards_A ^ cards_B) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{cards_C} << std::endl);
    }

    std::cout << "MISSING" << std::endl;
    {
        auto cards = (uint64_t(std::popcount((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)) | (uint64_t(1) << ( 0)))) << 58 | ((uint64_t(1) << ( 0 + 26)) | (uint64_t(1) << ( 0 + 39)) | (uint64_t(1) << ( 0 + 13)) | (uint64_t(1) << ( 0))));
        auto res = (uint64_t(52 - ((cards) >> 58)) << 58 | (((~cards) & 0xf'ffff'ffff'ffff)));
        (std::cout << std::bitset<64>{res} << std::endl);
    }
}
