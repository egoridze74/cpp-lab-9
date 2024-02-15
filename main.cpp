#include <iostream>
#include "SampleCondition.h"
#include "Conditions.h"
#include <string>
#include <functional>

template <typename T>
size_t CountMatching(T *array, size_t array_size, const SampleCondition<T> &cond)
{
    size_t result = 0;
    for (size_t i = 0; i < array_size; ++i)
        if(cond(array[i]))
            ++result;
    return result;
}
//std::function usage

bool contains_letter_a(std::string elem)
{
    char letter = 'a';
    bool k = false;
    char second_letter = 'a' <= letter && letter <= 'z' ? letter + 'A' - 'a' : letter + 'a' - 'A';
    for (size_t i  = 0; i < elem.size(); ++i)
        if (elem.find(letter) != -1 or elem.find(second_letter) != -1)
        {
            k = true;
            break;
        }
    return k;
}

bool is_bigger_than_2005(int year)
{
    return year > 2005;
}

template <typename T>
size_t FuncCountMatching(T *array, size_t array_size, const std::function<bool(T)> &func)
{
    size_t result = 0;
    for (size_t i = 0; i < array_size; ++i)
        if(func(array[i]))
            ++result;
    return result;
}



int main() {
    int Ints[5] = {1, 22, 333, 4444, 55555};
    std::cout << "Number of even elements in Ints: "
              << CountMatching(Ints, 5, IsEven()) << std::endl;

    std::cout << "Number of odd elements in Ints: "
              << CountMatching(Ints, 5, IsOdd()) << std::endl;

    std::string Strings[5] = {"Amazing", "Breakfast", "Contrasting", "Disgusting", "Evening"};
    std::cout << "Number of strings containing chosen letter in Strings: "
              << CountMatching(Strings, 5, HasLetter('b')) << std::endl;

    bool Bools[5] = {true, true, true, false, true};
    std::cout << "Number of false elements in Bools: "
              << CountMatching(Bools, 5, IsFalse()) << std::endl;

    double Doubles[5] = {1.234, 2.341, 3.412, 4.123, 3.14};
    std::cout << "Number of elements bigger than Pi in Doubles: "
              << CountMatching(Doubles, 5, IsBiggerThanPi()) << std::endl;

    std::function<bool(int)> f1= is_bigger_than_2005;
    std::cout << "Using std::function. " << std::endl << "Number of elements bigger than 2005 in Ints: "
              << FuncCountMatching(Ints, 5, f1) << std::endl;

    std::function<bool(std::string)> f2 = contains_letter_a;
    std::cout << "Number of strings containing letter \"a\" in Strings: "
              << FuncCountMatching(Strings, 5, f2) << std::endl;

}
