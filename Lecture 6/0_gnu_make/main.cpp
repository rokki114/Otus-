#include <iostream>

#include "answer.h"

int main(int, char**) {
  std::cout << "Hello from the GNU Make example!" << std::endl
            << R"(The answer is ")" << getAnswer() << R"("!)" << std::endl;

  return 0;
}