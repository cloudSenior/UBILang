#pragma once

#include <iostream>

#include "Statement.hh"
#include "Expression.hh"


class PrintStatment : public Statement
{
public:
    PrintStatment(Expression* expression);
    void execute() override;

private:
    Expression* expr;
}; 