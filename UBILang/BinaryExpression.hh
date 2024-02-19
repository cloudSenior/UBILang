#pragma once

#include "Expression.hh"
#include <memory>


class BinaryExpression : public Expression {
public:

    BinaryExpression(char operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2);

    double eval() override;
    
private:
    std::unique_ptr<Expression> expr1;
    std::unique_ptr<Expression> expr2;

    char operation;
};