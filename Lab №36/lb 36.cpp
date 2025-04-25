#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Pracivnyk {
protected:
    int vik;
    int stazh;

private:
    string prizvyshche;

public:
    Pracivnyk(string p, int v, int s) {
        prizvyshche = p;
        vik = v;
        stazh = s;
    }

    void zminytyDani(string p, int v, int s) {
        prizvyshche = p;
        vik = v;
        stazh = s;
    }

    void pokazatyInfo() {
        cout << "Prizvyshche: " << prizvyshche << endl;
        cout << "Vik: " << vik << endl;
        cout << "Stazh vodinnya: " << stazh << " rokiv" << endl;
    }

    int rikZPochatkuVodinnya() {
        return 2025 - stazh;
    }

    int getStazh() {
        return stazh;
    }
};

class Avtomobil {
protected:
    int rikVypusku;

private:
    string nomer;
    string marka;
    int probih;

public:
    Avtomobil() {
        nomer = "Nevydomo";
        marka = "Nevydomo";
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

    void pokazatyInfo() {
        cout << "Reyestraciynyi nomer: " << nomer << endl;
        cout << "Marka: " << marka << endl;
        cout << "Rik vypusku: " << rikVypusku << endl;
        cout << "Probih: " << probih << " km" << endl;
    }

    double seredniyProbih() {
        int vik = 2025 - rikVypusku;
        return (vik > 0) ? (double)probih / vik : probih;
    }

    int getRikVypusku() {
        return rikVypusku;
    }

    int getProbih() {
        return probih;
    }
};

class Vodiy : public Pracivnyk, public Avtomobil {
private:
    int rikPochatku;
    bool shtrafy;

public:
    Vodiy(string p, int v, int s, string n, string m, int r, int pbg, int rpv, bool sh)
        : Pracivnyk(p, v, s), Avtomobil(n, m, r, pbg) {
        rikPochatku = rpv;
        shtrafy = sh;
    }

    void zminytyDani() {
        try {
            string p;
            int v, s;

            cout << "Vvedit prizvyshche: ";
            cin >> p;

            cout << "Vvedit vik: ";
            cin >> v;
            if (v < 0) throw invalid_argument("Vik ne mozhe buty vid'yemnym");

            cout << "Vvedit stazh: ";
            cin >> s;
            if (s < 0) throw invalid_argument("Stazh ne mozhe buty vid'yemnym");

            Pracivnyk::zminytyDani(p, v, s);

            string n, m;
            int r, pr;

            cout << "Vvedit nomer avtivky: ";
            cin >> n;
            cout << "Vvedit marku: ";
            cin >> m;
            cout << "Vvedit rik vypusku: ";
            cin >> r;
            if (r < 0) throw invalid_argument("Rik vypusku ne mozhe buty vid'yemnym");

            cout << "Vvedit probih: ";
            cin >> pr;
            if (pr < 0) throw invalid_argument("Probih ne mozhe buty vid'yemnym");

            Avtomobil::zminytyDani(n, m, r, pr);

            cout << "Vvedit rik pochatku vykorystannya: ";
            cin >> rikPochatku;
            if (rikPochatku < 0) throw invalid_argument("Rik pochatku ne mozhe buty vid'yemnym");

            cout << "Chy ye shtrafy? (1 - tak, 0 - ni): ";
            cin >> shtrafy;

        } catch (const exception& e) {
            cerr << "Pomylka: " << e.what() << endl;
        }
    }

    void pokazatyInfo() {
        cout << "\n* INFORMACIYa PRO VODIYa *" << endl;
        Pracivnyk::pokazatyInfo();
        Avtomobil::pokazatyInfo();
        cout << "Rik pochatku vykorystannya: " << rikPochatku << endl;
        cout << "Shtrafy: " << (shtrafy ? "Tak" : "Ni") << endl;
    }
    
    void porivnyatyVikTaStazh() {
        int vikAuto = 2025 - getRikVypusku();
        int st = getStazh();
        cout << "Vik avtivky: " << vikAuto << endl;
        cout << "Stazh vodinnya: " << st << endl;

        if (vikAuto > st)
            cout << "Avto starshe za stazh." << endl;
        else if (vikAuto < st)
            cout << "Stazh bilshyi za vik avtivky." << endl;
        else
            cout << "Stazh i vik avtivky odnakovi." << endl;
    }
};

int main() {
    Vodiy v("Ivanenko", 40, 15, "AB1234CD", "Ford", 2012, 180000, 2013, true);

    cout << "--- POChATKOVA INFORMACIYa ---" << endl;
    v.pokazatyInfo();

    cout << "\n--- ONOVLENNYa DANIH ---" << endl;
    v.zminytyDani();

    cout << "\n--- ONOVLENA INFORMACIYa ---" << endl;
    v.pokazatyInfo();

    cout << "\n--- PORIVNANNYa VIKU AVTO I STAZhU ---" << endl;
    v.porivnyatyVikTaStazh();

    return 0;
}
