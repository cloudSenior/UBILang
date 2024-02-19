#pragma once

#include "UnaryExpression.hh"
#include "NumberValue.hh"

UnaryExpression::UnaryExpression(char operation, std::shared_ptr<Expression> expr1)
{
    this->expr = std::move(expr1);

    this->operation = operation;
}

