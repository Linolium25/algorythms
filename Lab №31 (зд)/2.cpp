#include <iostream>
using namespace std;

class People {
public:
    string prizvyshche;  
    string krayina;      
    string stat;        
    string osvita;       
    int rikNarodzhennya; 
    int vik;            

   
    People() {
        prizvyshche = "Nevdomyy";
        krayina = "Ukraina"; 
        stat = "Nevdomo";
        osvita = "Nemae";
        rikNarodzhennya = 2006; 
        vik = 2024 - rikNarodzhennya;
        cout << "Default constructor called\n";
    }

    // Пар. конст. з 5
    People(string p, string k, string s, string o, int rn) {
        prizvyshche = p;
        krayina = k;
        stat = s;
        osvita = o;
        rikNarodzhennya = rn;
        vik = 2024 - rikNarodzhennya;
        cout << "Parameterized constructor called for " << prizvyshche << "\n";
    }

    // Конст.коп.
    People(const People& p) {
        prizvyshche = p.prizvyshche;
        krayina = p.krayina;
        stat = p.stat;
        osvita = p.osvita;
        rikNarodzhennya = p.rikNarodzhennya;
        vik = p.vik;
        cout << "Copy constructor called for " << prizvyshche << "\n";
    }

    //  введ. даних
    void vvesty() {
        cout << "Vvedit prizvyshche: ";
        cin >> prizvyshche;
        cout << "Vvedit krainu: ";
        cin >> krayina;
        cout << "Vvedit stat (Cholovik/Zhinka): ";
        cin >> stat;
        cout << "Vvedit osvitu (Vyshcha/Serednya): ";
        cin >> osvita;
        cout << "Vvedit rik narodzhennya: ";
        cin >> rikNarodzhennya;
        vik = 2024 - rikNarodzhennya;
    }

    // вивед. даних
    void pokazaty() const {
        cout << prizvyshche << " (" << stat << "), Krayina: " << krayina
             << ", Osvita: " << osvita << ", Vik: " << vik << " rokiv\n";
    }

    // Дест.
    ~People() {
        cout << "Destructor called for " << prizvyshche << "\n";
    }
};

// Зовнішня функція для видалення осіб певної статі
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

    // мас. People
    People lyudy[MAX_LYUDY] = {
        People("Shevchenko", "Ukraina", "Cholovik", "Vyshcha", 1990),
        People("Kovalenko", "Ukraina", "Zhinka", "Vyshcha", 1985),
        People("Petrenko", "Ukraina", "Cholovik", "Serednya", 2001)
    };

    cout << "\n=== Vsi hromadyany ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    cout << "\n=== Gromadyany z vyshchoyu osvitoyu ta vikom > 30 ===\n";
    for (int i = 0; i < kilkist; i++)
        if (lyudy[i].osvita == "Vyshcha" && lyudy[i].vik > 30)
            lyudy[i].pokazaty();

    // Видалення чоловіків
    vydalytyZaStatyu(lyudy, kilkist, "Cholovik");

    cout << "\n=== Spysok pislya vydalennya cholovikiv ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    //  копіювання і вставка на початок
    if (kilkist < MAX_LYUDY) {
        for (int i = kilkist; i > 0; i--) {
            lyudy[i] = lyudy[i - 1];
        }
        lyudy[0] = People(lyudy[1]); // Виклик конст. копіювання
        kilkist++;
    }

    cout << "\n=== Spysok pislya kopiyuvannya pershogo hromadyanyna ===\n";
    for (int i = 0; i < kilkist; i++) lyudy[i].pokazaty();

    return 0;
}


