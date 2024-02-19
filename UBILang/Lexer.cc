#include "Lexer.hh"



Lexer::Lexer(str input)
{
    this->input = input;
    this->length = input.length();

    tokens = vec<Token> {};
}

vec<Token> Lexer::tokenize()
{
    while (this->pos < this->length) {

        char current = peek(NULL);

        if (std::isdigit(current)) 
        {
            tokenizeNumber();
        } 
        else if (std::isalpha(current))
        {
            tokenizeWord();
        } 
        else if (current == '#')
        {
            tokenizeHexNumber();
        }
        else if (OPERATION_CHARS.find(current) != -1)
        {
            tokenizeOperator();
        }
        else
        {
            next();
        }
    }
    return tokens;
}

void Lexer::tokenizeWord()
{
    str buffer;
    char current = peek(0);

    while (!std::isdigit(current)) {

       if (!(std::isdigit(current) || std::isalpha(current)) && (current != '_') && (current != '$'))
       {
            break;
       }

        buffer += current;
        current = next();
    }
    addToken(TokenType::WORD, buffer);
}

void Lexer::tokenizeNumber()
{
    str buffer;
    char current = peek(0);

    while (std::isdigit(current)) {
        if (current == '.')
        {
            if (buffer.find('.') != -1)
            {

            }
        }
        else if (!std::isdigit(current))
        {
            break;
        }

        buffer += current;
        current = next();
    }
    addToken(TokenType::NUMBER, buffer);
}

void Lexer::tokenizeHexNumber()
{
    str buffer;
    char current = peek(0);

    while (std::isdigit(current)) {
        buffer += current;
        current = next();
    }
    addToken(TokenType::HEX_NUMBER, buffer);
}

void Lexer::tokenizeOperator()
{
    TokenType result{};

    switch (peek(0)) {
    case '+':
        result = TokenType::PLUS;
        break;
    case '-':
        result = TokenType::MINUS;
        break;
    case '/':
        result = TokenType::DELITE;
        break;
    case '*':
        result = TokenType::MULTI;
        break;
    case '(':
        result = TokenType::LPAREN;
        break;
    case ')':
        result = TokenType::RPAREN;
        break;
    case '=':
        result = TokenType::EQ;
        break;
    }

    addToken(result);
    next();
}

char Lexer::peek(uint32 realativePosition)
{
    uint32 nowPosition = pos + realativePosition;
    if (nowPosition >= length)
        return '\0';
    return input.at(nowPosition);
}

char Lexer::next()
{
    pos++;
    return peek(NULL);
}

void Lexer::addToken(TokenType type)
{
    tokens.push_back(Token(type, ""));
}

void Lexer::addToken(TokenType type, str text)
{
    tokens.push_back(Token(type, text));
}