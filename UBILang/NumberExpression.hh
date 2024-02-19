#pragma once

#include "Expression.hh"
#include "Value.hh"
#include "NumberValue.hh"
#include <memory>


class NumberExpression : public Expression
{
public:

    NumberExpression(double value);

    std::shared_ptr<Value> eval() override;


private:
    double value;

};