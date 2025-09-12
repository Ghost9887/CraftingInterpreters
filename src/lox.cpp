#include "common.hpp"
#include "interpreter.hpp"

int main(int argc, char *argv[]) {

   Interpreter interpreter;

  if(argc > 2){
    std::cout << "Usage: ./program 'file name'" << "\n";
    exit(EXIT_FAILURE);
  }

  //read the file
  else if(argc == 2){
    interpreter.runFile(argv[1]);
  }
  
  //use the cmd to use the language
  else{
    interpreter.runPrompt();
  }

  return 0;
}
