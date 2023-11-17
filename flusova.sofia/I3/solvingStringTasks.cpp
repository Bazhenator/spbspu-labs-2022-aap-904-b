#include "solvingStringTasks.h"
#include <iostream>
#include <cstddef>
#include <cstring>
#include <set>

bool flusova::checkSameNearElInCline(char* cstring)
{
  size_t size = strlen(cstring);
  for (std::size_t i = 0; i < size - 1; ++i)
  {
    if (*(cstring + i) == *(cstring + (i + 1))) {
      return 1;
    }
  }
  return 0;
}
bool flusova::checkSameDigitsInCline(char* cstring)
{
  size_t size = strlen(cstring);
  std::set<int> digits;
  for (std::size_t i = 0; i < size; ++i)
  {
    if ((isdigit(*(cstring + i))) && (digits.count(*(cstring + i)) > 0))
    {
      return 1;
    }
    digits.insert(*(cstring + i));
  }
  return 0;
}


