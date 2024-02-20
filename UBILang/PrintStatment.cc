#pragma once
#include "PrintStatment.hh"

PrintStatment::PrintStatment(Expression* expression)
{
    this->expr = std::move(expression);
}

void PrintStatment::execute()
{
    if (expr != nullptr) {
        std::cout << expr->eval()->asString();
    }
}
