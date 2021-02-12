// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/11
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds {
  class LabelMaker {
    private:
      Label *m_labels;
      int m_count;
    public:
      LabelMaker(int noOfLabels);
      ~LabelMaker();
      void readLabels();
      void printLabels();
  };
};
#endif

