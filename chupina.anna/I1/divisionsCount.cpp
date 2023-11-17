#include "divisionsCount.h"
#include <iostream>
#include <limits>

void chupina::isInputCorrect() {
  if (std::cin.fail()) {
    throw std::invalid_argument("The elements of the sequence must me integer between -2147483647 and 2147483647");
  }
}

int chupina::divisionsCount(const int &nextNum, int &prevNum, int &seqCount, int answer) {
  chupina::isInputCorrect();
  const int MAX_INT = std::numeric_limits< int >::max();
  if (nextNum != 0) {
    if (MAX_INT - 1 >= seqCount) {
      seqCount++;
    } else {
      throw std::overflow_error("The number of the sequence length is overflow");
    }
    if (prevNum != 0) {
      if (nextNum % prevNum == 0) {
        if (MAX_INT - 1 >= answer) {
          answer++;
        } else {
          throw std::overflow_error("Answer is overflow");
        }
      }
    }
    prevNum = nextNum;
  }
  return answer;
}
