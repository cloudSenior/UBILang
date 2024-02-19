#pragma once

#include "Expression.hh"

class NumberExpression : public Expression
{
public:

    NumberExpression(double value);

    double eval() override;


private:
    double value;

};