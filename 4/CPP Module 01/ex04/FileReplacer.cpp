#include "FileReplacer.h"

FileReplacer::FileReplacer(const std::string &fileName, const std::string &s1, const std::string &s2)
    : s1(s1), s2(s2) {
  inFile.open(fileName);
  if (!inFile)
    throw std::runtime_error("Input file could not be opened.");

  outFile.open(fileName + ".replace");
  if (!outFile)
    throw std::runtime_error("Output file could not be created.");

  replace();
}

FileReplacer::~FileReplacer() {
  inFile.close();
  outFile.close();
}

void FileReplacer::replace() {
  std::string line;

  while (std::getline(inFile, line)) {
    std::string result;
    result.reserve(line.length());

    size_t startPos = 0;
    size_t pos;
    while ((pos = line.find(s1, startPos)) != std::string::npos) {
      result.append(line, startPos, pos - startPos);
      result.append(s2);
      startPos = pos + s1.length();
    }
    result.append(line, startPos, line.length() - startPos);

    outFile << result << '\n';
  }
}
