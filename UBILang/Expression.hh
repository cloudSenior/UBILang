#pragma once

#include <memory>

#include "Value.hh"


class Expression
{
public:
    virtual std::shared_ptr<Value> eval() = 0;
    virtual ~Expression() = default;
};