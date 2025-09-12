#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "common.hpp"
#include "tokenType.hpp"

//token class
class Token{
  public:
    const TokenType type;
    const std::string lexeme;
    const std::any literal;
    const int line;

    //constructor
    Token(TokenType type, std::string lexeme, std::any literal, int line);
    void print() const;
};

#endif
