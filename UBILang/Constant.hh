#pragma once
#include "defs.hh"

class {

private:
    const table<str, double> constants {
        { "PI", 3.1415926535 },
        { "GOLDEN_RATTION", 1.618 },
        { "E", 2.7182818284 }
    };

public:
    bool isExists(str key)
    {
        if (constants.find(key) != constants.end())
            return true;
        return false;
    }

    double get(str key)
    {
        if (!isExists(key))
            return 0;

       return constants.at(key);
    }
} Constant;