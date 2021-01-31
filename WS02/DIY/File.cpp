// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/01/30
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
    bool read(char postalCode[]) {
      return fscanf(fptr, "%[^,],", postalCode) == 1;
    }
    bool read(int &population) {
      return fscanf(fptr, "%d\n", &population) == 1;
    }
}
