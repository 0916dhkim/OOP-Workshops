// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/21
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
  class Mark {
    private:
      int m_value;
      bool isValid() const;
    public:
      Mark();
      Mark(int initial);

      operator int() const;
      operator double() const;
      operator char() const;
      Mark& operator+=(int amount);
      Mark& operator=(int initial);
      friend int& operator+=(int& left, const Mark& right);
  };
  int& operator+=(int& left, const Mark& right);
};

#endif
