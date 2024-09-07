#include <iostream>
#include "itask.h"

class StringLength : public ITask {
  public:
    std::string run(std::string req[]) const override {
      return std::to_string(req[0].length());
    }
};