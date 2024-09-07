#include <iostream>
#include "string-length.h"

int main() {
  StringLength task;
  std::string req[] = {"Hello, World!"};
  std::string res = task.run(req);
  std::cout << res << std::endl;
  return 0;
}