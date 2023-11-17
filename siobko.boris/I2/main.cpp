#include "ManageArrays.h"
#include <iostream>
#include <cstddef>

namespace siobko
{
  size_t InputDynamicArraySize()
  {
    size_t size;
    std::cin >> size;
    if (std::cin.fail())
    {
      throw std::logic_error("Invalid input dynamic array size");
    }
    return size;
  }
}
int main(int argc, const char* argv[])
{
  if (argc != 2)
  {
    return 1;
  }
  const size_t SHIFT_COUNT = 4;
  size_t size_dyn_array;
  const char* FILENAME = argv[1];
  try
  {
    size_dyn_array = siobko::InputDynamicArraySize();
    siobko::ManageWithArrays(SHIFT_COUNT, FILENAME, size_dyn_array);
  }
  catch (const std::logic_error& msg)
  {
    std::cout << msg.what() << '\n';
    return 1;
  }
  return 0;
}
