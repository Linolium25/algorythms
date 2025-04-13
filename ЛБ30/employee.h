#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    string department;
    int experience;
    double salary;

public:
    Employee(); 
    Employee(string n, string d, int e, double s);

    string getName() const;
    string getDepartment() const;
    int getExperience() const;
    double getSalary() const;

    friend void showAverageExperience(const vector<Employee>&);
    friend void sortByExperience(vector<Employee>&);
    friend void showDepartmentStats(const vector<Employee>&);
};

class Vacation {
private:
    Employee employee;
    string startDate;
    int days;
    string endDate;

public:
    Vacation(Employee e);
    void calculateVacation();
    void showVacationInfo() const;
};

#endif

