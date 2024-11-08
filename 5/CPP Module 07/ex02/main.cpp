#include <iostream>

#include "Array.hpp"

// int main() {
//   try {
//     std::cout << "\n* 빈 배열 생성 *\n";
//     Array<int> emptyArray;
//     std::cout << "빈 배열 사이즈: " << emptyArray.size() << "\n";

//     std::cout << "\n* 크기를 인자로 받는 배열 생성 *\n";
//     unsigned int n = 5;
//     Array<int> intArray(n);
//     std::cout << "배열 사이즈 (n=5): " << intArray.size() << "\n";

//     std::cout << "\n* 배열 요소 접근 및 초기값 출력 *\n";
//     for (unsigned int i = 0; i < n; ++i) {
//       std::cout << "intArray[" << i << "] = " << intArray[i] << "\n";
//     }

//     std::cout << "\n* 배열 요소 값 수정 *\n";
//     for (unsigned int i = 0; i < n; ++i) {
//       intArray[i] = i * 10;
//     }
//     for (unsigned int i = 0; i < n; ++i) {
//       std::cout << "intArray[" << i << "] = " << intArray[i] << "\n";
//     }

//     std::cout << "\n* 복사 생성자 *\n";
//     Array<int> copiedArray(intArray);
//     std::cout << "복사된 배열 크기: " << copiedArray.size() << "\n";
//     for (unsigned int i = 0; i < copiedArray.size(); ++i) {
//       std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << "\n";
//     }

//     std::cout << "\n* 기존 배열 수정 출력 및 복사된 배열 출력 *\n";
//     for (unsigned int i = 0; i < n; ++i) {
//       intArray[i] = i * 100;
//     }
//     for (unsigned int i = 0; i < n; ++i) {
//       std::cout << "intArray[" << i << "] = " << intArray[i] << "\n";
//     }
//     for (unsigned int i = 0; i < copiedArray.size(); ++i) {
//       std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << "\n";
//     }

//     std::cout << "\n* 대입 연산자 *\n";
//     Array<int> assignedArray;
//     assignedArray = intArray;
//     std::cout << "Assigned array size: " << assignedArray.size() << "\n";
//     for (unsigned int i = 0; i < assignedArray.size(); ++i) {
//       std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << "\n";
//     }

//     std::cout << "\n* 인덱스 범위 초과 *\n";
//     try {
//       std::cout << intArray[10] << "\n";
//     } catch (const std::exception& e) {
//       std::cerr << e.what() << "\n";
//     }

//   } catch (const std::exception& e) {
//     std::cerr << "Exception: " << e.what() << "\n";
//   }

//   return 0;
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}