// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/05
#include "Food.h"
#include <iostream>
#include <iomanip>

using namespace sdds;
using namespace std;

const char BREAKFAST[] = "Breakfast";
const char LUNCH[] = "Lunch";
const char SNACK[] = "Snack";
const char DINNER[] = "Dinner";

Food::Food() {
  // Default empty state.
  this->m_name[0] = '\0';
  this->m_calories = -1;
  this->m_time_of_consumption = 0;
}

void Food::set(const char *name, const int calories, const int timeOfConsumption) {
  // Copy name.
  if (name != nullptr) {
    int i;
    for (i = 0; name[i] != '\0' && i < FOOD_NAME_LENGTH - 1; i++) this->m_name[i] = name[i];
    this->m_name[i] = '\0';
  }

  this->m_calories = calories;
  this->m_time_of_consumption = timeOfConsumption;
}

bool Food::isValid() const {
  if (this->m_name[0] == '\0') return false;
  if (this->m_calories < 0 || this->m_calories > 3000) return false;
  if (this->m_time_of_consumption < 1 || this->m_time_of_consumption > 4) return false;

  return true;
}

const char *Food::timeOfConsumption() const {
  switch (this->m_time_of_consumption) {
    case 1: return BREAKFAST;
    case 2: return LUNCH;
    case 3: return DINNER;
    default: return SNACK;
  }
}

int Food::calories() const { return this->m_calories; }

void Food::display() const {
  if (!this->isValid()) {
    // Invalid.
    cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
  } else {
    // Valid.
    cout << "| ";
    cout << setw(FOOD_NAME_LENGTH - 1) << setfill('.') << left << this->m_name << setfill(' ');
    cout << " | ";
    cout << setw(4) << right << this->m_calories;
    cout << " | ";
    cout << setw(10) << left << this->timeOfConsumption();
    cout << " |" << endl;
  }
}
