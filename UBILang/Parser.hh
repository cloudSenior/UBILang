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

    vec<std::unique_ptr<Statement>> parse();

private:
    vec<Token> tokens;
    uint32 pos, size;
    Token EndOfFile = Token(TokenType::EXITSOPENFILE, "");

    std::unique_ptr<Statement> statement();

    std::unique_ptr<Statement> assigmentStatement();

    std::unique_ptr<Expression> expression();

    std::unique_ptr<Expression> addtive();

    std::unique_ptr<Expression> multi();

    std::unique_ptr<Expression> unary();

    std::unique_ptr<Expression> primary();

    Token consume(TokenType type);

    bool match(TokenType type);

    Token get(uint32 realativePosition);

};