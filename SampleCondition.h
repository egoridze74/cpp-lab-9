//
// Created by Egor on 19.01.2024.
//

#ifndef CPP_LAB_9_CONDITION_TYPE_H
#define CPP_LAB_9_CONDITION_TYPE_H

template <typename T>
class SampleCondition
{
public:
    virtual bool operator()(T elem) const = 0;
};

#endif //CPP_LAB_9_CONDITION_TYPE_H
