#include <iostream>
using namespace std;

class Flat { 
public:
    string address; 
    int floor;      
    int rooms;      
    double area;    

    Flat() { // Конструктор  (2 кімнати, 55 м?)
        address = "Unknown";
        floor = 1;
        rooms = 2;
        area = 55.0;
        cout << "Default constructor called\n";
    }

    Flat(string a, int f) { // Пар. конструктор (адреса і поверх)
        address = a;
        floor = f;
        rooms = 2;
        area = 55.0;
        cout << "Parameterized constructor called for " << address << "\n";
    }

    ~Flat() { 
        cout << "Destructor called for " << address << "\n";
    }

    void input() {
        cout << "Enter address: ";
        cin.ignore(); // очистити  cin
        getline(cin, address);// зчит/p
        cout << "Enter floor: ";
        cin >> floor;
        cout << "Enter number of rooms: ";
        cin >> rooms;
        cout << "Enter area: ";
        cin >> area;
    }

    void show() { 
        cout << "Address: " << address << ", Floor: " << floor
             << ", Rooms: " << rooms << ", Area: " << area << " m\n";
    }
};

int main() {
    const int SIZE = 4;
    Flat flats[SIZE];

    cout << "=== Enter data for 3 apartments ===\n";
    // Введ. даних для 3 квартир
    for (int i = 0; i < SIZE - 1; i++) {
        flats[i].input();
    }

    //  4 квартира через параметризований конструктор
    Flat customFlat("Franka St, 8", 5);
    customFlat.rooms = 1;
    customFlat.area = 35.5;
    flats[SIZE - 1] = customFlat; //в масив

    cout << "\n=== All apartments ===\n";
    for (int i = 0; i < SIZE; i++) {
        flats[i].show();
    }

    cout << "\n=== Apartments with 2 rooms ===\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].rooms == 2)
            flats[i].show();
    }

    cout << "\n=== Apartments up to 40 m on floors 1-5 ===\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].area < 40 && flats[i].floor >= 1 && flats[i].floor <= 5)
            flats[i].show();
    }

    return 0;
}


