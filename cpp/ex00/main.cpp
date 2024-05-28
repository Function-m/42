#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  BitcoinExchange::printBitcoinWorths("data.csv", argv[1]);
  return 0;
}
