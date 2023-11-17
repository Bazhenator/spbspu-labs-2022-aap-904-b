#include "ManageArrays.h"
#include <iostream>
#include <cstddef>
#include "Struct_Array.h"

void siobko::ManageWithArrays(const size_t ShiftCount, const char *FILENAME, size_t SIZE_DYN_ARRAY)
{
  siobko::Array Dynamic_Array_From_File(FILENAME);
  if (Dynamic_Array_From_File.size)
  {
    Dynamic_Array_From_File.rshift(ShiftCount);
    std::cout << "Shifted Dynamic Array From File" << '\n';
    for (size_t i = 0u; i < Dynamic_Array_From_File.size; ++i)
    {
      std::cout << Dynamic_Array_From_File[i] << " ";
    }
    std::cout << '\n';
  }
  if (SIZE_DYN_ARRAY)
  {
    siobko::Array Dynamic_Array(SIZE_DYN_ARRAY);
    Dynamic_Array.rshift(ShiftCount);
    std::cout << "Shifted Simple Dynamic Array" << '\n';
    for (size_t i = 0u; i < Dynamic_Array.size; ++i)
    {
      std::cout << Dynamic_Array[i] << " ";
    }
    std::cout << '\n';
  }
  const size_t SIZE_STAT_ARRAY = 10;
  int Stat_Array[SIZE_STAT_ARRAY] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Stat Array Shift" << '\n';
  for (size_t i = SIZE_STAT_ARRAY - ShiftCount; i <= 2 * SIZE_STAT_ARRAY - ShiftCount - 1; i++)
  {
    std::cout << Stat_Array[i % SIZE_STAT_ARRAY] << " ";
  }
  std::cout << '\n';
}
