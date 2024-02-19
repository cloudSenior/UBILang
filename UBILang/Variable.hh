#pragma once
#include "defs.hh"

class Variable {

private:
    table<str, double> variables {
        { "PI", 3.1415926535 },
        { "GOLDEN_RATTION", 1.618 },
        { "E", 2.7182818284 }
    };

public:
    bool isExists(str key)
    {
        if (variables.find(key) != variables.end())
            return true;
        return false;
    }

    double get(str key)
    {
        if (!isExists(key))
            return 0;

       return variables.at(key);
    }

    void set(str name, double value)
    {
       variables.emplace(name, value);
    }
};