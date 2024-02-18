#pragma once




#include "Token.hh"
#include "Expression.hh"
#include "NumberExpression.hh"
#include "BinaryExpression.hh"
#include "UnaryExpression.hh"


class Parser
{
public:

    Parser(vec<Token> tokens)
    {
        this->tokens = tokens;
        this->size = tokens.size();
    }

    vec<std::unique_ptr<Expression>> parse()
    {
        vec<std::unique_ptr<Expression>> result {};

        while (!match(TokenType::EXITSOPENFILE))
        {
            result.push_back(std::move(expression()));
        }

        return result;
    }

private:
    vec<Token> tokens;
    uint32 pos, size;
    Token EndOfFile = Token(TokenType::EXITSOPENFILE, "");

    std::unique_ptr<Expression> expression()
    {
        return addtive();
    }

    std::unique_ptr<Expression> addtive()
    {
        
        std::unique_ptr<Expression> Multi = std::move(multi());
        
        while (true) 
        {
            if (match(TokenType::MINUS)) 
            {
                Multi = std::make_unique<BinaryExpression>('-', std::move(Multi), multi());
                continue;
            }
            if (match(TokenType::PLUS)) 
            {
                Multi = std::make_unique<BinaryExpression>('+', std::move(Multi), multi());
                continue;
            }
            break;
        }

        return Multi;
    }


    std::unique_ptr<Expression> multi()
    {
        std::unique_ptr<Expression> Unary = std::move(unary());
        
        while (true)
        {
            if (match(TokenType::MULTI))
            {
                Unary = std::make_unique<BinaryExpression>('*', std::move(Unary), unary());

                continue;
            }
            if (match(TokenType::DELITE)) 
            {
                Unary = std::make_unique<BinaryExpression>('/', std::move(Unary), unary());
                
                continue;
            }
            break;
        }
        
        return Unary;
    }

    std::unique_ptr<Expression> unary()
    {
        if (match(TokenType::MINUS)) 
        {

            return std::make_unique<UnaryExpression>('-', primary());

        }
        if (match(TokenType::PLUS)) 
        {
            return primary();
        }

        return primary();
    }

    std::unique_ptr<Expression> primary()
    {
        Token current = get(0);

        std::unique_ptr<Expression> pointer {nullptr};


        if (match(TokenType::NUMBER))
        {
            return std::make_unique<NumberExpression>(std::stod(current.getText()));
        }

        if (match(TokenType::LPAREN))
        {
            match(TokenType::RPAREN);
            return expression();
        }

        if (match(TokenType::HEX_NUMBER))
        { 
            return std::make_unique<NumberExpression>(std::stol(current.getText()));
        }

        
    } 

    bool match(TokenType type)
    {
        Token current = get(0);
        if (type != current.getType())
            return false;
        pos++;
        return true;
    }


    Token get(uint32 realativePosition)
    {
        uint32 nowPosition = pos + realativePosition;
        if (nowPosition >= size)
            return EndOfFile;
        return tokens.at(nowPosition);
    }

};