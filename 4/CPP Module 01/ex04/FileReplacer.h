#ifndef FILE_REPLACER
#define FILE_REPLACER

#include <fstream>
#include <iostream>
#include <string>

class FileReplacer {
 public:
  FileReplacer(const std::string &fileName, const std::string &s1, const std::string &s2);
  ~FileReplacer();

 private:
  std::ifstream inFile;
  std::ofstream outFile;
  std::string s1;
  std::string s2;

  void replace();
};

#endif