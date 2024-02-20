#pragma once
#include "StringValue.hh"

StringValue::StringValue(str value)
{
    this->value = value;
}

double StringValue::asDouble()
{
    try {
        return std::stod(value.c_str());
    } catch (const std::exception& err) {
        return NULL;
    }
}

str StringValue::asString()
{
    return value;
}