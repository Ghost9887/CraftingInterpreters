#include "scanner.hpp"

Scanner::Scanner(std::string source) 
: source(std::move(source)){}

bool Scanner::isAtEnd(){
  return current >= (int)source.length();
}

std::vector<Token> Scanner::scanTokens(){
  while(!isAtEnd()){
    start = current;
    scanToken();
  }
  tokens.push_back(Token(TokenType::END_OF_FILE, "", std::any{}, line)); //std::any{} == NULL
  return tokens;
}

void Scanner::scanToken(){
  Interpreter interpreter;
  char c = advance();
  switch(c){
    case '(':
      addToken(TokenType::LEFT_PAREN);
      break;
    case ')':
      addToken(TokenType::RIGHT_PAREN);
      break;
    case '{':
      addToken(TokenType::LEFT_BRACE);
      break;
    case '}':
      addToken(TokenType::RIGHT_BRACE);
      break;
    case ',':
      addToken(TokenType::COMMA);
      break;
    case '.':
      addToken(TokenType::DOT);
      break;
    case '-':
      addToken(TokenType::MINUS);
      break;
    case '+':
      addToken(TokenType::PLUS);
      break;
    case ';':
      addToken(TokenType::SEMICOLON);
      break;
    case '*':
      addToken(TokenType::STAR);
      break;
    case '!':
      addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
      break;
    case '=':
      addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
      break;
    case '<':
      addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
      break;
    case '>':
      addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
      break;
    default:
      interpreter.error(line, "Unexpected character");
      break;
  }
}

bool Scanner::match(char expected){
  if(isAtEnd()) return false;
  if(source[current] != expected) return false;
  current++;
  return true;
}

char Scanner::advance(){
  current++;
  return source[current - 1];
}

void Scanner::addToken(TokenType type){
  addToken(type, NULL);
}

void Scanner::addToken(TokenType type, std::any literal){
  std::string text = source.substr(start, current); 
  tokens.push_back(Token(type, text, literal, line));
}



