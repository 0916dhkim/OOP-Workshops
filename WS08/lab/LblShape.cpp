// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#include "LblShape.h"
#include <cstring>
#include <string>

using namespace sdds;
using namespace std;

const char *LblShape::label() const { return m_label; }

LblShape::LblShape() {}

LblShape::LblShape(const char *label) {
  if (label == nullptr)
    return;

  m_label = new char[strlen(label) + 1];
  strcpy(m_label, label);
}

LblShape::~LblShape() { delete[] m_label; }

void LblShape::getSpecs(istream &istr) {
  string field;
  getline(istr, field, ',');

  delete[] m_label;
  m_label = new char[field.length() + 1];
  strcpy(m_label, field.c_str());
}
