#pragma once


#include "Parser.hh"
#include "Statement.hh"
#include "PrintStatment.hh"


Parser::Parser(vec<Token> tokens)
{
    this->tokens = tokens;
    this->size = tokens.size();
    this->pos = 0;
}
 
vec<Statement*> Parser::parse()
{
    vec<Statement*> result {};

    while (!match(TokenType::EXITSOPENFILE)) {
        result.push_back(std::move(statement()));
    }

    return result;
}

Statement* Parser::statement()
{
    if (match(TokenType::PRINT))
    {
        auto copy = std::move(expression());
        return new PrintStatment(copy);
    } 
    else 
    {
        return assigmentStatement();
    }
}

Statement* Parser::assigmentStatement()
{
    Token current = get(0);

    if (match(TokenType::WORD) && get(0).getType() == TokenType::EQ)
    {
        str variable = current.getText();
        consume(TokenType::EQ);
        auto copy = std::move(expression());
        return new Assigment(variable, copy);
    }

}

Expression* Parser::expression()
{
    return addtive();
}

Expression* Parser::addtive()
{
    Expression* Multi = std::move(multi());
    while (true) {
        if (match(TokenType::MINUS)) {
            Multi = new BinaryExpression('-', std::move(Multi), multi());
            continue;
        }
        if (match(TokenType::PLUS)) {
            Multi = new BinaryExpression('+', std::move(Multi), multi());
            continue;
        }
        break;
    }

    return Multi;
}

Expression* Parser::multi()
{
    Expression* Unary = std::move(unary());

    while (true) {
        if (match(TokenType::MULTI)) {
            Unary = new BinaryExpression('*', std::move(Unary), unary());

            continue;
        }
        if (match(TokenType::DELITE)) {
            Unary = new BinaryExpression('/', std::move(Unary), unary());

            continue;
        }
        break;
    }

    return Unary;
}

Expression* Parser::unary()
{
    if (match(TokenType::MINUS)) {

        return new UnaryExpression('-', primary());
    }
    if (match(TokenType::PLUS)) {
        return primary();
    }

    return primary();
}

Expression* Parser::primary()
{
    Token current = get(0);

    if (match(TokenType::NUMBER)) {
        return new NumberExpression(std::stod(current.getText()));
    }

    if (match(TokenType::LPAREN)) {
        Expression* result = std::move(expression());
        match(TokenType::RPAREN);
        return result;
    }

    if (match(TokenType::WORD))
    {
        return new VariableExpression(current.getText());
    }

    if (match(TokenType::HEX_NUMBER)) {
        return new NumberExpression(std::stol(current.getText()));
    }
}


Token Parser::consume(TokenType type)
{
    Token current = get(0);
    if (type != current.getType()) {
        throw "Error";
    }
    this->pos++;
    return current;
}


bool Parser::match(TokenType type)
{
    Token current = get(0);
    if (type != current.getType()) {
        return false;
    }
    pos++;
    return true;
}

Token Parser::get(uint32 realativePosition)
{
    uint32 nowPosition = pos + realativePosition;
    if (nowPosition >= size)
        return EndOfFile;
    return tokens.at(nowPosition);
}