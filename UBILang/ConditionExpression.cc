#pragma once

#include "ConditionExpression.hh"
#include "NumberValue.hh"
#include "StringValue.hh"

ConditionalExpression::ConditionalExpression(char operation, Expression* expr1, Expression* expr2)
{
    this->expr1 = std::move(expr1);

    this->expr2 = std::move(expr2);

    this->operation = operation;
}

Value* ConditionalExpression::eval()
{
    Value* value1 = expr1->eval();
    Value* value2 = expr2->eval();

    if (typeid(*value1) == typeid(StringValue)) {
        str string1 = value1->asString();
        str string2 = value2->asString();

        switch (operation) {
        case '>':
            return new NumberValue(string1.compare(string2) > 0);

        case '<':
            return new NumberValue(string1.compare(string2) < 0);

        case '=':
        default:
            return new NumberValue(string1._Equal(string2));
        }
    }

    double number1 = value1->asDouble(), number2 = value2->asDouble();

    switch (operation) {
    case '>':
        return new NumberValue(number1 < number2);

    case '<':
        return new NumberValue(number1 > number2);

    case '=':
    default:
        return new NumberValue(number1 == number2);
    }
}
