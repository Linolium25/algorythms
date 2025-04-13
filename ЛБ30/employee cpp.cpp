#include "employee.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;

// ===== Конструктори Employee =====

Employee::Employee() {
    name = "";
    department = "";
    experience = 0;
    salary = 0.0;
}

Employee::Employee(string n, string d, int e, double s) {
    name = n;
    department = d;
    experience = e;
    salary = s;
}

string Employee::getName() const { return name; }
string Employee::getDepartment() const { return department; }
int Employee::getExperience() const { return experience; }
double Employee::getSalary() const { return salary; }

// ===== Дружні функції =====

void showAverageExperience(const vector<Employee>& workers) {
    if (workers.empty()) return;

    int total = 0;
    for (size_t i = 0; i < workers.size(); ++i)
        total += workers[i].experience;

    double avg = (double)total / workers.size();
    cout << "Serednii stazh: " << fixed << setprecision(2) << avg << " rokiv\n";
}

void sortByExperience(vector<Employee>& workers) {
    for (size_t i = 0; i < workers.size() - 1; ++i) {
        for (size_t j = i + 1; j < workers.size(); ++j) {
            if (workers[i].experience > workers[j].experience) {
                Employee temp = workers[i];
                workers[i] = workers[j];
                workers[j] = temp;
            }
        }
    }

    cout << "\nSpivrobitnyky vidsortovani za stazhem:\n";
    for (size_t i = 0; i < workers.size(); ++i) {
        cout << workers[i].name << " — " << workers[i].experience << " rokiv\n";
    }
}

void showDepartmentStats(const vector<Employee>& workers) {
    map<string, int> count;
    map<string, double> total;

    for (size_t i = 0; i < workers.size(); ++i) {
        count[workers[i].department]++;
        total[workers[i].department] += workers[i].salary;
    }

    cout << "\nStatystyka po viddilakh:\n";
    for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
        string dept = it->first;
        cout << "Viddil: " << dept
             << ", kilkist: " << count[dept]
             << ", zagalna zarplata: " << fixed << setprecision(2) << total[dept] << " hrn\n";
    }
}

// ===== Vacation =====

Vacation::Vacation(Employee e) {
    employee = e;
    startDate = "01.07.2021";
    calculateVacation();
}

void Vacation::calculateVacation() {
    int exp = employee.getExperience();
    double sal = employee.getSalary();

    if (exp < 10 && sal < 12000)
        days = 14;
    else if (exp > 25 && sal > 25000)
        days = 28;
    else
        days = 21;

    int endDay = 1 + days;
    int endMonth = 7;
    int endYear = 2021;

    if (endDay > 31) {
        endDay -= 31;
        endMonth++;
        if (endMonth > 12) {
            endMonth = 1;
            endYear++;
        }
    }

    ostringstream oss;
    if (endDay < 10) oss << "0";
    oss << endDay << ".";
    if (endMonth < 10) oss << "0";
    oss << endMonth << ".";
    oss << endYear;

    endDate = oss.str();
}

void Vacation::showVacationInfo() const {
    cout << "\nVidpustka dlia: " << employee.getName() << endl;
    cout << "Pochatok: " << startDate << endl;
    cout << "Trivalist: " << days << " dniv" << endl;
    cout << "Kinets: " << endDate << endl;
}

