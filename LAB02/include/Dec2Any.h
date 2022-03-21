#pragma once

#include <string>

namespace TaskThree
{
    struct Dec2Any
    {
        auto convertNegativeNumberToPositive(long long int value) const -> long long int;

        auto dec2Any(long long value, int base) -> std::string;
    };
} // namespace TaskThree