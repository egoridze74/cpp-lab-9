#include <iostream>
#include "SampleCondition.h"
#include "Conditions.h"
#include <string>

template <typename T>
size_t CountMatching(T *array, size_t array_size, const SampleCondition<T> &cond)
{
    size_t result = 0;
    for (size_t i = 0; i < array_size; ++i)
        if(cond(array[i]))
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
    std::cout << "Number of strings containing letter a in Strings: "
              << CountMatching(Strings, 5, HasLetterA()) << std::endl;

    bool Bools[5] = {true, true, true, false, true};
    std::cout << "Number of false elements in Bools: "
              << CountMatching(Bools, 5, IsFalse()) << std::endl;

    double Doubles[5] = {1.234, 2.341, 3.412, 4.123, 3.14};
    std::cout << "Number of elements bigger than Pi in Doubles: "
              << CountMatching(Doubles, 5, IsBiggerThanPi()) << std::endl;

}
