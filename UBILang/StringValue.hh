#pragma once

#include "Value.hh"

class StringValue : public Value {

public:

    StringValue(str value)
    {
        this->value = value;
    }

    double asDouble() override
    {
        try 
        {
            return std::stod(value.c_str());
        }  
        catch (const std::exception& err) 
        { 
            return NULL;
        }
        
    }

    str asString() override
    {
        return value;
    }

private:
    str value;
};