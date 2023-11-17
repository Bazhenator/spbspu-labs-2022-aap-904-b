#include "InputData.h"
std::pair<char *, size_t> siobko::inputString(std::istream &in, char *str, size_t capacity)
{
  size_t i = 0u;
  in >> std::noskipws;
  while (in >> str[i] && str[i] != '\n')
  {
    i++;
    if (i == capacity - 1u)
    {
      str[i] = '\0';
      str = siobko::makeBiggerString(str, capacity);
    }
  }
  if (i < 2)
  {
    throw std::runtime_error("Zero input error");
  }
  str[i] = '\0';
  return {str, i - 1};
}
char *siobko::makeBiggerString(char *str, size_t &capacity)
{
  size_t originalCapacity = capacity;
  char *newString = nullptr;
  capacity *= 2;
  try
  {
    newString = new char[capacity];
  }
  catch (const std::bad_alloc &err)
  {
    delete[] str;
    throw std::exception(err);
  }
  for (size_t i = 0u; i != originalCapacity; ++i)
  {
    newString[i] = str[i];
  }
  delete[] str;
  return newString;
}
