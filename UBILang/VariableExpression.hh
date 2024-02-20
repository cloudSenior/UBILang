#pragma once

#include "Expression.hh"
#include "Variable.hh"
#include "Value.hh"
#include "defs.hh"


class VariableExpression : public Expression {
public:

    VariableExpression(str name)
    {
        this->name = name;
    }

    Value* eval() override
    {
        if (Variable().isExists(name)) 
        {
            return Variable().get(name);
        } 
        else 
        { 
            throw "No registation variable";
        }
    }

private:
    str name;
};