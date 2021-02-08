// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/08
#include <ios>
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

const double PI = 3.14159265;

namespace sdds {
  void Canister::setToDefault() {
    this->m_hieght = 13.0;
    this->m_diameter = 10.0;
    this->m_contentVolume = 0;
    this->m_contentName = nullptr;
    this->m_usable = true;
  }

  void Canister::setName(const char *Cstr) {
    if (Cstr == nullptr) {
      this->m_contentName = nullptr;
    } else {
      int contentNameLength = strLen(Cstr);
      this->m_contentName = new char[contentNameLength + 1];
      strCpy(this->m_contentName, Cstr);
    }
  }

  Canister::Canister() {
    this->setToDefault();
  }

  Canister::Canister(const char *contentName) {
    this->setToDefault();
    this->setName(contentName);
  }

  Canister::Canister(
    double hieght,
    double diameter,
    const char *contentName
  ) {
    this->setToDefault();
    bool isValidHeight = hieght >= 10 && hieght <= 40;
    bool isValidDiameter = diameter >= 10 && diameter <= 30;
    if (isValidHeight && isValidDiameter) {
      this->m_hieght = hieght;
      this->m_diameter = diameter;
    } else {
      this->m_usable = false;
    }
    this->setName(contentName);
  }

  Canister::~Canister() {
    delete[] this->m_contentName;
  }

  double Canister::capacity() const {
    return PI * (this->m_hieght - 0.267) * (this->m_diameter / 2) * (this->m_diameter / 2);
  }

  bool Canister::isEmpty() const {
    return this->m_contentVolume < 0.00001;
  }

  bool Canister::hasSameContent(const Canister &C) const {
    if (this->m_contentName == nullptr || C.m_contentName == nullptr) {
      return false;
    }
    return strCmp(this->m_contentName, C.m_contentName) == 0;
  }

  void Canister::clear() {
    delete[] this->m_contentName;
    this->setName(nullptr);
    this->m_contentVolume = 0;
    this->m_usable = true;
  }

  double Canister::volume() const {
    return this->m_contentVolume;
  }

  Canister& Canister::setContent(const char *contentName) {
    if (contentName == nullptr) {
      this->m_usable = false;
    } else if (this->isEmpty()) {
      this->setName(contentName);
    } else if (this->m_contentName != nullptr && strCmp(this->m_contentName, contentName) != 0) {
      this->m_usable = false;
    }
    return *this;
  }

  Canister& Canister::pour(double quantity) {
    double nextVolume = this->m_contentVolume + quantity;
    if (nextVolume >= this->capacity()) {
      // Fits.
      this->m_usable = false;
    } else {
      // Does not fit.
      this->m_contentVolume = nextVolume;
    }
    return *this;
  }

  Canister& Canister::pour(Canister &other) {
    this->setContent(other.m_contentName);
    double capacity = this->capacity();
    double remainingVolume = capacity - this->m_contentVolume;
    if (remainingVolume < other.m_contentVolume) {
      // Does not fit.
      other.m_contentVolume -= remainingVolume;
      this->m_contentVolume = capacity;
    } else {
      // Fits.
      this->pour(other.m_contentVolume);
      other.m_contentVolume = 0;
    }
    return *this;
  }

  std::ostream& Canister::display() const {
    cout << setw(7) << right << setprecision(1) << fixed << this->capacity();
    cout << "cc (" << this->m_hieght << "x" << this->m_diameter << ") Canister";

    if (!this->m_usable) {
      cout << " of Unusable content, discard!";
    } else if (this->m_contentName != nullptr) {
      cout << " of ";
      cout << setw(7) << right << setprecision(1) << fixed << this->m_contentVolume;
      cout << "cc   ";
      cout << this->m_contentName;
    }
    return cout;
  }
}
