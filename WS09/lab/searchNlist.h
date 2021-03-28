// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/27
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include "Collection.h"
#include <iostream>
namespace sdds {
template <typename P, typename Q>
bool search(Collection<P> &collection, P *array, int count, Q key) {
  bool res = false;
  for (int i = 0; i < count; i++) {
    if (array[i] == key) {
      collection.add(array[i]);
      res = true;
    }
  }
  return res;
}

template <typename T>
void listArrayElements(const char *title, const T *array, int count) {
  std::cout << title << std::endl;

  for (int i = 0; i < count; i++) {
    std::cout << (i + 1) << ": " << array[i] << std::endl;
  }
}
} // namespace sdds
#endif
