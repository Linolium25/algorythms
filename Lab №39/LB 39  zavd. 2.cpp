#include <iostream>
#include <string>
using namespace std;

class Pratsivnyk {
protected:
    int id;
    string prizvyshche;
public:
    Pratsivnyk(int id_, string prizv_) {
        id = id_;
        prizvyshche = prizv_;
    }

    int getId() const { return id; }
    string getPrizvyshche() const { return prizvyshche; }

    virtual double rozrakhZarplaty() = 0;

    bool operator==(const Pratsivnyk& other) const {
        return this->id == other.id;
    }

    virtual void pokazInfo() {
        cout << "ID: " << id << ", Prizvyshche: " << prizvyshche << endl;
    }

    virtual ~Pratsivnyk() {}
};

class Menedzher : public Pratsivnyk {
private:
    int pidlegli;
    const double stavka = 10000;
public:
    Menedzher(int id_, string prizv_, int pidlegli_) :
        Pratsivnyk(id_, prizv_), pidlegli(pidlegli_) {}

    double rozrakhZarplaty() override {
        double bonus = (pidlegli > 5) ? stavka * 0.1 : 0;
        return stavka + bonus;
    }

    void pokazInfo() override {
        Pratsivnyk::pokazInfo();
        cout << "Posada: Menedzher, Pidleglykh: " << pidlegli << endl;
        cout << "Zarplata: " << rozrakhZarplaty() << " hrn" << endl;
    }
};

class Rozrobnyk : public Pratsivnyk {
private:
    int hodyny;
    const double stavka = 100;
public:
    Rozrobnyk(int id_, string prizv_, int hodyny_) :
        Pratsivnyk(id_, prizv_), hodyny(hodyny_) {}

    double rozrakhZarplaty() override {
        return hodyny * stavka;
    }

    void pokazInfo() override {
        Pratsivnyk::pokazInfo();
        cout << "Posada: Rozrobnyk, Hodyn: " << hodyny << endl;
        cout << "Zarplata: " << rozrakhZarplaty() << " hrn" << endl;
    }
};

int main() {
    const int ROZMIIR = 2;
    Pratsivnyk* pracivnyky[ROZMIIR];

    int id1, pidlegli;
    string prizv1;
    cout << "Vvedit' dani dlya Menedzhera:\n";
    cout << "ID: ";
    cin >> id1;
    cout << "Prizvyshche: ";
    cin >> prizv1;
    cout << "Kilkist' pidleglykh: ";
    cin >> pidlegli;
    pracivnyky[0] = new Menedzher(id1, prizv1, pidlegli);

    int id2, hodyny;
    string prizv2;
    cout << "\nVvedit' dani dlya Rozrobnyka:\n";
    cout << "ID: ";
    cin >> id2;
    cout << "Prizvyshche: ";
    cin >> prizv2;
    cout << "Kilkist' vidpratsovanykh hodyn: ";
    cin >> hodyny;
    pracivnyky[1] = new Rozrobnyk(id2, prizv2, hodyny);

    cout << "\n--- Info pro pratsivnykiv ---\n";
    for (int i = 0; i < ROZMIIR; i++) {
        pracivnyky[i]->pokazInfo();
        cout << "---------------------------\n";
    }

    cout << "\n--- Poryvnyannya ---\n";
    if (*pracivnyky[0] == *pracivnyky[1]) {
        cout << "Pratsivnyky odnakovi za ID\n";
    } else {
        cout << "Pratsivnyky MAIUT' rizni ID\n";
    }

    for (int i = 0; i < ROZMIIR; i++) {
        delete pracivnyky[i];
    }

    return 0;
}

