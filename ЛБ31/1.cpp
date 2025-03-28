#include <iostream>
using namespace std;

class Flat {
public:
    string address;
    int floor;
    int rooms;
    double area;

    Flat() {
        address = "Unknown";
        floor = 1;
        rooms = 2;
        area = 55.0;
        cout << "Default constructor called\n";
    }

    Flat(string a, int f) {
        address = a;
        floor = f;
        rooms = 2;
        area = 55.0;
        cout << "Parameterized constructor called for " << address << "\n";
    }

    ~Flat() {
        cout << "Destructor called for " << address << "\n";
    }

    void show() {
        cout << "Address: " << address << ", Floor: " << floor 
             << ", Rooms: " << rooms << ", Area: " << area << " m?\n";
    }
};

int main() {
    Flat flats[3] = {
        Flat("Shevchenka St, 10", 3),
        Flat("Peace Avenue, 25", 7),
        Flat("Lesia Ukrainka Blvd, 15", 2)
    };

    Flat customFlat("Franka St, 8", 5);
    customFlat.rooms = 1;
    customFlat.area = 35.5;

    cout << "\n=== All apartments ===\n";
    for (int i = 0; i < 3; i++) flats[i].show();
    customFlat.show();

    cout << "\n=== Apartments with 2 rooms ===\n";
    for (int i = 0; i < 3; i++)
        if (flats[i].rooms == 2) flats[i].show();

    cout << "\n=== Apartments up to 40 m? on floors 1-5 ===\n";
    if (customFlat.area < 40 && customFlat.floor >= 1 && customFlat.floor <= 5)
        customFlat.show();

    return 0;
}

