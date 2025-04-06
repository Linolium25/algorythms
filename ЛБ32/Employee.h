#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string surname;
    std::string department;
    int yearOfEmployment;
    float salary;
    float bonus;

public:
    Employee();  // конструктор за замовчуванням
    Employee(std::string s, std::string d, int y, float sa);  // параметричний конструктор

    void inputEmployee();
    void printEmployee() const;
    void calculateBonus(int currentYear);
    int experience(int currentYear) const;
};

void bubbleSortEmployees(Employee* employees, int n, int currentYear);
float averageExperience(Employee* employees, int n, int currentYear);

#endif // EMPLOYEE_H

