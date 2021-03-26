// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {
class Line : public LblShape {
private:
  int m_length{0};

public:
  Line();
  Line(const char *label, int length);
  void getSpecs(std::istream &) override;
  void draw(std::ostream &) const override;
};
} // namespace sdds

#endif
