// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/05
#include "CalorieList.h"
#include <iostream>
#include <iomanip>

using namespace sdds;
using namespace std;

CalorieList::CalorieList() {
  this->m_food_items = nullptr;
  this->m_size = 0;
  this->m_item_count = 0;
}

void CalorieList::init(int size) {
  this->m_food_items = new Food[size];
  this->m_size = size;
  this->m_item_count = 0;
}

void CalorieList::deallocate() {
  delete[] this->m_food_items;
}

bool CalorieList::add(const char *item_name, int calories, int when) {
  if (this->m_item_count < this->m_size) {
    this->m_food_items[this->m_item_count].set(item_name, calories, when);
    this->m_item_count++;
    return true;
  }
  return false;
}

bool CalorieList::isValid() const {
  if (this->m_food_items == nullptr) return false;
  if (this->m_size <= 0) return false;
  if (this->m_item_count != this->m_size) return false;
  for (int i = 0; i < this->m_size; i++)
    if (!this->m_food_items[i].isValid()) return false;
  return true;
}

int CalorieList::totalCalories() const {
  if (!this->isValid()) return 0;
  int sum = 0;
  for (int i = 0; i < this->m_item_count; i++) sum += this->m_food_items[i].calories();
  return sum;
}

void CalorieList::printHeader() const {
  cout << "+----------------------------------------------------+" << endl;
  if (!this->isValid()) {
    cout << "| Invalid Calorie Consumption list                   |" << endl;
  } else {
    cout << "|  Daily Calorie Consumption                         |" << endl;
  }
  cout << "+--------------------------------+------+------------+" << endl;
  cout << "| Food name                      | Cals | When       |" << endl;
  cout << "+--------------------------------+------+------------+" << endl;
}

void CalorieList::printFooter() const {
  cout << "+--------------------------------+------+------------+" << endl;
  if (!this->isValid()) {
    cout << "|    Invalid Calorie Consumption list                |" << endl;
  } else {
    cout << "|    Total Calories for today: ";
    cout << setw(8) << right << this->totalCalories();
    cout << " |            |" << endl;
  }
  cout << "+----------------------------------------------------+" << endl;
}

void CalorieList::display() const {
  this->printHeader();
  for (int i = 0; i < this->m_size; i++) this->m_food_items[i].display();
  this->printFooter();
}

