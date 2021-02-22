// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/21
#include "Mark.h"

using namespace sdds;

const int INVALID_MARK = -1;

bool Mark::isValid() const {
  return this->m_value != INVALID_MARK;
}

Mark::Mark() {
  this->m_value = 0;
}

Mark::Mark(int initial) {
  if (initial < 0 || initial > 100) {
    // Invalid.
    this->m_value = INVALID_MARK;
  } else {
    this->m_value = initial;
  }
}

Mark::operator int() const {
  if (!this->isValid()) {
    return 0;
  }
  return this->m_value;
}

Mark::operator double() const {
  if (!this->isValid()) {
    return 0;
  }

  if (0 <= this->m_value && this->m_value < 50) {
    return 0;
  }
  if (this->m_value < 60) {
    return 1.0;
  }
  if (this->m_value < 70) {
    return 2.0;
  }
  if (this->m_value < 80) {
    return 3.0;
  }
  return 4.0;
}

Mark::operator char() const {
  if (!this->isValid()) {
    return 'X';
  }

  if (0 <= this->m_value && this->m_value < 50) {
    return 'F';
  }
  if (this->m_value < 60) {
    return 'D';
  }
  if (this->m_value < 70) {
    return 'C';
  }
  if (this->m_value < 80) {
    return 'B';
  }
  return 'A';
}

Mark& Mark::operator+=(int amount) {
  if (!this->isValid()) {
    // This is not valid. No-op.
    return *this;
  }
  this->m_value += amount;
  if (this->m_value < 0 || this->m_value > 100) {
    // This became invalid.
    this->m_value = INVALID_MARK;
  }
  return *this;
}

Mark& Mark::operator=(int initial) {
  this->m_value = initial;
  if (this->m_value < 0 || this->m_value > 100) {
    // This became invalid.
    this->m_value = INVALID_MARK;
  }
  return *this;
}

int& sdds::operator+=(int& left, const Mark& right) {
  left += int(right);
  return left;
}

