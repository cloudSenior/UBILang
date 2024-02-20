#pragma once

#include "defs.hh"

class Value
{
public:
    virtual double asDouble() = 0;
    virtual str asString() = 0;
    virtual ~Value() = default;
};
 