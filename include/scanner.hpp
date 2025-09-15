#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "common.hpp"
#include "token.hpp"
#include "tokenType.hpp"
#include "interpreter.hpp"

  class Scanner{
    public:
      Scanner(std::string source);
      std::vector<Token> scanTokens();
    private:
      const std::string source;
      std::vector<Token> tokens;
      int start;
      int current;
      int line;
      bool isAtEnd();
      void scanToken();
      char advance();
      void addToken(TokenType type);
      void addToken(TokenType type, std::any literal);
      bool match(char expected);
  };

#endif
