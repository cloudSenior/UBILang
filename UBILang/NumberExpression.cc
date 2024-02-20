#pragma once

#include "NumberExpression.hh"



NumberExpression::NumberExpression(double value)
{
    this->value = value;
}


Value* NumberExpression::eval()
{
    return new NumberValue(value);
} 