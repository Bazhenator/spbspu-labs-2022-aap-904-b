#include <InputData.h>
#include "comparingFunctions.h"
int main()
{
  const size_t defaultCapacity = 100;
  char *string = nullptr;
  size_t stringSize = 0u;
  try
  {
    string = new char[defaultCapacity];
    std::pair<char *, size_t> data = siobko::inputString(std::cin, string, defaultCapacity);
    string = data.first;
    stringSize = data.second;
    std::cout << ((siobko::isFloat(string, stringSize)) ? "true" : "false") << '\n';
  }
  catch (const std::exception &err)
  {
    std::cerr << err.what() << '\n';
    delete[] string;
    return 1;
  }
  delete[] string;
  return 0;
}
