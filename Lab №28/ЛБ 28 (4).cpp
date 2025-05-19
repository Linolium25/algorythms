#include <iostream>
#include <cstdlib>   
#include <ctime>     

using namespace std;

// ѕерев≥рка числа: чи маЇ однаков≥ цифри
bool hasSameDigits(int number) {
    int tens = number / 10;
    int units = number % 10;
    return tens == units;
}

int main() {
    int n;

    cout << "Vvedit rozmirnist matrytsi n: ";
    cin >> n;

    // ¬ид≥ленн€ динам≥чноњ пам'€т≥ дл€ матриц≥
    int** A = new int*[n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    srand(time(0));

    // «аповненн€ матриц≥ випадковими двоцифровими числами
    cout << "Matrytsia A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 90 + 10;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // ѕошук суми елемент≥в у тих стовпц€х, €к≥ не м≥ст€ть чисел з однаковими цифрами
    int countValidColumns = 0; // Ћ≥чильник к≥лькост≥ "придатних" стовпц≥в

    for (int j = 0; j < n; ++j) {
        bool hasSame = false;

        // ѕерев≥р€Їмо, чи Ї в стовпц≥ числа з однаковими цифрами
        for (int i = 0; i < n; ++i) {
            if (hasSameDigits(A[i][j])) {
                hasSame = true;
                break;
            }
        }

        // якщо таких чисел немаЇ Ч обчислюЇмо суму
        if (!hasSame) {
            int columnSum = 0;
            for (int i = 0; i < n; ++i) {
                columnSum += A[i][j];
            }
            cout << "Suma elementiv u stovptsi " << j << ": " << columnSum << endl;
            countValidColumns++;
        }
    }

    // якщо не знайдено жодного стовпц€ без чисел з однаковими цифрами Ч пов≥домити користувача
    if (countValidColumns == 0) {
        cout << "Nemaje stovptsiv bez chysel z odnakovymy tsyframy." << endl;
    }

    // «в≥льненн€ вид≥леноњ пам'€т≥
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

