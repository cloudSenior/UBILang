#pragma once




#include "Token.hh"

#include "Expression.hh"
#include "NumberExpression.hh"
#include "BinaryExpression.hh"
#include "UnaryExpression.hh"
#include "ConstExpression.hh"


class Parser
{
public:

    Parser(vec<Token> tokens);

    vec<std::unique_ptr<Expression>> parse();

private:
    vec<Token> tokens;
    uint32 pos, size;
    Token EndOfFile = Token(TokenType::EXITSOPENFILE, "");

    std::unique_ptr<Expression> expression();

    std::unique_ptr<Expression> addtive();

    std::unique_ptr<Expression> multi();

    std::unique_ptr<Expression> unary();

    std::unique_ptr<Expression> primary();

    bool match(TokenType type);

    Token get(uint32 realativePosition);

};