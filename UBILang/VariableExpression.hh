#pragma once

#include "Expression.hh"
#include "Variable.hh"
#include "defs.hh"


class VariableExpression : public Expression {
public:

    VariableExpression(str name)
    {
        this->name = name;
    }

    double eval() override
    {
        if (!Variable().isExists(name)) 
        {
            throw "Is not const";
        }
        return Variable().get(name);
    }

private:
    str name;
};