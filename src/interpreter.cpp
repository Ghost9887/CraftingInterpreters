#include "interpreter.hpp"

/*this is where we define all the methods and variables of class Interpreter*/

bool Interpreter::hadError = false;

void Interpreter::runFile(char *fileName){
  std::cout << "running file: " << fileName << "\n"; 

  //open the file
  std::ifstream file(fileName);
  std::string temp;
  std::string fileContent  = "";

  //write the file content to the string
  while(getline(file, temp)){
    fileContent += temp;
  }

  file.close();
  //std::cout << fileContent << "\n";
    
  //run the program
  run(fileContent);
}

void Interpreter::runPrompt(){
  std::cout << "running prompt" << "\n";

  std::cout << "> ";

  //user input
  std::string input;
  std::getline(std::cin, input); // we use getline as std::cin >> cuts off after whitespace

  run(input);
  Interpreter::hadError = false;
}

void Interpreter::run(std::string fileContent){
  std::cout << "running code" << "\n";
  std::cout << fileContent << "\n";
  if(Interpreter::hadError) exit(EXIT_FAILURE);
}

void Interpreter::error(int line, std::string message){
  Interpreter::report(line, "", message);
}

void Interpreter::report(int line, std::string where, std::string message){
  //prints the error
  std::cerr << "[line" << line << "] Error" << where << ": " << message << "\n";
  Interpreter::hadError = true;
}
