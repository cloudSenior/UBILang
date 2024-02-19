#pragma once

#include "Expression.hh"
#include <memory>


class BinaryExpression : public Expression {
public:

    BinaryExpression(char operation, std::shared_ptr<Expression> expr1, std::shared_ptr<Expression> expr2);

    std::shared_ptr<Value> eval() override;
    
private:
    std::shared_ptr<Expression> expr1;
    std::shared_ptr<Expression> expr2;

    char operation;
};