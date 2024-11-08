#include "Utils.h"

namespace utils {

/**
 * @brief 사용자로부터 입력을 받습니다.
 *
 * 이 함수는 사용자에게 프롬프트를 표시하고, 사용자가 비어 있지 않은 문자열을 입력할 때까지 기다립니다.
 * 사용자가 EOF (Ctrl+D)를 입력하면, 프로그램은 종료 메시지를 출력하고 종료합니다.
 * 입력 오류가 발생한 경우, 오류 메시지를 출력하고 다시 입력을 요청합니다.
 *
 * @param prompt 사용자에게 표시할 프롬프트 문자열입니다.
 * @return std::string 사용자가 입력한 비어 있지 않은 문자열을 반환합니다.
 */
std::string getInput(const std::string &prompt) {
  std::string input;

  while (true) {
    if (prompt != "")
      std::cout << prompt << std::flush;

    if (std::getline(std::cin, input)) {
      input = removeAnsiEscapeCodes(input);

      if (input.empty()) {
        std::cout << "\n입력이 비어있을 수 없습니다. " << std::endl;
        waitForEnter();
        clearScreen(5);
        continue;
      }
      return input;

    } else if (std::cin.eof()) {
      std::cin.clear();
      std::cout << "\n\nEOF가 입력되었습니다. 프로그램을 종료합니다.\n" << std::endl;
      exit(EXIT_FAILURE);

    } else {
      std::cin.clear();
      std::cout << "\n입력에 실패했습니다. " << std::endl;
      waitForEnter();
      clearScreen(5);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/**
 * @brief 사용자로부터 숫자만 입력받습니다.
 *
 * 이 함수는 사용자에게 프롬프트를 표시하고, 사용자가 숫자만 포함한 문자열을 입력할 때까지 기다립니다.
 * 사용자가 EOF (Ctrl+D)를 입력하면, 프로그램은 종료 메시지를 출력하고 종료합니다.
 * 비어 있는 입력이거나 숫자가 아닌 문자가 포함된 경우, 오류 메시지를 출력하고 다시 입력을 요청합니다.
 *
 * @param prompt 사용자에게 표시할 프롬프트 문자열입니다.
 * @return std::string 사용자가 입력한 숫자만 포함한 문자열을 반환합니다.
 */
std::string getNumericInput(const std::string &prompt) {
  std::string input;

  while (true) {
    if (prompt != "")
      std::cout << prompt << std::flush;

    if (std::getline(std::cin, input)) {
      input = removeAnsiEscapeCodes(input);
      if (!input.empty() && isNumber(input)) {
        return input;
      }
      std::cout << "\n유효한 숫자를 입력해주세요. " << std::endl;
      waitForEnter();
      clearScreen(5);

    } else if (std::cin.eof()) {
      std::cin.clear();
      std::cout << "\nEOF가 입력되었습니다. 프로그램을 종료합니다." << std::endl;
      exit(EXIT_FAILURE);

    } else {
      std::cin.clear();
      std::cout << "\n입력에 실패했습니다. " << std::endl;
      waitForEnter();
      clearScreen(5);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/**
 * @brief 사용자가 Enter 키를 누를 때까지 대기합니다.
 *
 * 이 함수는 사용자에게 Enter 키를 누르라는 메시지를 표시하고, 사용자가 Enter 키를 누를 때까지 대기합니다.
 * 이를 통해 프로그램 실행 중에 일시적으로 멈추고 사용자의 입력을 기다릴 수 있습니다.
 */
void waitForEnter() {
  std::cout << "\nENTER를 입력해 주세요..." << std::flush;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.clear();
}

/**
 * @brief 콘솔 화면을 지웁니다.
 *
 * 이 함수는 콘솔 화면을 지우기 위해 ANSI 이스케이프 코드를 사용합니다.
 * 파라미터로 지정된 라인 수만큼 콘솔의 내용을 지울 수 있으며,
 * 라인 수가 -1로 지정되면 전체 화면을 지웁니다.
 *
 * @param lines 지우고자 하는 라인 수입니다. 기본값은 -1로, 전체 화면을 지웁니다.
 */
void clearScreen(int lines) {
  if (lines == -1) {
    std::cout << "\033[2J\033[1;1H";
  } else {
    for (int i = 0; i < lines; ++i) {
      std::cout << "\033[G\033[1A\033[2K";
    }
  }
  std::cout << std::flush;
}

/**
 * @brief 문자열에서 ANSI 이스케이프 코드를 제거합니다.
 *
 * 이 함수는 주어진 문자열에서 ANSI 이스케이프 코드를 찾아 제거합니다.
 * 이스케이프 코드는 일반적으로 콘솔의 색상이나 스타일을 변경하는 데 사용됩니다.
 *
 * @param input 이스케이프 코드를 제거하고자 하는 원본 문자열입니다.
 * @return std::string 이스케이프 코드가 제거된 문자열을 반환합니다.
 */
std::string removeAnsiEscapeCodes(const std::string &input) {
  std::string output;
  size_t i = 0;

  while (i < input.size()) {
    if (i + 1 < input.size() && input[i] == '\033' && input[i + 1] == '[') {
      i += 2;
      while (i < input.size() && !(input[i] >= '@' && input[i] <= '~')) {
        ++i;
      }
      ++i;
    } else {
      output += input[i++];
    }
  }
  return output;
}

/**
 * @brief 문자열이 공백만으로 이루어져 있는지 확인합니다.
 *
 * 이 함수는 주어진 문자열이 공백(스페이스, 탭, 개행 등)만으로 이루어져 있는지 확인합니다.
 * 문자열에 공백 이외의 다른 문자가 포함되어 있지 않으면 true를 반환합니다.
 *
 * @param input 검사하고자 하는 문자열입니다.
 * @return true 문자열이 공백만으로 이루어져 있으면 true를 반환합니다.
 * @return false 문자열에 공백 이외의 문자가 포함되어 있으면 false를 반환합니다.
 */
bool isOnlyWhitespace(const std::string &input) {
  for (size_t i = 0; i < input.size(); ++i) {
    if (!std::isspace(input[i])) {
      return false;
    }
  }
  return true;
}

/**
 * @brief 문자열이 숫자만으로 이루어져 있는지 확인합니다.
 *
 * 이 함수는 주어진 문자열이 숫자(0-9)만 포함하고 있는지 확인합니다.
 * 문자열이 숫자만으로 이루어져 있으면 true를 반환합니다.
 *
 * @param str 검사하고자 하는 문자열입니다.
 * @return true 문자열이 숫자만으로 이루어져 있으면 true를 반환합니다.
 * @return false 문자열에 숫자 이외의 문자가 포함되어 있으면 false를 반환합니다.
 */
bool isNumber(const std::string &str) {
  for (size_t i = 0; i < str.size(); ++i) {
    if (!std::isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

}  // namespace utils
