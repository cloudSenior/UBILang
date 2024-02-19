#pragma once
#include <memory>


#include "Expression.hh"

#include "Value.hh"
#include "NumberValue.hh"


class UnaryExpression : public Expression
{
public:

    UnaryExpression(char operation, std::shared_ptr<Expression> expr);

    std::shared_ptr<Value> eval() override
    {
        switch (operation) {

        case '-':
            return std::make_shared<NumberValue>(-expr->eval()->asDouble());

        case '+':
        default:
            return std::make_shared<NumberValue>(expr->eval()->asDouble());
        }
    }

private:
    std::shared_ptr<Expression> expr;
    char operation;
};