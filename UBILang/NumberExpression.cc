#pragma once

#include "NumberExpression.hh"



NumberExpression::NumberExpression(double value)
{
    this->value = value;
}

double NumberExpression::eval() 
{
    return this->value;
}