#include <iostream>
#include "lessons/0/string-length.h"
#include "tester.h"

int main() {
  StringLength task;
  Tester tester(&task, "lessons/0/tests");
  tester.RunTest();
  
  return 0;
}