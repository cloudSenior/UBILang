#pragma once

#include "defs.hh"
#include "TokenType.hh"


class Token
{
public:
    
    Token() = default;

    Token(TokenType type, str text);
    TokenType getType();
    str getText();
    void setText(str text);
    void setType(TokenType type);

private:

    TokenType type;
    str text;
};