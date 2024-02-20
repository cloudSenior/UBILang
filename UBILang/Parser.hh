#pragma once




#include "Token.hh"

#include "Expression.hh"
#include "NumberExpression.hh"
#include "BinaryExpression.hh"
#include "UnaryExpression.hh"
#include "VariableExpression.hh"

#include "Assigment.hpp"
#include "Statement.hh"


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

    Expression* expression();

    Expression* addtive();

    Expression* multi();

    Expression* unary();

    Expression* primary();
     
    Token consume(TokenType type);

    bool match(TokenType type);

    Token get(uint32 realativePosition);

};