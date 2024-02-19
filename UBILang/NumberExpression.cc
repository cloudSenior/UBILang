#pragma once

#include "NumberExpression.hh"



NumberExpression::NumberExpression(double value)
{
    this->value = value;
}


std::shared_ptr<Value> NumberExpression::eval()
{
    return std::make_shared<NumberValue>(value);
}