#include "common.hpp"

void runFile(char *fileName);
void runPrompt();
void run(std::string fileContent);

int main(int argc, char *argv[]) {

  if(argc > 2){
    std::cout << "Usage: ./program 'file name'" << "\n";
    exit(EXIT_FAILURE);
  }

  //read the file
  else if(argc == 2){
    runFile(argv[1]);
  }
  
  //use the cmd to use the language
  else{
    runPrompt();
  }

  return 0;
}

void runFile(char *fileName){
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

void runPrompt(){
  std::cout << "running prompt" << "\n";

  std::cout << "> ";

  //user input
  std::string input;
  std::getline(std::cin, input); // we use getline as std::cin >> cuts off after whitespace

  run(input);
}

void run(std::string fileContent){

  std::cout << "running code" << "\n";

  std::cout << fileContent << "\n";

}
