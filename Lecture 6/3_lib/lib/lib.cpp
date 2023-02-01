#include "lib.h"

#include <iostream>

#include "config.h"

namespace lib {

int makeSomeSuperJob() {
  std::cout << "Hello from lib!" << std::endl;
  return 42;
}

int getVersion() { return getProjectVersionPatch(); }

}  // namespace lib