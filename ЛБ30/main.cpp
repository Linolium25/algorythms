#include "employee.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Employee> workers;

    workers.push_back(Employee("Ivan Ivanenko", "Informatyka", 3, 10000));
    workers.push_back(Employee("Olena Shevchenko", "Kadriv", 5, 8000));
    workers.push_back(Employee("Andrii Petrenko", "Informatyka", 27, 26000));
    workers.push_back(Employee("Kateryna Bondar", "Finansy", 12, 13000));

    cout << "===============================" << endl;
    cout << "1. Serednii stazh pratsivnykiv" << endl;
    cout << "===============================" << endl;
    showAverageExperience(workers);

    cout << "\n===============================" << endl;
    cout << "2. Sortuvannia za stazhem" << endl;
    cout << "===============================" << endl;
    sortByExperience(workers);

    cout << "\n===============================" << endl;
    cout << "3. Statystyka po viddilakh" << endl;
    cout << "===============================" << endl;
    showDepartmentStats(workers);

    cout << "\n===============================" << endl;
    cout << "4. Vidpustky pratsivnykiv" << endl;
    cout << "===============================" << endl;
    for (size_t i = 0; i < workers.size(); ++i) {
        Vacation vac(workers[i]);
        vac.showVacationInfo();
        cout << "-------------------------------" << endl;
    }

    return 0;
}

