#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>

namespace BitcoinExchange {
  // Key: date, Value: exchange rate
  // Valid date format: YYYY-MM-DD
  typedef std::map<std::string, double> Database;
  void printBitcoinWorths(const std::string& dbFile, const std::string& inputFile);

  namespace helper {
    Database loadDatabase(const std::string& dbFile);
    void processInputFile(const std::string& inputFile, const Database& database);
    long long dateToLongLong(const std::string& date);
    double getExchangeRate(const std::string& date, const Database& database);
  }

  namespace validator {
    bool isValidDate(const std::string& date);
  }
}

#endif
