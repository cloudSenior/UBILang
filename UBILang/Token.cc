#include "Token.hh"


Token::Token(TokenType type, str text)
{
    this->text = text;
    this->type = type;
}

TokenType Token::getType()
{
    return type;
}

str Token::getText()
{
    return text;
}

void Token::setText(str text)
{
    this->text = text;
}

void Token::setType(TokenType type)
{
    this->type = type;
}