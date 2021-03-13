// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/13
#include <iostream>
namespace sdds {
// Dynamic size double array.
class DynamicArrayList {
private:
  double *mElements{nullptr};
  unsigned mLength;
  unsigned mCapacity;

public:
  DynamicArrayList();
  DynamicArrayList(const DynamicArrayList &);
  ~DynamicArrayList();
  DynamicArrayList &operator=(const DynamicArrayList &);

  double &operator[](unsigned idx) const;
  unsigned length() const;
  void push(double value);
  void clear();
};

class Stats {
private:
  static double invalidIndexValue;
  char *mFileName{nullptr};
  DynamicArrayList mFields;
  unsigned mColumnWidth;
  unsigned mColumnCount;
  unsigned mPrecision;

  // Open file and load its content to this object.
  void openFile(const char *fileName);

public:
  Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4,
        unsigned precision = 2);
  Stats(const char *filename, unsigned columnWidth = 15,
        unsigned noOfColumns = 4, unsigned precision = 2);
  Stats(const Stats &);
  ~Stats();

  Stats &operator=(const Stats &);
  double &operator[](unsigned idx) const;
  operator bool() const;

  void sort(bool ascending);
  unsigned size() const;
  const char *name() const;
  void print(std::ostream &ostr) const;
  void occurrence(double min, double max, std::ostream &ostr = std::cout);
  void readFileName(std::istream &);
};

std::ostream &operator<<(std::ostream &, const Stats &);
std::istream &operator>>(std::istream &, Stats &);
} // namespace sdds
