// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#include "Shape.h"

using namespace sdds;
using namespace std;

Shape::~Shape(){};

ostream &operator<<(ostream &ostr, Shape &shape) {
  shape.draw(ostr);
  return ostr;
}

istream &operator>>(istream &istr, Shape &shape) {
  shape.getSpecs(istr);
  return istr;
}
