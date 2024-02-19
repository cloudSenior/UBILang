#pragma once

#include "BinaryExpression.hh"
#include "NumberValue.hh"

BinaryExpression::BinaryExpression(char operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2)
{
    this->expr1 = std::move(expr1);

    this->expr2 = std::move(expr2);

    this->operation = operation;
}

std::shared_ptr<Value> BinaryExpression::eval()
{
    switch (operation) {

    case '+':
        return std::make_shared<NumberValue>(expr1->eval()->asDouble() + expr2->eval()->asDouble());

    case '-':
        return std::make_shared<NumberValue>(expr1->eval()->asDouble() - expr2->eval()->asDouble());

    case '/':
        return std::make_shared<NumberValue>(expr1->eval()->asDouble() / expr2->eval()->asDouble());

    case '*':
        return std::make_shared<NumberValue>(expr1->eval()->asDouble() * expr2->eval()->asDouble());

    default:
        return std::make_shared<NumberValue>(expr1->eval()->asDouble() + expr2->eval()->asDouble());
    }
}
