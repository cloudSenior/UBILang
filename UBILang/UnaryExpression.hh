#pragma once

#include "Expression.hh"



class UnaryExpression : public Expression
{
public:

    UnaryExpression(char operation, std::unique_ptr<Expression> expr)
    {
        this->expr = expr.get();
        this->operation = operation;
    }

    double eval() override
    {
        switch (operation) {

        case '-':
            return -expr->eval();
            
        case '+':
        default:
            return expr->eval();
            
        }
    }


private:
    Expression* expr;
    char operation;
};