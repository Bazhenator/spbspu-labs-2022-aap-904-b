#include <iostream>
#include "arrayClass.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: incorrect amount of CML args\n";
    return 2;
  }
  try {
    std::size_t sizeOfRandom;
    std::cin >> sizeOfRandom;
    pelipeychenko::Array randomArray{sizeOfRandom};
    randomArray.fillWithRandom();
    std::cout << randomArray.findCountLeftToMin() << "\n";

    pelipeychenko::Array fileArray(argv[argc - 1]);
    fileArray.fillFromFile(argv[argc - 1]);
    std::cout << fileArray.findCountLeftToMin() << "\n";
  }
  catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
