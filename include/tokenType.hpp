#ifndef TOKENTYPE_HPP
#define TOKENTYPE_HPP

#include "common.hpp"

enum class TokenType{
  //single character tokens
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  //One or two characters
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  //literals
  IDENTIFIER, STRING, NUMBER,

  //keywords

  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  //end of file
  END_OF_FILE
};


//we have to overload the stream to be able to print the enums directly
inline std::ostream& operator<<(std::ostream& os, const TokenType& type) {
    switch (type) {
        // Single-character tokens
        case TokenType::LEFT_PAREN:     os << "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN:    os << "RIGHT_PAREN"; break;
        case TokenType::LEFT_BRACE:     os << "LEFT_BRACE"; break;
        case TokenType::RIGHT_BRACE:    os << "RIGHT_BRACE"; break;
        case TokenType::COMMA:          os << "COMMA"; break;
        case TokenType::DOT:            os << "DOT"; break;
        case TokenType::MINUS:          os << "MINUS"; break;
        case TokenType::PLUS:           os << "PLUS"; break;
        case TokenType::SEMICOLON:      os << "SEMICOLON"; break;
        case TokenType::SLASH:          os << "SLASH"; break;
        case TokenType::STAR:           os << "STAR"; break;
        // One or two character tokens
        case TokenType::BANG:           os << "BANG"; break;
        case TokenType::BANG_EQUAL:     os << "BANG_EQUAL"; break;
        case TokenType::EQUAL:          os << "EQUAL"; break;
        case TokenType::EQUAL_EQUAL:    os << "EQUAL_EQUAL"; break;
        case TokenType::GREATER:        os << "GREATER"; break;
        case TokenType::GREATER_EQUAL:  os << "GREATER_EQUAL"; break;
        case TokenType::LESS:           os << "LESS"; break;
        case TokenType::LESS_EQUAL:     os << "LESS_EQUAL"; break;
        // Literals
        case TokenType::IDENTIFIER:     os << "IDENTIFIER"; break;
        case TokenType::STRING:         os << "STRING"; break;
        case TokenType::NUMBER:         os << "NUMBER"; break;
        // Keywords
        case TokenType::AND:            os << "AND"; break;
        case TokenType::CLASS:          os << "CLASS"; break;
        case TokenType::ELSE:           os << "ELSE"; break;
        case TokenType::FALSE:          os << "FALSE"; break;
        case TokenType::FUN:            os << "FUN"; break;
        case TokenType::FOR:            os << "FOR"; break;
        case TokenType::IF:             os << "IF"; break;
        case TokenType::NIL:            os << "NIL"; break;
        case TokenType::OR:             os << "OR"; break;
        case TokenType::PRINT:          os << "PRINT"; break;
        case TokenType::RETURN:         os << "RETURN"; break;
        case TokenType::SUPER:          os << "SUPER"; break;
        case TokenType::THIS:           os << "THIS"; break;
        case TokenType::TRUE:           os << "TRUE"; break;
        case TokenType::VAR:            os << "VAR"; break;
        case TokenType::WHILE:          os << "WHILE"; break;
        // End of file
        case TokenType::END_OF_FILE:    os << "END_OF_FILE"; break;
        default:                        os << "UNKNOWN"; break;
    }
    return os;
}


#endif
