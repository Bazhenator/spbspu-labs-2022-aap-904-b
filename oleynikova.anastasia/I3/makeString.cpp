#include "makeString.h"
#include <cctype>

char *oleynikova::makeString(char *newString, const char *string)
{
  int temp = 0;
  int newLength = 0;
  int i = 0;
  if (std::isspace(string[0])) {
    i = 1;
  }
  for (; string[i]; i++) {
    if (std::isspace(string[i])) {
      if (temp == 0) {
        newString[newLength] = string[i];
        newLength += 1;
        temp += 1;
      }
    }
    else if (!(std::isspace(string[i]))) {
      newString[newLength] = string[i];
      newLength += 1;
      temp = 0;
    }
  }
  if (std::isspace(newString[newLength - 1])) {
    newString[newLength - 1] = '\0';
  }
  else {
    newString[newLength] = '\0';
  }
  return newString;
}
