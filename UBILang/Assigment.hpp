#pragma once

#include <memory>

#include "defs.hh"

#include "Statement.hh"
#include "Expression.hh"
#include "VariableExpression.hh"


class Assigment : public Statement
{
public:

    Assigment(str variable, std::unique_ptr<Expression> expression)
    {
        this->variable = variable;
        this->expression = std::move(expression);
    }

    void execute() override
    {
        double result = expression->eval();
        Variable().set(variable, result);
    }

private:
    str variable;
    std::unique_ptr<Expression> expression;
};