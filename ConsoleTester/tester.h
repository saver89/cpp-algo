#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::string trim(std::string s) {
    std::regex e("^\\s+|\\s+$");   // remove leading and trailing spaces
    return std::regex_replace(s, e, "");
}

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

class Tester {
  public:
    ITask *task;
    std::string path;

    Tester(ITask *task, std::string path) {
      this->task = task;
      this->path = path;
    }

    void RunTest() {
      int nr = 0;
      while (true) {
        std::string inFile = path + "/test." + std::to_string(nr) + ".in";
        std::string outFile = path + "/test." + std::to_string(nr) + ".out";

        bool inFileExists = std::filesystem::exists(inFile);
        bool outFileExists = std::filesystem::exists(outFile);

        if (!inFileExists && !outFileExists) {
          break;
        }
        std::cout<<"Test #"<<nr<<" - "<< BoolToString(Test(inFile, outFile)) << std::endl;
        nr++;
      } 
    }

    bool Test(std::string inFile, std::string outFile) {
      try {
        std::ifstream inFileF;
        std::ifstream outFileF;
        std::string fline;

        inFileF.open(inFile);
        std::vector<std::string> inFileData;


        if (inFileF.is_open()) {
          while (std::getline(inFileF, fline)) {
            inFileData.push_back(trim(fline));
          }
        }
        inFileF.close();

        outFileF.open(outFile);
        std::vector<std::string> outFileData;

        std::string expected = "";
        if (outFileF.is_open()) {
          while (std::getline(outFileF, fline)) {
            expected += trim(fline) + "\n";
          }
        }
        outFileF.close();
        expected = trim(expected);

        std::string result = task->run(inFileData);

        return expected == result;
      } catch (std::string error_message) {
        std::cout << error_message << std::endl;
        return false;
      }
    }
};