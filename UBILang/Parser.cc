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

vec<std::shared_ptr<Statement>> Parser::parse()
{
    vec<std::shared_ptr<Statement>> result {};

    while (!match(TokenType::EXITSOPENFILE)) {
        result.push_back(std::move(statement()));
    }

    return result;
}

std::shared_ptr<Statement> Parser::statement()
{
    if (match(TokenType::PRINT))
    {
        auto copy = std::move(expression());
        return std::make_shared<PrintStatment>(copy);
    } 
    else 
    {
        return assigmentStatement();
    }
}

std::shared_ptr<Statement> Parser::assigmentStatement()
{
    Token current = get(0);

    if (match(TokenType::WORD) && get(0).getType() == TokenType::EQ)
    {
        str variable = current.getText();
        consume(TokenType::EQ);
        auto copy = std::move(expression());
        return std::make_shared<Assigment>(variable, copy);
    }

}

std::shared_ptr<Expression> Parser::expression()
{
    return addtive();
}

std::shared_ptr<Expression> Parser::addtive()
{
    std::shared_ptr<Expression> Multi = std::move(multi());
    while (true) {
        if (match(TokenType::MINUS)) {
            Multi = std::make_shared<BinaryExpression>('-', std::move(Multi), multi());
            continue;
        }
        if (match(TokenType::PLUS)) {
            Multi = std::make_shared<BinaryExpression>('+', std::move(Multi), multi());
            continue;
        }
        break;
    }

    return Multi;
}

std::shared_ptr<Expression> Parser::multi()
{
    std::shared_ptr<Expression> Unary = std::move(unary());

    while (true) {
        if (match(TokenType::MULTI)) {
            Unary = std::make_shared<BinaryExpression>('*', std::move(Unary), unary());

            continue;
        }
        if (match(TokenType::DELITE)) {
            Unary = std::make_shared<BinaryExpression>('/', std::move(Unary), unary());

            continue;
        }
        break;
    }

    return Unary;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match(TokenType::MINUS)) {

        return std::make_shared<UnaryExpression>('-', primary());
    }
    if (match(TokenType::PLUS)) {
        return primary();
    }

    return primary();
}

std::shared_ptr<Expression> Parser::primary()
{
    Token current = get(0);

    if (match(TokenType::NUMBER)) {
        return std::make_shared<NumberExpression>(std::stod(current.getText()));
    }

    if (match(TokenType::LPAREN)) {
        std::shared_ptr<Expression> result = std::move(expression());
        match(TokenType::RPAREN);
        return result;
    }

    if (match(TokenType::WORD))
    {
        return std::make_shared<VariableExpression>(current.getText());
    }

    if (match(TokenType::HEX_NUMBER)) {
        return std::make_shared<NumberExpression>(std::stol(current.getText()));
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