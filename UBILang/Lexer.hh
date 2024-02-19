#pragma once

#include "Token.hh"

class Lexer {
public:

    Lexer(str input);

    vec<Token> tokenize();

private:
    const str OPERATION_CHARS { "+-/*()=" };
    
    vec<Token> tokens;
    str input;

    uint32 pos, length;

    void tokenizeNumber();

    void tokenizeHexNumber();

    void tokenizeWord();

    void tokenizeOperator();

    char peek(uint32 realativePosition);

    char next();

    void addToken(TokenType type);

    void addToken(TokenType type, str text);
};