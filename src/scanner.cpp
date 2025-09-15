#include "scanner.hpp"

Interpreter interpreter;

void Scanner::initMap(){
  //Map
  keywords["and"] = TokenType::AND;
  keywords["class"] = TokenType::CLASS;
  keywords["else"] = TokenType::ELSE;
  keywords["false"] = TokenType::FALSE;
  keywords["for"] = TokenType::FOR;
  keywords["fun"] = TokenType::FUN;
  keywords["if"] = TokenType::IF;
  keywords["nil"] = TokenType::NIL;
  keywords["or"] = TokenType::OR;
  keywords["print"] = TokenType::PRINT;
  keywords["return"] = TokenType::RETURN;
  keywords["super"] = TokenType::SUPER;
  keywords["this"] = TokenType::THIS;
  keywords["true"] = TokenType::TRUE;
  keywords["var"] = TokenType::VAR;
  keywords["while"] = TokenType::WHILE;
}


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
    case '/':
      if(match('/')){
        //a comment goes all the way to the end of the line
        while(peek() != '\n' && !isAtEnd()) advance();
      }else{
        addToken(TokenType::SLASH);
      }
      break;
    case ' ':
    case '\r':
    case '\t':
      break;
    case '\n':
      line++;
      break;
    case '"':
      string();
      break;
    case 'o':
      if(peek() == 'r'){
        addToken(TokenType::OR);
      }
      break;
    default:
      if(isDigit(c)){
        number();
      }
      else if(isAlpha(c)){
        identifier();
      }
      else{
        interpreter.error(line, "Unexpected character");
      }
      break;
  }
}

void Scanner::identifier(){
  while(isAlphaNumeric(peek())) advance();
  std::string text = source.substr(start, current);
  auto key = keywords.find(text);
  TokenType type;
  if(key == keywords.end()) type = TokenType::IDENTIFIER;
  addToken(type);
}

bool Scanner::isAlpha(char c){
  return (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z') ||
         c == '_';
}

bool Scanner::isAlphaNumeric(char c){
  return isAlpha(c) || isDigit(c);
}

void Scanner::number(){
  while(isDigit(peek())) advance();
  //Look for decimal
  if(peek() == '.' && isDigit(peekNext())){
    advance();

    while(isDigit(peek())) advance();
  }
  addToken(TokenType::NUMBER, stod(source.substr(start, current), NULL));
}

char Scanner::peekNext(){
  if(current + 1 >= (int)source.length()) return '\0';
  return source[current + 1];
}

bool Scanner::isDigit(char c){
  return c >= '0' && c <= '9';
}

void Scanner::string(){
  while(peek() != '"' && !isAtEnd()){
    if(peek() == '\n') line++;
    advance();
  }
  if(isAtEnd()){
    interpreter.error(line, "Unterminated string");
    return;
  }
  //The closing "";
  advance();

  std::string value = source.substr(start + 1, current - 1);
  addToken(TokenType::STRING, value);
}

char Scanner::peek(){
  if(isAtEnd()) return '\0';
  return source[current];
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



