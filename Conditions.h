
#ifndef CPP_LAB_9_CONDITIONS_H
#define CPP_LAB_9_CONDITIONS_H
#define PI 3.1415926535897

#include "SampleCondition.h"
#include <string>

class IsEven : public SampleCondition<int>
{
public:
    IsEven() {}

    bool operator()(int elem) const
    {
        return elem % 2 == 0;
    }
};

class IsOdd : public SampleCondition<int>
{
public:
    IsOdd() {}

    bool operator()(int elem) const
    {
        return elem % 2 == 0;
    }
};

class HasLetterA : public SampleCondition<std::string>
{
public:
    HasLetterA() {}

    bool operator()(std::string elem) const
    {
        bool k = false;
        for (size_t i  = 0; i < elem.size(); ++i)
            if (elem.find("a") != -1 or elem.find("A") != -1)
            {
                k = true;
                break;
            }
        return k;
    }
};

class IsFalse : public SampleCondition<bool>
{
public:
    IsFalse() {}

    bool operator()(bool elem) const
    {
        return !elem;
    }
};

class IsBiggerThanPi : public SampleCondition<double>
{
public:
    IsBiggerThanPi() {}

    bool operator()(double elem) const
    {
        return elem > PI;
    }
};
#endif //CPP_LAB_9_CONDITIONS_H
