#include "Harl.h"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "\n[DEBUG level]\n";
    harl.complain("DEBUG");

    std::cout << "\n[INFO level]\n";
    harl.complain("INFO");

    std::cout << "\n[WARNING level]\n";
    harl.complain("WARNING");

    std::cout << "\n[ERROR level]\n";
    harl.complain("ERROR");

    std::cout << "\n[ETC level]\n";
    harl.complain("");

    return 0;
}

