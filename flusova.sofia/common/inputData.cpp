#include "inputData.h"
#include <iostream>

char* flusova::inputData(std::istream& cin, size_t& capacity)
{
  char* data = new char[capacity];
  size_t size = 0;
  cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newData = new char[capacity + 20];
        for (size_t i = 0; i != size; ++i)
        {
          newData[i] = data[i];
        }
        delete[] data;
        data = newData;
      } catch (const std::bad_alloc& e) {
        delete[] data;
        throw;
      }
      capacity += 20;
    }
    cin >> data[size];
  } while (cin && data[size++] != '\n');
  data[size == 0 ? size : size - 1] = '\0';
  if (!data[0]) {
    delete[] data;
    throw std::runtime_error("Empty line!");
  }
  return data;
}
