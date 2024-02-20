#pragma once

#include "Statement.hh"
#include "Expression.hh"

class IfStatement : public Statement
{
public:
    IfStatement(Expression* expression, Statement* ifStatement, Statement* elseStatement)
    {
        this->expression = expression;
        this->ifStatement = ifStatement;
        this->elseStatement = elseStatement;
    }

    void execute() override
    {
        double result = expression->eval()->asDouble();
        if (result != 0)
        {
            ifStatement->execute();
        } 
        else if (elseStatement != nullptr)
        {
            elseStatement->execute();
        }
    }


private: 
    Expression* expression;
    Statement* ifStatement;
    Statement* elseStatement;

};