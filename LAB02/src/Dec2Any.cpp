#include "Dec2Any.h"

namespace TaskThree
{
    auto Dec2Any::convertNegativeToPositive(long long int value) -> long long int
    {
        if(value < 0)
        {
            value *= -1;
        }
        return value;
    }

    template<typename T>
    auto Dec2Any::swap(T &a, T &b) -> void
    {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    auto Dec2Any::reverseStr(std::string &str) -> void
    {
        int n = str.length();
        for(int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }

    auto Dec2Any::dec2Any(long long value, int base) -> std::string
    {
        //moze zrob include do any2dec bo uzywaja tego ifa i converta - todo
        if(base < 2 || base > 36)
            //CHANGE TO             throw std::out_of_range("Base cannot be less than 2 or more than thirtysix");
            return "0";

        value = convertNegativeToPositive(value);

        std::string output {};

        do
        {
            auto digit = value % base;

            if(digit < 10)
                digit += '0';
            else
                digit = digit + 'A' - 10;
            output += digit;
            value /= base;
        } while (value > 0);

        if(convertNegativeToPositive(value))
            output += '-';

        reverseStr(output);
        return output;
    }
} // namespace TaskThree