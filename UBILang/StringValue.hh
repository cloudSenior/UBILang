#pragma once

#include "Value.hh"

class StringValue : public Value {

public:

    StringValue(str value);

    double asDouble() override;

    str asString() override;

private:
    str value;
};