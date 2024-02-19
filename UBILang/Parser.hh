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

    vec<std::shared_ptr<Statement>> parse();

private:
    vec<Token> tokens;
    uint32 pos, size;
    Token EndOfFile = Token(TokenType::EXITSOPENFILE, "");

    std::shared_ptr<Statement> statement();

    std::shared_ptr<Statement> assigmentStatement();

    std::shared_ptr<Expression> expression();

    std::shared_ptr<Expression> addtive();

    std::shared_ptr<Expression> multi();

    std::shared_ptr<Expression> unary();

    std::shared_ptr<Expression> primary();

    Token consume(TokenType type);

    bool match(TokenType type);

    Token get(uint32 realativePosition);

};