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

    std::shared_ptr<Value> eval() override
    {
        if (Variable().isExists(name)) 
        {
            return std::shared_ptr<Value>(Variable().get(name));
        } 
        else 
        {
            throw "No registation variable";
        }
    }

private:
    str name;
};