#include "stringManaging.h"
#include <fstream>

void pelipeychenko::deleteDigits(char *result, const char *source) {
  int resultSize = 0;
  for (std::size_t i = 0u; source[i]; i++) {
    if (!std::isdigit(source[i])) {
      result[resultSize] = source[i];
      resultSize++;
    }
  }
  result[resultSize] = '\0';
}
