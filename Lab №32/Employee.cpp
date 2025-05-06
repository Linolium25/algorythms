#include "Employee.h"
#include <iostream>

Employee::Employee()
    : surname("Smith"), department("Finance"), yearOfEmployment(2010), salary(15000), bonus(0) {}

Employee::Employee(std::string s, std::string d, int y, float sa)
    : surname(s), department(d), yearOfEmployment(y), salary(sa), bonus(0) {}

void Employee::inputEmployee() {
    std::cout << "Input surname: ";
    std::cin >> surname;
    std::cout << "Department: ";
    std::cin >> department;
    std::cout << "Year of Employment: ";
    std::cin >> yearOfEmployment;
    std::cout << "Salary: ";
    std::cin >> salary;
}

void Employee::printEmployee() const {
    std::cout << "\nSurname: " << surname
              << "\nDepartment: " << department
              << "\nYear of Employment: " << yearOfEmployment
              << "\nSalary: " << salary
              << "\nBonus: " << bonus << std::endl;
}

void Employee::calculateBonus(int currentYear) {
    int experience = currentYear - yearOfEmployment;
    if (experience <= 10) {
        bonus = salary * 0.10f;
    } else if (experience <= 20) {
        bonus = salary * 0.25f;
    } else {
        bonus = salary * 0.40f;
    }
}

int Employee::experience(int currentYear) const {
    return currentYear - yearOfEmployment;
}

void bubbleSortEmployees(Employee* employees, int n, int currentYear) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (employees[j].experience(currentYear) > employees[j + 1].experience(currentYear)) {
                std::swap(employees[j], employees[j + 1]);
            }
        }
    }
}

float averageExperience(Employee* employees, int n, int currentYear) {
    int totalExperience = 0;
    for (int i = 0; i < n; ++i) {
        totalExperience += employees[i].experience(currentYear);
    }
    return static_cast<float>(totalExperience) / n;
}
