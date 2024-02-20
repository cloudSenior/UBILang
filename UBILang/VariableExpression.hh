#pragma once

#include "Expression.hh"
#include "Variable.hh"
#include "Value.hh"
#include "defs.hh"


class VariableExpression : public Expression {
public:

    VariableExpression(str name);

    Value* eval() override;

private:
    str name;
};