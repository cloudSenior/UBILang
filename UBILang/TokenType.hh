#pragma once


enum class TokenType {
    NUMBER, HEX_NUMBER,
    PLUS,
    MINUS,
    MULTI,
    DELITE,

    LPAREN, // (
    RPAREN, // )
    
    WORD,

    EXITSOPENFILE
};