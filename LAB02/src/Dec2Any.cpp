#include "Dec2Any.h"
#include <string>
#include <algorithm>

namespace TaskThree
{
    auto Dec2Any::convertNegativeNumberToPositive(long long int value) const -> long long int
    {
        bool isNegative = (value < 0);
        if(isNegative)
            return value *= -1;
        return value;
    }

    auto Dec2Any::dec2Any(long long value, int base) -> std::string
    {
        if(base < 2 || base > 36)
            return "0";

//do funkcji to przenies!
        bool isNegative = (value < 0);
        if(isNegative)
            value *= -1;

        std::string output;

        do
        {
            char digit = value % base;

            if(digit < 10)
                digit += '0';
                // A-Z
            else
                digit = digit + 'A' - 10;

            output += digit;

            value /= base;

        } while (value > 0);

        if(isNegative)
            output += '-';

        std::reverse(output.begin(), output.end());
        return output;
    }
//    {
//        if(base < 2 or base > 36)
//            return "0";
////        convertNegativeNumberToPositive(value);
//        bool isNegative = (value < 0);
//        if (isNegative)
//            value *= -1;
//
//
//        std::string output = "";
//        do
//        {
//            char digit = value & base;
//            if(digit < 10)
//                digit += '0';
//            else
//                digit = digit + 'A' - 10;
//
//            output += digit;
//            value /= base;
//        } while (value > 0);
//
//        if(isNegative)
//            output += '-';
//
//        std::reverse(output.begin(),output.end());
//        return output;
//    }

} // namespace TaskThree