#pragma once

#include "Expression.hh"
#include "Value.hh"
#include "NumberValue.hh"
#include <memory>


class ValueExpression : public Expression
{
public:

    ValueExpression(double value);
    ValueExpression(str value);

    Value* eval() override;


private:
    Value* value;

}; 