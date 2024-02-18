#pragma once

#include "Expression.hh"


class BinaryExpression : public Expression {
public:

    BinaryExpression(char operation, std::unique_ptr<Expression> expr1, std::unique_ptr<Expression> expr2)
    {
        
        this->expr1 = std::move(expr1);
    
        this->expr2 = std::move(expr2);

        this->operation = operation;
 
    }

    double eval() override
    {
        switch (operation) {

        case '+':
            return expr1->eval() + expr2->eval();

        case '-':
            return expr1->eval() - expr2->eval();

        case '/':
            return expr1->eval() / expr2->eval();

        case '*':
            return expr1->eval() * expr2->eval();

        default:
            return expr1->eval() + expr2->eval();
        }
    }

    

private:
    std::unique_ptr<Expression> expr1;
    std::unique_ptr<Expression> expr2;

    char operation;
};