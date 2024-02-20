#pragma once

#include "BinaryExpression.hh"
#include "NumberValue.hh"
#include "StringValue.hh"

BinaryExpression::BinaryExpression(char operation, Expression* expr1, Expression* expr2)
{
    this->expr1 = std::move(expr1);

    this->expr2 = std::move(expr2);

    this->operation = operation;
}
 
Value* BinaryExpression::eval()
{
    Value* value1 = expr1->eval();
    Value* value2 = expr2->eval();

    if (typeid(*value1) == typeid(StringValue))
    {
        str string1 = value1->asString();

        switch (operation) 
        {
        case '*': 
        {
            size_t iteration = static_cast<size_t>(value2->asDouble());
            str buffer;

            for (size_t i = 0; i < iteration; ++i) 
            {
                buffer += string1;
            }

            return new StringValue(buffer);
        }

        case '+':
        default:
            return new StringValue(string1 + value2->asString());
        }
    }


    double number1 = value1->asDouble(), number2 = value2->asDouble();

    switch (operation) {

    case '-':
        return new NumberValue(number1 - number2);

    case '/':
        return new NumberValue(number1 / number2);

    case '*':
        return new NumberValue(number1 * number2);

    case '+':
    default:
        return new NumberValue(number1 + number2);
    }
}
