#include <Standard52CardDeckEnum.h>

#include <iostream>

int main()
{
    auto begin = Standard52CardDeckEnum::begin;
    auto end = Standard52CardDeckEnum::end;
    auto len = Standard52CardDeckEnum::len;

    std::cout << begin << std::endl;
    std::cout << end << std::endl;
    std::cout << len << std::endl;

    return 0;
}
