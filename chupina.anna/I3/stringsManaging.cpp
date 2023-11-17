#include "stringsManaging.h"
#include <iostream>

char * chupina::replaceUpperToLowerCase(char * newCString, const char * cString)
{
  int currentLength = -1;
  while (cString[++currentLength]) {
    if (cString[currentLength] >= 'a' or cString[currentLength] < 'A') {
      newCString[currentLength] = cString[currentLength];
    } else {
      newCString[currentLength] = cString[currentLength] + 32;
    }
  }
  newCString[currentLength] = '\0';
  delete [] cString;
  return newCString;
}
