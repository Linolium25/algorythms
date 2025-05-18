#include <iostream>
#include <cmath>
using namespace std;

class Figura {
public:
    virtual double ploshcha() = 0;
    virtual double perymetr() = 0;
    virtual ~Figura() {} // Віртуальний деструктор
};

class Pryamokutnyk : public Figura {
private:
    double dovzhyna, shyryna;
public:
    Pryamokutnyk(double d, double s) {
        dovzhyna = d;
        shyryna = s;
    }

    double ploshcha() {
        return dovzhyna * shyryna;
    }

    double perymetr() {
        return 2 * (dovzhyna + shyryna);
    }

    ~Pryamokutnyk() {}
};

class Trykutnyk : public Figura {
private:
    double a, b, c;
public:
    Trykutnyk(double stor1, double stor2, double stor3) {
        a = stor1;
        b = stor2;
        c = stor3;
    }

    double ploshcha() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c)); // Формула Herona
    }

    double perymetr() {
        return a + b + c;
    }

    ~Trykutnyk() {}
};

class Kolo : public Figura {
private:
    double radius;
public:
    Kolo(double r) {
        radius = r;
    }

    double ploshcha() {
        return 3.14159 * radius * radius;
    }

    double perymetr() {
        return 2 * 3.14159 * radius;
    }

    ~Kolo() {}
};

int main() {
    Figura* figury[3];

    cout << "Vvedit' dany dlya pryamokutnyka:\n";
    double d, s;
    cout << "Dovzhyna: ";
    cin >> d;
    cout << "Shyryna: ";
    cin >> s;
    figury[0] = new Pryamokutnyk(d, s);

    cout << "\nVvedit' dany dlya trykutnyka:\n";
    double a, b, c;
    cout << "Storona 1: ";
    cin >> a;
    cout << "Storona 2: ";
    cin >> b;
    cout << "Storona 3: ";
    cin >> c;
    figury[1] = new Trykutnyk(a, b, c);

    cout << "\nVvedit' radius kola:\n";
    double r;
    cout << "Radius: ";
    cin >> r;
    figury[2] = new Kolo(r);

    cout << "\n--- Rezul'taty obchyslen' ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "Figura #" << (i + 1) << ":\n";
        cout << "Ploshcha: " << figury[i]->ploshcha() << endl;
        cout << "Perymetr: " << figury[i]->perymetr() << endl;
        cout << "--------------------------\n";
    }

    for (int i = 0; i < 3; i++) {
        delete figury[i];
    }

    return 0;
}

