#include <iostream>
#include <string>
using namespace std;


class Dvyhun {
private:
    double potuzhnist;
    string zavodNom;

public:
    // Констр.
    Dvyhun() : potuzhnist(0), zavodNom("0000") {
        cout << "Stvoreno ob'yekt klasu \"Dvyhun\" (za zamovchuvannyam)" << endl;
    }

    // Пар. кон.
    Dvyhun(double p, string z) : potuzhnist(p), zavodNom(z) {
        cout << "Stvoreno ob'yekt klasu \"Dvyhun\" (z parametramy)" << endl;
    }

    // Віртуальний деструктор
    virtual ~Dvyhun() {
        cout << "Znyshcheno ob'yekt klasu \"Dvyhun\"" << endl;
    }

    // Метод введення
    virtual void vvesty() {
        cout << "Vvedit potuzhnist (kVt): ";
        cin >> potuzhnist;
        cin.ignore();

        cout << "Vvedit zavodskyy nomer: ";
        getline(cin, zavodNom);
    }

    // Метод виведення
    virtual void vyvesty() const {
        cout << "Potuzhnist: " << potuzhnist << " kVt" << endl;
        cout << "Zavodskyy nomer: " << zavodNom << endl;
    }
};

// === Похідний клас: "Avtomobil" ===

//   "При визначенні специфікатора доступу при наслідуванні описати в коментарі його дію."
// Наслідування з public означає, що всі public і protected елементи базового класу ("Dvyhun")
// залишаються доступними у похідному класі ("Avtomobil") з такими самими правами доступу.
// Це дозволяє викликати методи типу Dvyhun::vvesty() у класі Avtomobil.

class Avtomobil : public Dvyhun {
private:
    string marka;
    double tsina;

public:
    // Конструктор за замовчуванням
    Avtomobil() : Dvyhun(), marka("N/A"), tsina(0) {
        cout << "Stvoreno ob'yekt klasu \"Avtomobil\" (za zamovchuvannyam)" << endl;
    }

    // Параметризований конструктор
    Avtomobil(string m, double t, double p, string z) : Dvyhun(p, z), marka(m), tsina(t) {
        cout << "Stvoreno ob'yekt klasu \"Avtomobil\" (z parametramy)" << endl;
    }

    // Деструктор
    ~Avtomobil() override {
        cout << "Znyshcheno ob'yekt klasu \"Avtomobil\"" << endl;
    }

    // Метод введення
    void vvesty() override {
        Dvyhun::vvesty();

        cout << "Vvedit marku avtomobilya: ";
        getline(cin, marka);

        cout << "Vvedit tsinu: ";
        cin >> tsina;
        cin.ignore();
    }

    // Метод виведення
    void vyvesty() const override {
        Dvyhun::vyvesty();

        cout << "Marka: " << marka << endl;
        cout << "Tsina: " << tsina << " hrn" << endl;
    }
};

// === Похідний клас: "Vantazhivka" ===

//  "При визначенні специфікатора доступу при наслідуванні описати в коментарі його дію."
// Наслідування з public означає, що клас "Vantazhivka" може напряму використовувати публічні методи класів "Avtomobil" та "Dvyhun".
// Це потрібно для виклику Avtomobil::vvesty() і Dvyhun::vyvesty() без обмежень.

class Vantazhivka : public Avtomobil {
private:
    double vantazhopidyomnist;

public:
    // Конструктор за замовчуванням
    Vantazhivka() : Avtomobil(), vantazhopidyomnist(0) {
        cout << "Stvoreno ob'yekt klasu \"Vantazhivka\" (za zamovchuvannyam)" << endl;
    }

    // Параметризований конструктор
    Vantazhivka(string m, double t, double p, string z, double v)
        : Avtomobil(m, t, p, z), vantazhopidyomnist(v) {
        cout << "Stvoreno ob'yekt klasu \"Vantazhivka\" (z parametramy)" << endl;
    }

    // Деструктор
    ~Vantazhivka() override {
        cout << "Znyshcheno ob'yekt klasu \"Vantazhivka\"" << endl;
    }

    // Метод введення
    void vvesty() override {
        Avtomobil::vvesty();

        cout << "Vvedit vantazhopidyomnist (kg): ";
        cin >> vantazhopidyomnist;
        cin.ignore();
    }

    // Метод виведення
    void vyvesty() const override {
        Avtomobil::vyvesty();

        cout << "Vantazhopidyomnist: " << vantazhopidyomnist << " kg" << endl;
    }
};

// === Головна функція ===
int main() {
    const int N = 3;

    // Масиви об'єктів класу "Dvyhun"
    cout << "\n=== \"DVYHUNY\" ===" << endl;
    Dvyhun dvyhuny[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Dvyhun\" #" << i + 1 << ":" << endl;
        dvyhuny[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Dvyhun\" #" << i + 1 << ":" << endl;
        dvyhuny[i].vyvesty();
    }

    // Масиви об'єктів класу "Avtomobil"
    cout << "\n=== \"AVTOMOBILI\" ===" << endl;
    Avtomobil avt[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Avtomobil\" #" << i + 1 << ":" << endl;
        avt[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Avtomobil\" #" << i + 1 << ":" << endl;
        avt[i].vyvesty();
    }

    // Масиви об'єктів класу "Vantazhivka"
    cout << "\n=== \"VANTAZHIVKY\" ===" << endl;
    Vantazhivka vant[N];
    for (int i = 0; i < N; ++i) {
        cout << "\n\"Vantazhivka\" #" << i + 1 << ":" << endl;
        vant[i].vvesty();
    }

    for (int i = 0; i < N; ++i) {
        cout << "\nInformatsiya pro \"Vantazhivka\" #" << i + 1 << ":" << endl;
        vant[i].vyvesty();
    }

    return 0;
}


