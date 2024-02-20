#pragma once




#include "Token.hh"

#include "Expression.hh"
#include "ValueExpression.hh"
#include "BinaryExpression.hh"
#include "UnaryExpression.hh"
#include "VariableExpression.hh"

#include "Statement.hh"
#include "PrintStatment.hh"
#include "IfStatement.hh"

#include "ConditionExpression.hh"

#include "Assigment.hpp"


class Parser
{
public:

    Parser(vec<Token> tokens);

    vec<Statement*> parse();

private:
    vec<Token> tokens;
    uint32 pos, size;
    Token EndOfFile = Token(TokenType::EXITSOPENFILE, "");

    Statement* statement();

    Statement* assigmentStatement();

    Statement* ifElse();


    Expression* expression();

    Expression* addtive();

    Expression* multi();

    Expression* unary();

    Expression* conditional();

    Expression* primary();
     
    Token consume(TokenType type);

    bool match(TokenType type);

    Token get(uint32 realativePosition);

};