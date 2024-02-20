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

    Assigment(str variable, Expression* expression);

    void execute() override;

private:
    str variable;
    Expression* expression;
}; 