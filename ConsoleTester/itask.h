#include <iostream>

class ITask {
public:
    virtual std::string run(std::vector<std::string> req) const = 0;
};