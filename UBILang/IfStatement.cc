#pragma once
#include "IfStatement.hh"

IfStatement::IfStatement(Expression* expression, Statement* ifStatement, Statement* elseStatement)
{
    this->expression = expression;
    this->ifStatement = ifStatement;
    this->elseStatement = elseStatement;
}

void IfStatement::execute() 
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
