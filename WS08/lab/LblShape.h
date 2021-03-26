// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/26
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds {
class LblShape : public Shape {
private:
  char *m_label{nullptr};

protected:
  const char *label() const;

public:
  LblShape();
  LblShape(const char *label);
  virtual ~LblShape();
  LblShape(const LblShape &) = delete;
  LblShape &operator=(const LblShape &) = delete;
  void getSpecs(std::istream &) override;
};
} // namespace sdds

#endif
