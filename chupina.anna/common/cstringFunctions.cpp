#include "cstringFunctions.h"

char* chupina::inputString(std::istream &in, size_t &capacity)
{
  char* string = new char[capacity];
  size_t size = 0;
  in >> std::noskipws;
  do {
    if (size == capacity) {
      char* newStr = nullptr;
      try {
        newStr = new char[++capacity];
      } catch (const std::bad_alloc &e) {
        delete[] string;
        throw;
      }
      for (char* i = string, *j = newStr; i != string + size; ++i, ++j) {
        *j = *i;
      }
      delete[] string;
      string = newStr;
    }
    in >> string[size++];
  } while (in && string[size - 1] != '\n');
  string[(size ? size - 1 : 0)] = '\0';
  if (!string[0]) {
    delete[] string;
    throw std::runtime_error("Empty string");
  }
  return string;
}
