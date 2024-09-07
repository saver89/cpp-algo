#include <iostream>
#include "string-length.h"
#include "tester.h"

int main() {
  StringLength task;
  Tester tester(&task, "tests");
  tester.RunTest();
  
  return 0;
}