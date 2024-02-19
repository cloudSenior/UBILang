#pragma once


#include "Value.hh"


class NumberValue : public Value
{
public:
    NumberValue(double value)
    {
        this->value = value;
    }

    double asDouble() override 
    {
        return value;
    }

    str asString() override
    {
        return std::to_string(value);
    }

private:
    double value;
};