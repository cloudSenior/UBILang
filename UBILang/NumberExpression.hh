#pragma once

#include "Expression.hh"

class NumberExpression : public Expression
{
public:

    NumberExpression(double value)
    {
        this->value = value;
    }

    double eval() override
    {
        return this->value;
    }

private:
    double value;

};