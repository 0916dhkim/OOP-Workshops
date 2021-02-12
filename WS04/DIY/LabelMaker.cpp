// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/11
#include "LabelMaker.h"
#include "Label.h"
#include <iostream>
using namespace sdds;
using namespace std;

LabelMaker::LabelMaker(int noOfLabels) {
  this->m_labels = new Label[noOfLabels];
  this->m_count = noOfLabels;
}

LabelMaker::~LabelMaker() {
  delete[] this->m_labels;
}

void LabelMaker::readLabels() {
  cout << "Enter " << this->m_count << " labels:" << endl;
  for (int i = 0; i < this->m_count; i++) {
    cout << "Enter label number " << (i + 1) << endl;
    cout << "> ";
    this->m_labels[i].readLabel();
  }
}

void LabelMaker::printLabels() {
  for (int i = 0; i < this->m_count; i++) {
    this->m_labels[i].printLabel();
  }
}

