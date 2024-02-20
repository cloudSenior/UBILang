#pragma once

#include "VariableExpression.hh"

VariableExpression::VariableExpression(str name)
{
    this->name = name;
}

Value* VariableExpression::eval()
{
    if (Variable().isExists(name)) {
        return Variable().get(name);
    } else {
        throw "No registation variable";
    }
}
