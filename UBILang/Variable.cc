#pragma once
#include "Variable.hh"

bool Variable::isExists(str key)
{
    for (auto iter = variables.begin(); iter != variables.end(); ++iter)
        if (iter->first != key)
            return true;
    return false;
}

Value* Variable::get(str key)
{
    if (!isExists(key)) {
        throw "Variable not on regidit";
    } else {
        return variables.at(key);
    }

    return nullptr;
}

void Variable::set(str name, Value* value)
{
    variables[name] = value;
}
