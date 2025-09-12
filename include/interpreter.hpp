#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "common.hpp"

class Interpreter{
  public:
    static bool hadError;
    void runFile(char *fileName);
    void runPrompt();
    void run(std::string fileContent);
    void error(int line, std::string message);
    void report(int line, std::string where, std::string message);
};


#endif
