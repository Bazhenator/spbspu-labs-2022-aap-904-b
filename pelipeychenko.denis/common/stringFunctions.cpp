#include "stringFunctions.h"

char *pelipeychenko::inputString(std::istream &in, std::size_t &size) {
  std::size_t capacity = 30u;
  char *string = new char[capacity];
  in >> std::noskipws;
  do {
    if (size == capacity) {
      char *subString;
      subString = new char[capacity + 30u];
      for (char *i = string, *j = subString; i != string + size; ++i, ++j) {
        *j = *i;
      }
      delete[] string;
      string = subString;
      capacity += 30u;
    }
    std::cin >> string[size];
  } while (std::cin && string[size++] != '\n');
  string[size == 0u ? size : size - 1u] = '\0';
  if (!string[0]) {
    delete[] string;
    throw std::invalid_argument("empty line");
  }
  return string;
}
