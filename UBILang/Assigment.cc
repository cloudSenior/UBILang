#pragma once
#include "Assigment.hpp"

Assigment::Assigment(str variable, Expression* expression)
{
    this->variable = variable;
    this->expression = std::move(expression);
}

void Assigment::execute() 
{
    Variable().set(variable, expression->eval());
}