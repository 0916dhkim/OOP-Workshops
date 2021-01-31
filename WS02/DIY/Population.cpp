// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/01/30
#include "Population.h"
#include "File.h"
#include "cstring.h"
#include <iostream>

using namespace std;
namespace sdds {

  int numRows;
  Row *rows;

   void sort() {
      int i, j;
      Row temp;
      for (i = numRows - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (rows[j].population > rows[j + 1].population) {
               temp = rows[j];
               rows[j] = rows[j + 1];
               rows[j + 1] = temp;
            }
         }
      }
   }

   bool load(const char *filename) {
      bool ok = false;
      int i = 0;
      if (openFile(filename)) {
          numRows = noOfRecords();
          rows = new Row[numRows];
          for (i = 0; i < numRows && load(rows[i]); i++);
          if (i != numRows) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
          } else {
              ok = true;
          }
          closeFile();
      }
      else {
         cout << "Could not open data file: " << filename << endl;
      }
      return ok;
   }

   bool load(Row &r) {
      bool ok = false;
      char postalCode[4];
      if (read(postalCode) && read(r.population)) {
          r.postalCode = new char[4];
          strCpy(r.postalCode, postalCode);
          ok = true;
      }
      return ok;
   }

   int populationSum() {
     int sum = 0;
     for (int i = 0; i < numRows; i++) {
       sum += rows[i].population;
     }
     return sum;
   }

   void display() {
     cout << "Postal Code: population" << endl
       << "-------------------------" << endl;
      sort();
      for (int i = 0; i < numRows; i++) {
          cout << i + 1 << "- ";
          display(rows[i]);
      }
      cout << "-------------------------" << endl
        << "Population of Canada: " << populationSum() << endl;
   }

   void display(const Row &r) {
      cout
        << r.postalCode << ": "
        << r.population << endl;
   }

   void deallocateMemory() {
     for (int i = 0; i < numRows; i++) {
       delete[] rows[i].postalCode;
     }
     delete[] rows;
   }
}
