#include <iostream>
#include <cstddef>
#include <cstring>
#include <InputData.h>
#include "StringFunctions.h"

int main()
{
  char *cstr = nullptr;
  const size_t defaultCapacity = 100;
  try
  {
    cstr = new char[defaultCapacity];
    std::pair<char *, size_t> data = siobko::inputString(std::cin, cstr, defaultCapacity);
    cstr = data.first;
  }
  catch (const std::exception &err)
  {
    delete[] cstr;
    std::cout << err.what();
    return 1;
  }
  strcpy(cstr, "Hello");
  std::cout << "The answer is " << siobko::CountDiffLetters(cstr) << '\n';
  delete[] cstr;
  return 0;
}
