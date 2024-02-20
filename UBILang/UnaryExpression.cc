#pragma once

#include "UnaryExpression.hh"
#include "NumberValue.hh"

UnaryExpression::UnaryExpression(char operation, Expression* expr1)
{
    this->expr = std::move(expr1);

    this->operation = operation;
}

 