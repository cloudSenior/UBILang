#pragma once

#include <iostream>

#include "Statement.hh"
#include "Expression.hh"


class PrintStatment : public Statement
{
public:
    PrintStatment(std::shared_ptr<Expression> expression)
    {
        this->expr = std::move(expression);
    }

    void execute() override
    {
        if (expr != nullptr) 
        {
            std::cout << (expr.get())->eval()->asString();
        }
    }

private:
    std::shared_ptr<Expression> expr;
};