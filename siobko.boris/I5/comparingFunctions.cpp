#include "comparingFunctions.h"
bool siobko::isFloat(char *str, size_t stringSize)
{
  size_t i = 0u;
  i += ((str[i] == '-' || str[i] == '+') ? 1u : 0u);
  if (str[i] == '.')
  {
    i++;
    if (i < (stringSize - 2u) && siobko::isInteger(str, stringSize, i))
    {
      if (str[i] == 'E')
      {
        ++i;
        i += ((str[i] == '-' || str[i] == '+') ? 1u : 0u);
        if (siobko::isInteger(str, stringSize, i))
        {
          return i == stringSize;
        }
      }
    }
  }
  return false;
}
bool siobko::isInteger(char *str, size_t stringSize, size_t &i)
{
  if (i < stringSize && std::isdigit(str[i]))
  {
    ++i;
    siobko::isInteger(str, stringSize, i);
    return true;
  }
  return false;
}
