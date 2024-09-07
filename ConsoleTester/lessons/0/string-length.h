#include <iostream>
#include "../../itask.h"

class StringLength : public ITask {
  public:
    std::string run(std::vector<std::string> req) const override {
      for (int i = 0; i < req.size(); i++) {
        return std::to_string(req.at(0).length());
      }

      return 0;
    }
    
};