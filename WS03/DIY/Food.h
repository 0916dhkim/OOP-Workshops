// Name: Donghyeon Kim
// Email: dkim167@myseneca.ca
// ID: 151613197
// Date: 2021/02/05
#ifndef FOOD_H
#define FOOD_H
namespace sdds {
  const int FOOD_NAME_LENGTH = 31;

  class Food {
    private:
      char m_name[FOOD_NAME_LENGTH];
      int m_calories;
      int m_time_of_consumption;
    public:
      Food();
      void set(const char *name, const int calories, const int timeOfConsumption);
      bool isValid() const;
      void display() const;

      // Return time of consumption as a const string.
      const char *timeOfConsumption() const;
      int calories() const;
  };
};
#endif

