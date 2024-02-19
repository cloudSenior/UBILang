#pragma once


#include "Parser.hh"


Parser::Parser(vec<Token> tokens)
{
    this->tokens = tokens;
    this->size = tokens.size();
    this->pos = 0;
}

vec<std::unique_ptr<Expression>> Parser::parse()
{
    vec<std::unique_ptr<Expression>> result {};

    while (!match(TokenType::EXITSOPENFILE)) {
        result.push_back(std::move(expression()));
    }

    return result;
}



std::unique_ptr<Expression> Parser::expression()
{
    return addtive();
}

std::unique_ptr<Expression> Parser::addtive()
{

    std::unique_ptr<Expression> Multi = std::move(multi());

    while (true) {
        if (match(TokenType::MINUS)) {
            Multi = std::make_unique<BinaryExpression>('-', std::move(Multi), multi());
            continue;
        }
        if (match(TokenType::PLUS)) {
            Multi = std::make_unique<BinaryExpression>('+', std::move(Multi), multi());
            continue;
        }
        break;
    }

    return Multi;
}

std::unique_ptr<Expression> Parser::multi()
{
    std::unique_ptr<Expression> Unary = std::move(unary());

    while (true) {
        if (match(TokenType::MULTI)) {
            Unary = std::make_unique<BinaryExpression>('*', std::move(Unary), unary());

            continue;
        }
        if (match(TokenType::DELITE)) {
            Unary = std::make_unique<BinaryExpression>('/', std::move(Unary), unary());

            continue;
        }
        break;
    }

    return Unary;
}

std::unique_ptr<Expression> Parser::unary()
{
    if (match(TokenType::MINUS)) {

        return std::make_unique<UnaryExpression>('-', primary());
    }
    if (match(TokenType::PLUS)) {
        return primary();
    }

    return primary();
}

std::unique_ptr<Expression> Parser::primary()
{
    Token current = get(0);

    if (match(TokenType::NUMBER)) {
        return std::make_unique<NumberExpression>(std::stod(current.getText()));
    }

    if (match(TokenType::LPAREN)) {
        std::unique_ptr<Expression> result = std::move(expression());
        match(TokenType::RPAREN);
        return result;
    }

    if (match(TokenType::WORD))
    {
        return std::make_unique<ConstExpression>(current.getText());
    }

    if (match(TokenType::HEX_NUMBER)) {
        return std::make_unique<NumberExpression>(std::stol(current.getText()));
    }
}

bool Parser::match(TokenType type)
{
    Token current = get(0);
    if (type != current.getType())
        return false;
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