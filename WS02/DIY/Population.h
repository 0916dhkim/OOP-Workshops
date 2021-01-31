// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/01/30
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
  struct Row {
    char *postalCode;
    int population;
  };
  void sort();
  bool load(Row &r);
  bool load(const char *filename);
  int populationSum();
  void display(const Row &r);
  void display();
  void deallocateMemory();
}
#endif // SDDS_POPULATION_H_
