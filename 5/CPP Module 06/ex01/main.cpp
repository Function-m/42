#include <iostream>

#include "Serializer.hpp"

int main() {
  Data myData;
  myData.value = 123;

  std::cout << "* Original data\n"
            << "Original data value: " << myData.value << "\n"
            << "Original data address: " << &myData << "\n";
  std::cout << std::endl;

  // serialize
  std::cout << "* Serializing\n";
  uintptr_t raw = Serializer::serialize(&myData);
  std::cout << "Serialized raw value (uintptr_t): " << raw << "\n"
            << "Serialized hex value: " << "0x" << std::hex << raw << std::dec << "\n";
  std::cout << std::endl;

  // deserialize
  std::cout << "* Deserializing\n";
  Data* pData = Serializer::deserialize(raw);
  std::cout << "Deserialized data value: " << pData->value << "\n"
            << "Deserialized data address: " << pData << "\n";
  std::cout << std::endl;

  // Check if pointers are equal
  if (pData == &myData) {
    std::cout << "The deserialized pointer is equal to the original pointer." << std::endl;
  } else {
    std::cout << "The deserialized pointer is NOT equal to the original pointer." << std::endl;
  }

  return 0;
}
