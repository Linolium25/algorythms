#include <iostream>
#include <string>
#include <stdexcept> // vucl.sit.

using namespace std;

class Pracivnyk {
protected:
    int vik;
    int stazh;

private:
    string prizvysche;

public:
    Pracivnyk(string p, int v, int s) {
        prizvysche = p;
        vik = v;
        stazh = s;
    }

    void zminytyDani(string p, int v, int s) {
        prizvysche = p;
        vik = v;
        stazh = s;
    }

    void pokazatyInfo() const {
        cout << "Pryzvysche: " << prizvysche << endl;
        cout << "Vik: " << vik << " rokiv" << endl;
        cout << "Stazh vodinnya: " << stazh << " rokiv" << endl;
    }

    int rikZPochatkuVodinnya() const {
        return 2025 - stazh;
    }

    int getStazh() const {
        return stazh;//get
    }
};

class Avtomobil {
protected:
    int rikVypusku;

private:
    string nomer;
    string marka;
    int probih;

public://bezparam
    Avtomobil() {
        nomer = "Nevidomo";
        marka = "Nevidomo";
        rikVypusku = 0;
        probih = 0;
    }

    Avtomobil(string n, string m, int r, int p) {
        nomer = n;
        marka = m;
        rikVypusku = r;
        probih = p;
    }

    void zminytyDani(string n, string m, int r, int p) {
        nomer = n;
        marka = m;
        rikVypusku = r;
        probih = p;
    }

    void pokazatyInfo() const {
        cout << "Nomer avto: " << nomer << endl;
        cout << "Marka: " << marka << endl;
        cout << "Rik vypusku: " << rikVypusku << endl;
        cout << "Probih: " << probih << " km" << endl;
        cout << "Seredniy richniy probih: " << seredniyProbih() << " km/rik" << endl;
    }

    double seredniyProbih() const {
        int vik = 2025 - rikVypusku;
        // Перевірка(cl.pomiloc)
        return (vik > 0) ? static_cast<double>(probih) / vik : probih;
    }

    int getRikVypusku() const {
        return rikVypusku;
    }

    int getProbih() const {
        return probih;
    }
};

// Мн.nasl
class Vodiy : public Pracivnyk, public Avtomobil {
private:
    int rikPochatku;
    bool shtrafy;

public: //yspad
    Vodiy(string p, int v, int s, string n, string m, int r, int pbg, int rpv, bool sh)
        : Pracivnyk(p, v, s), Avtomobil(n, m, r, pbg) {
        rikPochatku = rpv;
        shtrafy = sh;
    }

    void zminytyDani() {
        try {
            string p, n, m;
            int v, s, r, pr, rpv;
            bool sh;

            cout << "\n--- Vvedennya novykh danykh ---" << endl;

            cout << "Pryzvysche: ";
            cin >> p;

            cout << "Vik: ";
            cin >> v;
            if (v < 0) throw invalid_argument("Vik ne mozhe buty vid'yemnym."); //Обробка помилки

            cout << "Stazh: ";
            cin >> s;
            if (s < 0) throw invalid_argument("Stazh ne mozhe buty vid'yemnym."); 

            Pracivnyk::zminytyDani(p, v, s);

            cout << "Nomer avto: ";
            cin >> n;

            cout << "Marka avto: ";
            cin >> m;

            cout << "Rik vypusku: ";
            cin >> r;
            if (r < 0) throw invalid_argument("Rik vypusku ne mozhe buty vid'yemnym."); 

            cout << "Probih: ";
            cin >> pr;
            if (pr < 0) throw invalid_argument("Probih ne mozhe buty vid'yemnym."); 

            Avtomobil::zminytyDani(n, m, r, pr);

            cout << "Rik pochatku vykorystannya avto: ";
            cin >> rpv;
            if (rpv < 0) throw invalid_argument("Rik pochatku ne mozhe buty vid'yemnym."); 

            cout << "Bylu shtrafy (1 - tak, 0 - ni): ";
            cin >> sh;

            rikPochatku = rpv;
            shtrafy = sh;

        } catch (const exception& e) {
            cerr << "Pomylka: " << e.what() << endl;
        }
    }

    void pokazatyInfo() const {
        cout << "\n=== INFORMACIYA PRO VODIYA ===" << endl;
        Pracivnyk::pokazatyInfo();
        Avtomobil::pokazatyInfo();
        cout << "Rik pochatku vykorystannya avto: " << rikPochatku << endl;
        cout << "Nayavnist shtrafiv: " << (shtrafy ? "Yas" : "No") << endl;
    }

    void porivnyatyVikTaStazh() const {
        int vikAuto = 2025 - getRikVypusku();
        int st = getStazh();

        cout << "\n=== PORIVNYANNYA VIKU AVTO I STAZHU ===" << endl;
        cout << "Vik avto: " << vikAuto << " rokiv" << endl;
        cout << "Stazh vodinnya: " << st << " rokiv" << endl;

        if (vikAuto > st)
            cout << "Avtomobil starishyy za stazh." << endl;
        else if (vikAuto < st)
            cout << "Stazh bilshyy za vik avto." << endl;
        else
            cout << "Stazh i vik avto odnakovi." << endl;
    }
};

int main() {
    Vodiy v("Babenco", 40, 15, "AB1234CD", "Ford", 2012, 180000, 2013, true);

    cout << "\n--- Pochatkova informaciya ---" << endl;
    v.pokazatyInfo();

    v.zminytyDani(); // Введення нових даних з перевірками

    cout << "\n--- Onovlena informaciya ---" << endl;
    v.pokazatyInfo();

    v.porivnyatyVikTaStazh(); 

    return 0;
}

