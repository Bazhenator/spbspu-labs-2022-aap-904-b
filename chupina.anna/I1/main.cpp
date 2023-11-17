#include <iostream>
#include "divisionsCount.h"

int main() {
  int nextNumber = 1;
  int previousNumber = 0;
  int sequenceCount = 0;
  int answer = 0;
  try {
    while (nextNumber != 0) {
      std::cin >> nextNumber;
      answer = chupina::divisionsCount(nextNumber, previousNumber, sequenceCount, answer);
    }
    if (sequenceCount < 2) {
      std::cout << "The sequence contains less than two elements\n";
    } else {
      std::cout << answer << '\n';
    }
  } catch (const std::invalid_argument & e) {
    std::cout << e.what() << '\n';
    return 1;
  } catch (const std::overflow_error & e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  return 0;
}
