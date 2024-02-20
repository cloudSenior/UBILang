#pragma once
#include "Value.hh"


class NumberValue : public Value
{
public:
    NumberValue(double value);

    double asDouble() override;
    
    str asString() override;

private:
    double value;
};