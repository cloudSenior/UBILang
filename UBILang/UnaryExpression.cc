#pragma once

#include "UnaryExpression.hh"


UnaryExpression::UnaryExpression(char operation, std::unique_ptr<Expression> expr1)
{
    this->expr = std::move(expr1);
    this->operation = operation;
}

double UnaryExpression::eval()
{
    switch (operation) {

    case '-':
        return expr->eval() * -1;

    case '+':
    default:
        return expr->eval();
    }
}