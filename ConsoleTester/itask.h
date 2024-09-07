#include <iostream>

class ITask {
public:
    virtual std::string run(std::string req[]) const = 0;
};