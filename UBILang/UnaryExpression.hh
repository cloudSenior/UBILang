#pragma once
#include <memory>


#include "Expression.hh"

#include "Value.hh"
#include "NumberValue.hh"


class UnaryExpression : public Expression
{
public:

    UnaryExpression(char operation, Expression* expr);

    Value* eval() override
    {
        switch (operation) {

        case '-':
            return new NumberValue(-expr->eval()->asDouble());

        case '+':
        default:
            return new NumberValue(expr->eval()->asDouble());
        }
    }
     
private:
    Expression* expr;
    char operation;
};