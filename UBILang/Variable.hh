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
    bool isExists(str key)
    {
        for (auto iter = variables.begin(); iter != variables.end(); ++iter)
            if (iter->first != key)
                return true;
        return false;
    }

    Value*get(str key)
    {
        if (!isExists(key)) 
        {
            throw "Variable not on regidit";
        }
        else
        {
            return variables.at(key);
        }

        return nullptr;
    }

    void set(str name, Value*value) 
    {
        variables[name] = value;
    }
};