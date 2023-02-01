#include <iostream>

#include "answer.h"
#include "config.h"

int main(int, char**) {
  std::cout << "Hello from the 3rd CMake example!" << std::endl;

  std::cout << std::endl
            << R"(The answer is ")" << getAnswer() << R"("!)" << std::endl
            << std::endl;

  std::cout << "Main version from macro: " << (PROJECT_VERSION) << std::endl;
  std::cout << "Main version from func: " << getVersion() << std::endl;

  return 0;
}