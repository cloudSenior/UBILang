#pragma once

#include "BinaryExpression.hh"
#include "NumberValue.hh"

BinaryExpression::BinaryExpression(char operation, Expression* expr1, Expression* expr2)
{
    this->expr1 = std::move(expr1);

    this->expr2 = std::move(expr2);

    this->operation = operation;
}
 
Value* BinaryExpression::eval()
{
    switch (operation) {

    case '+':
        return new NumberValue(expr1->eval()->asDouble() + expr2->eval()->asDouble());

    case '-':
        return new NumberValue(expr1->eval()->asDouble() - expr2->eval()->asDouble());

    case '/':
        return new NumberValue(expr1->eval()->asDouble() / expr2->eval()->asDouble());

    case '*':
        return new NumberValue(expr1->eval()->asDouble() * expr2->eval()->asDouble());

    default:
        return new NumberValue(expr1->eval()->asDouble() + expr2->eval()->asDouble());
    }
}
