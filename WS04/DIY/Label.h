// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/11
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include<iostream>
namespace sdds {
  const int MAX_LABEL_LENGTH = 70;
  class Label {
    private:
      char m_frame[8];
      char *m_content;
      void setContent(const char *content);
    public:
      Label();
      Label(const char *frameArg);
      Label(const char *frameArg, const char *content);
      ~Label();
      void readLabel();
      std::ostream &printLabel() const;
  };
};
#endif

