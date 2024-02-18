#pragma once



class Expression
{
public:
    virtual double eval() = 0;
    virtual ~Expression() = default;
};