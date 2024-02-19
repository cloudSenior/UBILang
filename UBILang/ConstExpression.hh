#pragma once

#include "Expression.hh"
#include "Constant.hh"
#include "defs.hh"


class ConstExpression : public Expression
{
public:

    ConstExpression(str name)
    {
        this->name = name;
    }

    double eval() override
    {
        if (!Constant.isExists(name)) 
        {
            throw "Is not const";
        }
        return Constant.get(name);
    }

private:
    str name;
};