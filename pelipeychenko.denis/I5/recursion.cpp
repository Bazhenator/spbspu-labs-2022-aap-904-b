#include "recursion.h"
#include <iostream>

pelipeychenko::customString::customString(char *string, size_t size) :
  string_(string),
  size_(size),
  index_(0u) {}

pelipeychenko::customString::~customString() {
  delete[] string_;
}

bool pelipeychenko::customString::checkIfSign() {
  if (string_[index_] == '+' || string_[index_] == '-') {
    index_++;
    return true;
  }
  return false;
}

bool pelipeychenko::customString::checkIfDigit() {
  if (std::isdigit(string_[index_])) {
    index_++;
    return true;
  }
  return false;
}

bool pelipeychenko::customString::checkIfUnsignedInt() {
  if (checkIfDigit()) {
    checkIfUnsignedInt();
    return true;
  }
  return false;
}

bool pelipeychenko::customString::checkIfOrder() {
  if (string_[index_] == 'E') {
    index_++;
    checkIfSign();
    if (checkIfUnsignedInt()) {
      return true;
    }
  }
  return false;
}

bool pelipeychenko::customString::checkIfMantissa() {
  if (checkIfUnsignedInt() && string_[index_] == '.') {
    index_++;
    if (checkIfUnsignedInt()) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

bool pelipeychenko::customString::checkIfReal() {
  checkIfSign();
  if (checkIfMantissa() && checkIfOrder() && string_[index_] == '\0') {
    return true;
  }
  return false;
}
