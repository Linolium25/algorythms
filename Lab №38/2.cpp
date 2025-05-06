#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class Vector10 {
    T data[10];

public:
    Vector10() {
        for (int i = 0; i < 10; i++) {
            data[i] = T();
        }
    }

    Vector10(T val) {
        for (int i = 0; i < 10; i++) {
            data[i] = val;
        }
    }

    void vvestyZKlaviatury() {
        for (int i = 0; i < 10; i++) {
            cout << "Vvedy element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void zapovnennyaRand() {
        for (int i = 0; i < 10; i++) {
            data[i] = rand() % 100;
        }
    }

    void vyvesty() {
        for (int i = 0; i < 10; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void parniVNapered() {
        T temp[10];
        int index = 0;

        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) temp[index++] = data[i];
        }
        for (int i = 0; i < 10; i++) {
            if (i % 2 != 0) temp[index++] = data[i];
        }

        for (int i = 0; i < 10; i++) {
            data[i] = temp[i];
        }
    }

    void vydalyZnachenia(T val) {
        T temp[10];
        int index = 0;

        for (int i = 0; i < 10; i++) {
            if (data[i] != val && index < 10) {
                temp[index++] = data[i];
            }
        }

        while (index < 10) {
            temp[index++] = T();
        }

        for (int i = 0; i < 10; i++) {
            data[i] = temp[i];
        }
    }

    Vector10 operator+(const Vector10& other) {
        Vector10 res;
        for (int i = 0; i < 10; i++) {
            res.data[i] = data[i] + other.data[i];
        }
        return res;
    }

    Vector10 operator++(int) {
        Vector10 res = *this;
        for (int i = 0; i < 10; i++) {
            data[i] += 10;
        }
        return res;
    }

    bool operator<(const Vector10& other) const {
        T sum1 = T(), sum2 = T();
        for (int i = 0; i < 10; i++) {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 < sum2;
    }

    bool operator>(const Vector10& other) const {
        T sum1 = T(), sum2 = T();
        for (int i = 0; i < 10; i++) {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 > sum2;
    }

    bool operator==(const Vector10& other) const {
        T sum1 = T(), sum2 = T();
        for (int i = 0; i < 10; i++) {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 == sum2;
    }
};

int main() {
    srand(time(0));

    Vector10<int> v1;
    cout << "Vvedennya z klaviatury v1:\n";
    v1.vvestyZKlaviatury();
    v1.vyvesty();

    Vector10<int> v2;
    v2.zapovnennyaRand();
    cout << "v2 (random): ";
    v2.vyvesty();

    Vector10<int> v3 = v1 + v2;
    cout << "v3 = v1 + v2: ";
    v3.vyvesty();

    v1++;
    cout << "v1 pislya ++: ";
    v1.vyvesty();

    cout << "parni vpered: ";
    v1.parniVNapered();
    v1.vyvesty();

    v1.vydalyZnachenia(10);
    cout << "Pislya vydalennya 10: ";
    v1.vyvesty();

    if (v1 > v2) cout << "v1 > v2\n";
    else if (v1 < v2) cout << "v1 < v2\n";
    else cout << "v1 == v2\n";

    return 0;
}


