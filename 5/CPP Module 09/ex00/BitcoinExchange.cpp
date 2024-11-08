#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <math.h>

namespace BitcoinExchange {

  void printBitcoinWorths(const std::string &dbFile, const std::string &inputFile) {
    try {
      Database database = helper::loadDatabase(dbFile);
      helper::processInputFile(inputFile, database);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }

  namespace helper {
    Database loadDatabase(const std::string &dbFile) {
      std::ifstream file(dbFile.c_str());
      if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
      }

      Database database;
      std::string line;
      if (!std::getline(file, line) || line != "date,exchange_rate") {
        throw std::invalid_argument("Error: bad header in the database file.");
      }
      while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double exchangeRate;

        if (std::getline(iss, date, ',') && iss >> exchangeRate && iss.eof() && validator::isValidDate(date)) {
          if (database.find(date) != database.end())
            throw std::invalid_argument("Error: duplicate date in the database file.");
          database[date] = exchangeRate;
        } else {
          throw std::invalid_argument("Error: bad format in the database file.");
        }
      }
      return database;
    }

    void processInputFile(const std::string &inputFile, const Database &database) {
      std::ifstream file(inputFile.c_str());
      if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
      }

      std::string line;
      if (!std::getline(file, line) || line != "date | value") {
        throw std::invalid_argument("Error: bad header in the input file.");
      }
      while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, deliminater;
        double value;

        // date
        if (!(std::getline(iss, date, ' ') && !iss.eof() && validator::isValidDate(date))) {
          std::cout << "Error: bad input => " << line << std::endl;
        }
        // deliminater
        else if (!(std::getline(iss, deliminater, ' ') && !iss.eof() && deliminater == "|" && iss.peek() != ' ')) {
          std::cout << "Error: bad input => " << line << std::endl;
        }
        // value
        else if (!(iss >> value && iss.eof() && value >= 0 && value <= 1000)) {
          if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
          } else if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
          } else {
            std::cout << "Error: bad input => " << line << std::endl;
          }

        } else {
          double exchangeRate = getExchangeRate(date, database);
          if (isnan(exchangeRate))
            std::cout << "Error: no exchange rate available for " << date << "." << std::endl;
          else
            std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
        }
      }
    }

    long long dateToLongLong(const std::string& date) {
      int year, month, day;
      char dash;

      std::istringstream ss(date);
      ss >> year >> dash >> month >> dash >> day;
      return year * 10000 + month * 100 + day;
    }

    double getExchangeRate(const std::string &date, const Database &database) {
      std::map<std::string, double>::const_iterator it = database.end();
      long long dateLL = dateToLongLong(date);

      while (--it != database.begin()) {
        if (dateToLongLong(it->first) <= dateLL) {
          return it->second;
        }
      }
      return std::numeric_limits<double>::quiet_NaN();
    }
  } // namespace helper

  namespace validator {
    bool isValidDate(const std::string &date) {
      std::istringstream ss(date);
      int year, month, day;
      char delim1, delim2;

      // Format: YYYY-MM-DD
      if (!(ss >> year >> delim1 >> month >> delim2 >> day && ss.eof() && delim1 == '-' && delim2 == '-')) {
        return false;
      }

      if (year > 9999 || year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
      }

      if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
          return day <= 29;
        } else {
          return day <= 28;
        }
      } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
      } else {
        return day <= 31;
      }
    }
  } // namespace validator
} // namespace BitcoinExchange