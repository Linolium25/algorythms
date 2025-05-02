#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Shkolyar {
protected:
    string pip;        
    int birthYear;      
    string gender;     

public:
    // Конструктор за замовчуванням
    Shkolyar() {
        pip = "Nevidomyy";
        birthYear = 2000;
        gender = "ch";
    }

    // Конструктор з параметрами
    Shkolyar(string p, int year, string g) {
        pip = p;
        birthYear = year;
        gender = g;
    }

    // Метод обчислення віку
    int calculateAge() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return currentYear - birthYear;
    }

    // Метод для виведення інформації
    void showInfo() {
        cout << "PIP: " << pip << endl;
        cout << "Rik narodzhennya: " << birthYear << endl;
        cout << "Stat': " << gender << endl;
        cout << "Vik: " << calculateAge() << " rokiv" << endl;
    }
};

// ===== Похідний клас: Працівник =====
class Pratsivnyk : public Shkolyar {
private:
    double salary;
    string jobPlace;

public:
    // Параметризований конструктор
    Pratsivnyk(string p, int year, string g, double s, string job)
        : Shkolyar(p, year, g) {
        salary = s;
        jobPlace = job;
    }

    // Метод для виведення інформації
    void showFullInfo() {
        showInfo();
        cout << "Zarplata: " << salary << " hrn" << endl;
        cout << "Mistse roboty: " << jobPlace << endl;
    }
};


int main() {
  
    const int nSh = 3;
    Shkolyar shkolyari[nSh] = {
        Shkolyar("Ivanenko Ivan Ivanovych", 2006, "ch"),
        Shkolyar("Shevchenko Olena Mykolaivna", 2007, "zh"),
        Shkolyar("Koval Andriy Serhiyovych", 2005, "ch")
    };

    cout << "== Spysok shkolyariv ==" << endl;
    for (int i = 0; i < nSh; i++) {
        cout << "--- Shkolyar #" << (i + 1) << " ---" << endl;
        shkolyari[i].showInfo();
        cout << endl;
    }

    
    const int nPr = 3;
    Pratsivnyk pratsivnyky[nPr] = {
        Pratsivnyk("Petrenko Petro Petrovych", 1990, "ch", 18500, "TOV 'Innovatsii'"),
        Pratsivnyk("Melnyk Kateryna Volodymyrivna", 1995, "zh", 21300, "Bank 'Rozvytok'"),
        Pratsivnyk("Dmytrenko Oksana Yuriyivna", 1988, "zh", 19000, "Firma 'Tekhnika'")
    };

    cout << "== Spysok pratsivnykiv ==" << endl;
    for (int i = 0; i < nPr; i++) {
        cout << "--- Pratsivnyk #" << (i + 1) << " ---" << endl;
        pratsivnyky[i].showFullInfo();
        cout << endl;
    }

    return 0;
}

