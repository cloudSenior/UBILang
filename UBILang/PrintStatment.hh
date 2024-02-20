#pragma once

#include <iostream>

#include "Statement.hh"
#include "Expression.hh"


class PrintStatment : public Statement
{
public:
    PrintStatment(Expression* expression)
    {
        this->expr = std::move(expression);
    }

    void execute() override
    {
        if (expr != nullptr) 
        {
            std::cout << expr->eval()->asString();
        }
    }

private:
    Expression* expr;
}; 