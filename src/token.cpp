#include "token.hpp"

//constructor
Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
//initializer list
: type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line){}

//print method
void Token::print() const{
  std::cout << type << "(" << lexeme << ") at line " << line << "\n";
}
