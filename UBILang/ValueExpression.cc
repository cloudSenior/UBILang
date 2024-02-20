#pragma once

#include "ValueExpression.hh"

#include "StringValue.hh"

ValueExpression::ValueExpression(double value)
{
    this->value = new NumberValue(value);
}

ValueExpression::ValueExpression(str value)
{
    this->value = new StringValue(value);
}



Value* ValueExpression::eval()
{
    return value;
} 