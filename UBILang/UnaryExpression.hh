#pragma once

#include "Expression.hh"
#include <memory>



class UnaryExpression : public Expression
{
public:

    UnaryExpression(char operation, std::unique_ptr<Expression> expr);

    double eval() override;

private:
    std::unique_ptr<Expression> expr;
    char operation;
};