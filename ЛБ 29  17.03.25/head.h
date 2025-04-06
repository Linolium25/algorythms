#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string surname;
    string department;
    int yearOfEmployment;
    float salary;
    float bonus;

public:
    Employee(); 
    Employee(string s, string d, int y, float sa); 

    void input_Employee();
    void print_Employee(); 
    void calculate_bonus_Employee(int current_year); 
    int experience_Employee(int current_year); 
};

float average_experience_Employee(Employee* employees, int n, int current_year); 
void buble_sort_Employee(Employee* employees, int n, int current_year); 

#endif

