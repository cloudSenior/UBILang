#pragma once
#include "defs.hh"

#include "Value.hh"
#include "NumberValue.hh"
#include "StringValue.hh"

#include <map>

static std::map<str, Value*> variables {
    { "PI",             new NumberValue (3.1415926535) },
    { "GOLDEN_RATTION", new NumberValue (1.618) },
    { "E",              new NumberValue (2.7182818284) }
};




class Variable {
public:
    bool isExists(str key);

    Value* get(str key);

    void set(str name, Value* value);
};