#include "Any2Dec.h"
#include "Essentials.h"
#include <string_view>

namespace TaskFour
{
    auto Any2Dec::replaceNumberToChar(char c) -> int
    {
        if(c >= '0' && c <= '9')
            return static_cast<int>(c - '0');
        else
            return static_cast<int>(c - 'A' + 10);
    }

    auto Any2Dec::any2Dec(const char* str, int base) -> int
    {
        auto power = 1;
        int outputNumber = 0;

        if(base < 2 || base > 36)
        {
            throw std::out_of_range("Base cannot be less than 2 or more than thirtysix");
        }

        for(int i = strlen(str) - 1; i >= 0; --i)
        {
            //1.1 odnosnik na dole
            outputNumber += replaceNumberToChar(str[i]) * power;
            power *= base;
        }
        return outputNumber;
    }
} // namespace TaskFour
//DO U NEED THIS SHIT?
//1.1 //if(replaceNumberToChar(str[i]) >= base){return -1;}