#pragma once
#include <string>
//dopisz zeby zmienialo litery na duze
namespace TaskThree
{
    struct Dec2Any
    {
        template<typename T>
        auto swap(T &a, T &b) -> void;

        auto reverseStr(std::string &str) -> void;

        static auto convertNegativeToPositive(long long int value) -> long long int;

        auto dec2Any(long long value, int base) -> std::string;
    };
} // namespace TaskThree