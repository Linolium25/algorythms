#include <iostream>
using namespace std;

class Flat {
public:
    string address;
    int floor;
    int rooms;
    double area;

    Flat() {
        address = "Невідомо";
        floor = 1;
        rooms = 2;
        area = 55;
    }

    Flat(string addr, int fl) {
        address = addr;
        floor = fl;
        rooms = 2;  
        area = 55; 
    }

    void input() {
        cout << "Введіть адресу: ";
        cin.ignore();
        getline(cin, address);
        cout << "Введіть поверх: ";
        cin >> floor;
        cout << "Введіть кількість кімнат: ";
        cin >> rooms;
        cout << "Введіть площу (м?): ";
        cin >> area;
    }

    void display() {
        cout << "Адреса: " << address << ", Поверх: " << floor 
             << ", Кімнат: " << rooms << ", Площа: " << area << " м?" << endl;
    }
};

int main() {
    const int SIZE = 3;
    Flat flats[SIZE] = {
        Flat("вул. Шевченка, 10", 3),
        Flat("пр. Перемоги, 25", 5),
        Flat()  
    };

    cout << "\nВведіть дані для третьої квартири:\n";
    flats[2].input();

    cout << "\nСписок усіх квартир:\n";
    for (int i = 0; i < SIZE; i++) {
        flats[i].display();
    }

    int searchRooms;
    cout << "\nВведіть кількість кімнат для пошуку: ";
    cin >> searchRooms;
    cout << "Квартири з " << searchRooms << " кімнатами:\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].rooms == searchRooms) {
            flats[i].display();
        }
    }

    double maxArea = 40;
    int minFloor, maxFloor;
    cout << "\nВведіть мінімальний поверх: ";
    cin >> minFloor;
    cout << "Введіть максимальний поверх: ";
    cin >> maxFloor;

    cout << "\nКвартири з площею < 40 м? та між " << minFloor << " і " << maxFloor << " поверхами:\n";
    for (int i = 0; i < SIZE; i++) {
        if (flats[i].area < maxArea && flats[i].floor >= minFloor && flats[i].floor <= maxFloor) {
            flats[i].display();
        }
    }

    return 0;
}

