#include "manageWithCStrings.h"
#include <iostream>
#include <cctype>

char *ponomarev::removeAlpha(char *destination, char *source)
{
  std::size_t dIndex = 0;
  for (char *sPointer = source; *sPointer; sPointer++) {
    if (!std::isalpha(static_cast<unsigned char>(*sPointer))) {
      destination[dIndex++] = *sPointer;
    }
  }
  destination[dIndex] = '\0';
  return destination;
}
