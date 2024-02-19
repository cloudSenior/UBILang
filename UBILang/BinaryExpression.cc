#pragma once

#include "BinaryExpression.hh"


BinaryExpression::BinaryExpression(char operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2)
{
    this->expr1 = std::move(expr1);

    this->expr2 = std::move(expr2);

    this->operation = operation;
}

double BinaryExpression::eval()
{
    switch (operation) {

    case '+':
        return expr1->eval() + expr2->eval();

    case '-':
        return expr1->eval() - expr2->eval();

    case '/':
        return expr1->eval() / expr2->eval();

    case '*':
        return expr1->eval() * expr2->eval();

    default:
        return expr1->eval() + expr2->eval();
    }
}
