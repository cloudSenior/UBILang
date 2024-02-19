#pragma once

#include <memory>

#include "defs.hh"

#include "Statement.hh"
#include "Expression.hh"
#include "VariableExpression.hh"

#include "Value.hh"

class Assigment : public Statement
{
public:

    Assigment(str variable, std::shared_ptr<Expression> expression)
    {
        this->variable = variable;
        this->expression = std::move(expression);
    }

    void execute() override
    {
        Variable().set(variable, expression->eval().get());
    }

private:
    str variable;
    std::shared_ptr<Expression> expression;
};