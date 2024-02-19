#pragma once




class Statement
{
public:
    virtual void execute() = 0;
    virtual ~Statement() = default;
};