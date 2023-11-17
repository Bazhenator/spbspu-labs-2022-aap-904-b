#include "StringFunctions.h"
#include <iostream>
#include <unordered_set>
#include <limits>

unsigned short siobko::CountDiffLetters(char *str)
{
  std::uint16_t sum = 0u;
  std::unordered_set<std::uint16_t> set_of_char;
  for (size_t i = 0u; str[i] != '\0'; ++i)
  {
    if (siobko::IsCharEnglishLetter(str[i]))
    {
      if (set_of_char.find(str[i]) == set_of_char.end())
      {
        if (sum == std::numeric_limits<int>::max())
        {
          delete[] str;
          throw std::runtime_error("Overflow of integer sum... Restart the programm");
        }
        else
        {
          sum++;
        }
        set_of_char.insert(str[i]);
      }
    }
  }
  return sum;
}
bool siobko::IsCharEnglishLetter(char letter)
{
  return ((letter > 'a' && letter < 'z') || (letter > 'A' && letter < 'Z'));
}
