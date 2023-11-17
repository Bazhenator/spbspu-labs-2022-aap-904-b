#include "inputString.h"

char *oleynikova::inputString(std::istream &in, std::size_t &capacity)
{
  std::size_t size = 0;
  char *string = new char[capacity];
  in >> std::noskipws;
  do {
    if (size == capacity) {
      char *newStr = nullptr;
      try {
        newStr = new char[capacity + 20];
      }
      catch (const std::bad_alloc &e) {
        delete[] string;
        throw std::runtime_error("Bad_alloc");
      }
      for (char *i = string, *j = newStr; i != string + size; ++i, ++j) {
        *j = *i;
      }
      delete[] string;
      string = newStr;
      capacity += 20;
    }
    in >> string[size++];
  } while (std::cin && (string[size - 1] != '\n'));
  if (size != 0) {
    string[size - 1] = '\0';
  }
  else {
    string[0] = '\0';
  }
  if (!string[0]) {
    delete[] string;
    throw std::runtime_error("Empty string");
  }
  return string;
}
