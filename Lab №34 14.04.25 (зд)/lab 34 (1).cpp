#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
   
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }


  ~Time() {
      
    }

    //вед.
    void input() {
        cout << "Vvedit godunu, xvulunu, sekundy: ";
        cin >> hours >> minutes >> seconds;
    }

    // вив.
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }

    // Перев.о.+
    Time operator+(const Time& t) const {
        Time result; 
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes + result.seconds / 60;
        result.seconds %= 60;
        result.hours = hours + t.hours + result.minutes / 60;
        result.minutes %= 60;
        result.hours %= 24; 
        return result;
    }

   
    Time operator-(const Time& t) const {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = abs(total1 - total2); // -

        Time result;
        result.hours = diff / 3600;
        result.minutes = (diff % 3600) / 60;
        result.seconds = diff % 60;
        return result;
    }

    
    bool operator>(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) > (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }

    bool operator<(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) < (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }

    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }
};


int main() {
    Time t1, t2;

    cout << "Vvedennya pershogo chasu\n";
    t1.input();

    cout << "Vvedennya drugoho chasu\n";
    t2.input();

    cout << "\nPershuy chas: ";
    t1.display();
    cout << "Druguy chas: ";
    t2.display();

    Time sum = t1 + t2;
    Time diff = t1 - t2;

    cout << "\nSuma: ";
    sum.display();

    cout << "Riznucya: ";
    diff.display();

    if (t1 > t2)
        cout << "\nPershuy chas bilshuy za druguy.\n";
    else if (t1 < t2)
        cout << "\nDruguy chas bilshuy za pershuy.\n";
    else
        cout << "\nChasy odnakovi.\n";

    return 0;
}

