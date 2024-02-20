#pragma once

#include <memory>

#include "Value.hh"


class Expression
{
public:
    virtual Value* eval() = 0;
    virtual ~Expression() = default;
}; 