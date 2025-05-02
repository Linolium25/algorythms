#include <iostream>
#include <string>

using namespace std;

class Dvyhun {
protected:
    double potuzhnist;
    string zavodNom;

public:
    // Конструктор за замовчуванням
    Dvyhun() {
        potuzhnist = 0.0;
        zavodNom = "0000";
        cout << "Stvoreno ob'yekt klasu Dvyhun (za zamovchuvannyam)" << endl;
    }

    // Параметризований конструктор
    Dvyhun(double p, string z) {
        potuzhnist = p;
        zavodNom = z;
        cout << "Stvoreno ob'yekt klasu Dvyhun (z parametramy)" << endl;
    }

    ~Dvyhun() {
        cout << "Znyshcheno ob'yekt klasu Dvyhun" << endl;
    }

    // Метод введення даних
    void vvesty() {
        cout << "Vvedit potuzhnist: ";
        cin >> potuzhnist;
        cout << "Vvedit zavodskyy nomer: ";
        cin >> zavodNom;
    }

    // Метод виведення даних
    void vyvesty() {
        cout << "Potuzhnist: " << potuzhnist << " kW" << endl;
        cout << "Zavodskyy nomer: " << zavodNom << endl;
    }
};

// === Похідний клас: Автомобіль ===
class Avtomobil : public Dvyhun {
    // Наслідування public: відкриває публічні методи базового класу для похідного класу
protected:
    string marka;
    double tsina;

public:
    // Конструктор за замовчуванням
    Avtomobil() : Dvyhun() {
        marka = "N/A";
        tsina = 0;
        cout << "Stvoreno ob'yekt klasu Avtomobil (za zamovchuvannyam)" << endl;
    }

    // Параметризований конструктор
    Avtomobil(string m, double t, double p, string z) : Dvyhun(p, z) {
        marka = m;
        tsina = t;
        cout << "Stvoreno ob'yekt klasu Avtomobil (z parametramy)" << endl;
    }

    // Деструктор
    ~Avtomobil() {
        cout << "Znyshcheno ob'yekt klasu Avtomobil" << endl;
    }

    // Метод введення
    void vvesty() {
        Dvyhun::vvesty();  // виклик методу базового класу
        cout << "Vvedit marku avtomobilya: ";
        cin >> marka;
        cout << "Vvedit tsinu: ";
        cin >> tsina;
    }

    // Метод виведення
    void vyvesty() {
        Dvyhun::vyvesty();  // виведення даних двигуна
        cout << "Marka: " << marka << endl;
        cout << "Tsina: " << tsina << " hrn" << endl;
    }
};

// === Похідний клас: Вантажівка ===
class Vantazhivka : public Avtomobil {
protected:
    double vantazhopidyomnist;

public:
    // Конструктор за замовчуванням
    Vantazhivka() : Avtomobil() {
        vantazhopidyomnist = 0;
        cout << "Stvoreno ob'yekt klasu Vantazhivka (za zamovchuvannyam)" << endl;
    }

    // Параметризований конструктор
    Vantazhivka(string m, double t, double p, string z, double v) 
        : Avtomobil(m, t, p, z) {
        vantazhopidyomnist = v;
        cout << "Stvoreno ob'yekt klasu Vantazhivka (z parametramy)" << endl;
    }

    // Деструктор
    ~Vantazhivka() {
        cout << "Znyshcheno ob'yekt klasu Vantazhivka" << endl;
    }

    // Метод введення
    void vvesty() {
        Avtomobil::vvesty();
        cout << "Vvedit vantazhopidyomnist (kg): ";
        cin >> vantazhopidyomnist;
    }

    // Метод виведення
    void vyvesty() {
        Avtomobil::vyvesty();
        cout << "Vantazhopidyomnist: " << vantazhopidyomnist << " kg" << endl;
    }
};

// === Головна функція ===
int main() {
    const int N = 3;

    cout << "\n=== DVYHUNY ===" << endl;
    Dvyhun dvyhuny[N];
    for (int i = 0; i < N; i++) {
        cout << "\nDvyhun #" << (i + 1) << endl;
        dvyhuny[i].vvesty();
    }
    for (int i = 0; i < N; i++) {
        cout << "\nDvyhun #" << (i + 1) << " info:" << endl;
        dvyhuny[i].vyvesty();
    }

    cout << "\n=== AVTOMOBILI ===" << endl;
    Avtomobil avt[N];
    for (int i = 0; i < N; i++) {
        cout << "\nAvtomobil #" << (i + 1) << endl;
        avt[i].vvesty();
    }
    for (int i = 0; i < N; i++) {
        cout << "\nAvtomobil #" << (i + 1) << " info:" << endl;
        avt[i].vyvesty();
    }

    cout << "\n=== VANTAZHIVKY ===" << endl;
    Vantazhivka vant[N];
    for (int i = 0; i < N; i++) {
        cout << "\nVantazhivka #" << (i + 1) << endl;
        vant[i].vvesty();
    }
    for (int i = 0; i < N; i++) {
        cout << "\nVantazhivka #" << (i + 1) << " info:" << endl;
        vant[i].vyvesty();
    }

    return 0;
}

