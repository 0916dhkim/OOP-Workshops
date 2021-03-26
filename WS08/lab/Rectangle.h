// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds {
class Rectangle : public LblShape {
private:
  int m_width{0};
  int m_height{0};

public:
  Rectangle();
  Rectangle(const char *label, int width, int height);
  void getSpecs(std::istream &) override;
  void draw(std::ostream &) const override;
};
} // namespace sdds
#endif
