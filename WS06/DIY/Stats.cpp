// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/03/13
#include "Stats.h"
#include "cstring.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <string>
using namespace std;

namespace sdds {
void copyFile(const char *destFileName, const char *sourceFileName) {
  if (sourceFileName == nullptr || destFileName == nullptr)
    return;

  ifstream fin(sourceFileName);
  ofstream fout(destFileName);
  char ch;
  while (fin.get(ch))
    fout << ch;
}

DynamicArrayList::DynamicArrayList() { this->clear(); }

DynamicArrayList::DynamicArrayList(const DynamicArrayList &other) {
  mElements = new double[other.mCapacity];
  mLength = other.mLength;
  mCapacity = other.mCapacity;

  // Copy data.
  for (unsigned i = 0; i < mLength; i++) {
    mElements[i] = other.mElements[i];
  }
}

DynamicArrayList::~DynamicArrayList() {
  delete[] mElements;
}

DynamicArrayList &DynamicArrayList::operator=(const DynamicArrayList &other) {
  delete[] mElements;
  mElements = new double[other.mCapacity];
  mLength = other.mLength;
  mCapacity = other.mCapacity;

  // Copy data.
  for (unsigned i = 0; i < mLength; i++) {
    mElements[i] = other.mElements[i];
  }

  return *this;
}

double &DynamicArrayList::operator[](unsigned int idx) const {
  return mElements[idx];
}

unsigned DynamicArrayList::length() const { return mLength; }

void DynamicArrayList::push(double value) {
  if (mLength == mCapacity) {
    // Capacity full.
    // Increase capacity.
    double *old = mElements;
    mCapacity *= 2;
    double *next = new double[mCapacity];
    for (unsigned i = 0; i < mLength; i++) {
      next[i] = old[i];
    }

    // Free old.
    delete[] old;

    // Set mElements.
    mElements = next;
  }
  mElements[mLength++] = value;
}

void DynamicArrayList::clear() {
  delete[] mElements;
  // Make single capacity empty list.
  mElements = new double[1];
  mLength = 0;
  mCapacity = 1;
}

double Stats::invalidIndexValue = 0;

void Stats::openFile(const char *fileName) {
  if (fileName == nullptr) {
    return;
  }

  ifstream ifs;
  ifs.open(fileName, ifstream::in);
  if (!ifs) {
    // Failed to open the file.
    mFileName = nullptr;
    ifs.close();
    return;
  }

  // File open successful.
  // Set filename.
  if (mFileName != fileName) {
    delete[] mFileName;
    mFileName = new char[strLen(fileName) + 1];
    strCpy(mFileName, fileName);
  }

  // Clear existing numbers.
  mFields.clear();

  // Read numbers.
  string field;
  while (getline(ifs, field, ',')) {
    mFields.push(stod(field));
  }

  ifs.close();
}

Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
  mColumnWidth = columnWidth;
  mColumnCount = noOfColumns;
  mPrecision = precision;
}

Stats::Stats(const char *filename, unsigned columnWidth, unsigned noOfColumns,
             unsigned precision) {
  mColumnWidth = columnWidth;
  mColumnCount = noOfColumns;
  mPrecision = precision;

  openFile(filename);
}

Stats::Stats(const Stats &other) {
  mColumnWidth = other.mColumnWidth;
  mColumnCount = other.mColumnCount;
  mPrecision = other.mPrecision;

  if (other) {
    // New file name is the original name appended by "C_".
    char *nameOfCopy = new char[strLen(other.mFileName) + 3];
    strCpy(nameOfCopy, "C_");
    strCpy(nameOfCopy + 2, other.mFileName);

    // Copy file content.
    copyFile(nameOfCopy, other.mFileName);
    openFile(nameOfCopy);

    // Cleanup.
    delete[] nameOfCopy;
  }
}

Stats::~Stats() {
  delete[] mFileName;
}

Stats &Stats::operator=(const Stats &other) {
  if (!*this || !other)
    return *this;

  // Copy attributes.
  mColumnWidth = other.mColumnWidth;
  mColumnCount = other.mColumnCount;
  mPrecision = other.mPrecision;

  // Copy file content.
  copyFile(mFileName, other.mFileName);
  openFile(mFileName);

  return *this;
}

double &Stats::operator[](unsigned int idx) const {
  if (!*this)
    return invalidIndexValue;
  return mFields[idx % mFields.length()];
}

Stats::operator bool() const { return mFileName != nullptr; }

// Recursive quick sort implementation.
void quickSort(DynamicArrayList &list, int low, int high,
               bool ascending) {
  if (low < high) {
    // Partition.
    double pivotValue = list[high];
    int i = low - 1;
    double temp;

    for (int j = low; j < high; j++) {
      if (!ascending ^ (list[j] < pivotValue)) {
        i++;
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }

    int k = i + 1;

    temp = list[k];
    list[k] = list[high];
    list[high] = temp;

    // Recurse each partition.
    quickSort(list, low, k - 1, ascending);
    quickSort(list, k + 1, high, ascending);
  }
}

void Stats::sort(bool ascending) {
  if (!*this) return;
  quickSort(mFields, 0, mFields.length() - 1, ascending);
}

unsigned Stats::size() const { return mFields.length(); }

const char *Stats::name() const { return mFileName; }

void Stats::print(ostream &ostr) const {
  if (!*this)
    return;

  // Print header.
  ostr << mFileName << endl;
  unsigned fileNameLength = strLen(mFileName);
  for (unsigned i = 0; i < fileNameLength; i++) {
    ostr << '=';
  }
  ostr << endl;

  // Print table.
  ostr.precision(mPrecision);
  ostr << fixed;
  for (unsigned i = 0; i < mFields.length();
       i++) {
    if (i % mColumnCount == 0)
      ostr << endl;
    ostr << setw(mColumnWidth) << right << mFields[i];
  }
  ostr << endl;
  ostr << "Total of " << size() << " listed!" << endl;
}

void Stats::occurrence(double min, double max, std::ostream &ostr) {
  if (!*this) return;

  unsigned count = 0;

  ostr.precision(mPrecision);
  ostr << fixed;
  for (unsigned i = 0; i < mFields.length(); i++) {
    if (min < mFields[i] && mFields[i] < max) {
      if (count % mColumnCount == 0)
        ostr << endl;

      ostr << setw(mColumnWidth) << right << mFields[i];
      count++;
    }
  }
  ostr << endl;
  ostr << "Total of " << count << " numbers are between ";
  ostr << min << " and " << max << endl;
}

void Stats::readFileName(std::istream &istr) {
  string input;
  getline(istr, input);
  input.erase(input.find_last_not_of(" \n\r\t") + 1);

  openFile(input.c_str());
}

ostream &operator<<(ostream &ostr, const Stats &stats) {
  stats.print(ostr);
  return ostr;
}

istream &operator>>(istream &istr, Stats &stats) {
  stats.readFileName(istr);
  return istr;
}
} // namespace sdds
