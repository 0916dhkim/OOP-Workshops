// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/21
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
     return this->m_number > 0;
   }

   Account::operator int() const {
     return this->m_number;
   }

   Account::operator double() const {
     return this->m_balance;
   }

   bool Account::operator~() const {
     return this->m_number == 0;
   }

   Account& Account::operator=(int number) {
     if (this->m_number != 0) {
       // This is not new. No-op.
       return *this;
     }

     this->setEmpty();
     if (number >= 10000 && number <= 99999) {
       this->m_number = number;
     }
     return *this;
   }

   Account& Account::operator=(Account &right) {
     if (this->m_number != 0) {
       // This is not new. No-op.
       return *this;
     }
     if (!right) {
       // Right hand side is not valid. No-op.
       return *this;
     }

     // Set this.
     this->m_number = right.m_number;
     this->m_balance = right.m_balance;

     // Reset right hand side.
     right.m_number = 0;
     right.m_balance = 0;

     return *this;
   }

   Account& Account::operator+=(double amount) {
     if (!*this) {
       // This is not valid. No-op.
       return *this;
     }
     if (amount < 0) {
       // Amount is negative. No-op.
       return *this;
     }

     this->m_balance += amount;
     return *this;
   }

   Account& Account::operator-=(double amount) {
     if (!*this) {
       // This is not valid. No-op.
       return *this;
     }
     if (amount < 0) {
       // Amount is negative. No-op.
       return *this;
     }
     if (amount > this->m_balance) {
       // Insufficient balance. No-op.
       return *this;
     }

     this->m_balance -= amount;
     return *this;
   }

   Account& Account::operator<<(Account& right) {
     if (!*this || !right) {
       // Either account is not valid. No-op.
       return *this;
     }
     if (this->m_number == right.m_number) {
       // This is the same account as the right hand side. No-op.
       return *this;
     }

     this->m_balance += right.m_balance;
     right.m_balance = 0;
     return *this;
   }

   Account& Account::operator>>(Account& right) {
     if (!*this || !right) {
       // Either account is not valid. No-op.
       return *this;
     }
     if (this->m_number == right.m_number) {
       // This is the same account as the right hand side. No-op.
       return *this;
     }

     right.m_balance += this->m_balance;
     this->m_balance = 0;
     return *this;
   }

   double operator+(const Account& left, const Account& right) {
     if (!left || !right) {
       // Either account is not valid.
       return 0;
     }
     return left.m_balance + right.m_balance;
   }

   double& operator+=(double& left, const Account& right) {
     if (!right) {
       // The account is not valid.
       return left;
     }
     left += right.m_balance;
     return left;
   }
}
