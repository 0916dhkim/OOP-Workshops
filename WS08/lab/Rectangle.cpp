// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#include "Rectangle.h"
#include <cstring>
#include <iomanip>

using namespace sdds;
using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle(const char *label, int width, int height)
    : LblShape(label), m_width(width), m_height(height) {
  if (label == nullptr || m_height < 3 || m_width < (int)strlen(label) + 2) {
    m_width = 0;
    m_height = 0;
  }
}

void Rectangle::getSpecs(istream &istr) {
  LblShape::getSpecs(istr);
  string s;
  istr >> m_width;
  getline(istr, s, ',');
  istr >> m_height;
  istr.ignore(1000, '\n');
}

void Rectangle::draw(ostream &ostr) const {
  if (m_width == 0 && m_height == 0) {
    // Empty state. No-op.
    return;
  }

  // First line.
  ostr << '+';
  for (int i = 0; i < m_width - 2; i++) {
    ostr << '-';
  }
  ostr << '+' << endl;

  // Second line.
  ostr << '|';
  ostr << setw(m_width - 2) << left << label() << '|' << endl;

  // Remaining lines.
  for (int i = 0; i < m_height - 3; i++) {
    ostr << '|';
    for (int j = 0; j < m_width - 2; j++) {
      ostr << ' ';
    }
    ostr << '|' << endl;
  }

  // Last line.
  ostr << '+';
  for (int i = 0; i < m_width - 2; i++) {
    ostr << '-';
  }
  ostr << '+';
}