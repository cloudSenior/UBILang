#pragma once

#include "Expression.hh"
#include <memory>

class ConditionalExpression : public Expression {
public:
    ConditionalExpression(char operation, Expression* expr1, Expression* expr2);

    Value* eval() override;

private:
    Expression* expr1;
    Expression* expr2;

    char operation;
};