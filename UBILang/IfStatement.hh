#pragma once

#include "Statement.hh"
#include "Expression.hh"

class IfStatement : public Statement
{
public:
    IfStatement(Expression* expression, Statement* ifStatement, Statement* elseStatement);

    void execute() override;


private: 
    Expression* expression;
    Statement* ifStatement;
    Statement* elseStatement;

};