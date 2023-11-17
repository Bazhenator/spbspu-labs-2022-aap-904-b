#ifndef RECURSED_RECURSION_H
#define RECURSED_RECURSION_H

#include <cstddef>

namespace pelipeychenko {
  class customString {
  public:
    customString(char *string, size_t size);

    ~customString();

    bool checkIfSign();

    bool checkIfDigit();

    bool checkIfUnsignedInt();

    bool checkIfOrder();

    bool checkIfMantissa();

    bool checkIfReal();

  private:
    char *string_;
    std::size_t size_;
    std::size_t index_;

  };
}

#endif
