#include "Struct_Array.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstddef>

siobko::Array::Array(size_t size) : data(new int[size]),
size(size),
capacity(size)
{
}
siobko::Array::Array(const char* FileName)
{
  size_t it = 0u;
  std::ifstream DataFromFile(FileName);
  if (!DataFromFile.is_open())
  {
    throw std::logic_error("Error with input txt");
  }
  DataFromFile >> size;
  if (DataFromFile.fail())
  {
    throw std::logic_error("Invalid input arguments from file");
  }
  capacity = size;
  data = new int[size];
  while (!DataFromFile.eof() && DataFromFile >> data[it++])
  {
    if (DataFromFile.fail())
    {
      throw std::logic_error("Elements of array must be integers");
    }
  }
  DataFromFile.close();
}
siobko::Array::~Array()
{
  delete[] data;
}
int& siobko::Array::operator[](size_t index)
{
  return data[index];
}
void siobko::Array::GenerateRandomArray()
{
  std::srand(std::time(nullptr));
  for (size_t i = 0u; i < size; ++i)
  {
    data[i] = std::rand();
  }
}
void siobko::Array::rshift(size_t ShiftCount)
{
  size_t index = 0u;
  ShiftCount %= size;
  int* tmp = new int[size];
  for (size_t i = 0u; i < size; ++i)
  {
    tmp[i] = data[i];
  }
  for (size_t i = size - ShiftCount; i <= 2 * size - ShiftCount - 1; i++)
  {
    data[index++] = tmp[i % size];
  }
  delete[] tmp;
}
