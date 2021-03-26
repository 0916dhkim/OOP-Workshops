// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#include "Line.h"

using namespace sdds;
using namespace std;

Line::Line() {}

Line::Line(const char *label, int length) : LblShape(label), m_length(length) {}

void Line::getSpecs(istream &istr) {
  LblShape::getSpecs(istr);
  string rest;
  istr >> m_length;
  istr.ignore(1000, '\n');
}

void Line::draw(ostream &ostr) const {
  if (m_length == 0)
    return;
  ostr << label() << endl;
  for (int i = 0; i < m_length; i++) {
    ostr << '=';
  }
}
