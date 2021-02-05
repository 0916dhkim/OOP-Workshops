// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/05
#ifndef CALORIELIST_H
#define CALORIELIST_H
#include "Food.h"

namespace sdds {
  class CalorieList {
    private:
      Food *m_food_items;

      // Size of the items array.
      int m_size;

      // Number of food items in the items array.
      int m_item_count;

      void printHeader() const;
      void printFooter() const;
      bool isValid() const;
      int totalCalories() const;
    public:
      CalorieList();
      void init(int size);
      bool add(const char *item_name, int calories, int when);
      void display() const;
      void deallocate();
  };
};
#endif

