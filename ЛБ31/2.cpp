#include <iostream>
using namespace std;

class People {
public:
    string prizvyshche;
    string stat;
    string osvita;
    int rikNarodzhennya;
    int vik;

    People() {
        prizvyshche = "Nevdomyy";
        stat = "Nevdomo";
        osvita = "Nemae";
        rikNarodzhennya = 2006;
        vik = 2024 - rikNarodzhennya;
    }

    People(string p, string s, string o, int rn) {
        prizvyshche = p;
        stat = s;
        osvita = o;
        rikNarodzhennya = rn;
        vik = 2024 - rikNarodzhennya;
    }

    People(const People& p) {
        prizvyshche = p.prizvyshche;
        stat = p.stat;
        osvita = p.osvita;
        rikNarodzhennya = p.rikNarodzhennya;
        vik = p.vik;
    }

    void pokazaty() {
        cout << prizvyshche << " (" << stat << "), " << osvita 
             << ", Vik: " << vik << "\n";
    }
};

void vydalytyZaStatyu(People lyudy[], int& kilkist, string statDlyaVydalennya) {
    for (int i = 0; i < kilkist; i++) {
        if (lyudy[i].stat == statDlyaVydalennya) {
            for (int j = i; j < kilkist - 1; j++) {
                lyudy[j] = lyudy[j + 1];
            }
            kilkist--; 
            i--;    
        }
    }
}

int main() {
    const int MAX_LYUDY = 5;
    int kilkist = 3;
    
    People lyudy[MAX_LYUDY] = {
        People("Shevchenko", "Cholovik", "Vyshcha", 1990),
        People("Kovalenko", "Zhinka", "Vyshcha", 1985),
        People("Petrenko", "Cholovik", "Serednya", 2001)
    };

    cout << "\n=== Vsi hromadyany ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    cout << "\n=== Vyshcha osvita & vik > 30 ===\n";
    for (int i = 0; i < kilkist; i++)
        if (lyudy[i].osvita == "Vyshcha" && lyudy[i].vik > 30)
            lyudy[i].pokazaty();

    vydalytyZaStatyu(lyudy, kilkist, "Cholovik");

    cout << "\n=== Onovlenyy spysok hromadyan ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    if (kilkist < MAX_LYUDY) {
        for (int i = kilkist; i > 0; i--) {
            lyudy[i] = lyudy[i - 1];
        }
        lyudy[0] = People(lyudy[1]); 
        kilkist++;
    }

     cout << "\n=== Kopiyovanyy pershyy hromadyanyn ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    return 0;
}


