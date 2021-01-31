// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/01/30
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          for (i = 0; i < noOfEmployees && load(employees[i]); i++);
          if (i != noOfEmployees) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
          } else {
              ok = true;
          }
          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   bool load(Employee &theEmployee) {
      bool ok = false;
      char name[128];
      if (read(theEmployee.m_empNo) && read(theEmployee.m_salary) && read(name)) {
          theEmployee.m_name = new char[strLen(name) + 1];
          strCpy(theEmployee.m_name, name);
          ok = true;
      }
      return ok;
   }

   void display() {
      cout << "Employee Salary report, sorted by employee number" << endl
          << "no- Empno, Name, Salary" << endl
          << "------------------------------------------------" << endl;
      sort();
      for (int i = 0; i < noOfEmployees; i++) {
          cout << i + 1 << "- ";
          display(employees[i]);
      }
   }

   void display(const Employee &theEmployee) {
      cout
        << theEmployee.m_empNo << ": "
        << theEmployee.m_name << ", "
        << theEmployee.m_salary << endl;
   }

   void deallocateMemory() {
     for (int i = 0; i < noOfEmployees; i++) {
       delete[] employees[i].m_name;
     }
     delete[] employees;
   }
}
