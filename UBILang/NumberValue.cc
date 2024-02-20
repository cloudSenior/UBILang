#pragma once
#include "NumberValue.hh"

NumberValue::NumberValue(double value)
{
    this->value = value;
}

double NumberValue::asDouble()
{
    return value;
}

str NumberValue::asString()
{
    return std::to_string(value);
}
