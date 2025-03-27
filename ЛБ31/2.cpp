#include <iostream>
#include <vector>
using namespace std;

class People {
public:
    string surname, country, gender, education;
    int birthYear, age;

    People() {
        surname = "Невідомо";
        country = "Україна";
        gender = "Невідомо";
        education = "Середня";
        birthYear = 2006;
        age = 2024 - birthYear;
    }

    People(string s, string g, string e, int by) {
        surname = s;
        country = "Україна";
        gender = g;
        education = e;
        birthYear = by;
        age = 2024 - birthYear;
    }

    People(const People &p) {
        surname = p.surname;
        country = p.country;
        gender = p.gender;
        education = p.education;
        birthYear = p.birthYear;
        age = p.age;
    }

    void input() {
        cout << "Прізвище: ";
        cin >> surname;
        cout << "Стать (ч/ж): ";
        cin >> gender;
        cout << "Освіта: ";
        cin >> education;
        cout << "Рік народження: ";
        cin >> birthYear;
        age = 2024 - birthYear;
    }

    void display() {
        cout << surname << ", " << gender << ", Освіта: " << education 
             << ", Вік: " << age << " років" << endl;
    }
};

int main() {
    vector<People> peopleList = {
        People("Іваненко", "ч", "Вища", 1995),
        People("Петренко", "ж", "Середня", 2001),
        People("Сидорчук", "ч", "Вища", 1987)
    };

    // Додаємо нового користувача
    People newPerson;
    cout << "\nВведіть дані для нової людини:\n";
    newPerson.input();
    peopleList.push_back(newPerson);

    // Виведення списку
    cout << "\nСписок усіх людей:\n";
    for (People &p : peopleList) p.display();

    // Фільтрація за освітою і віком
    int minAge;
    cout << "\nВведіть мінімальний вік для пошуку осіб з вищою освітою: ";
    cin >> minAge;
    cout << "\nОсоби з вищою освітою і віком > " << minAge << ":\n";
    for (People &p : peopleList) {
        if (p.education == "Вища" && p.age > minAge) p.display();
    }

    // Видалення за статтю
    string genderToRemove;
    cout << "\nВведіть стать для видалення (ч/ж): ";
    cin >> genderToRemove;
    for (int i = 0; i < peopleList.size(); i++) {
        if (peopleList[i].gender == genderToRemove) {
            peopleList.erase(peopleList.begin() + i);
            i--;  
        }
    }

    // Виведення списку після видалення
    cout << "\nСписок після видалення осіб статі " << genderToRemove << ":\n";
    for (People &p : peopleList) p.display();

    // Копіюємо першого і додаємо в початок
    if (!peopleList.empty()) {
        People copyPerson = peopleList[0];
        peopleList.insert(peopleList.begin(), copyPerson);
    }

    // Виведення після копіювання
    cout << "\nСписок після копіювання першої людини:\n";
    for (People &p : peopleList) p.display();

    return 0;
}

