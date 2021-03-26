// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds {
class Shape {
public:
  virtual ~Shape();

  virtual void draw(std::ostream &) const = 0;
  virtual void getSpecs(std::istream &) = 0;
};
} // namespace sdds

std::ostream &operator<<(std::ostream &, sdds::Shape &);
std::istream &operator>>(std::istream &, sdds::Shape &);
#endif
