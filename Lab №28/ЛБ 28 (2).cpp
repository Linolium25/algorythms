#include <iostream>
#include <cstdlib> 
#include <ctime>    

using namespace std;

// Функція для перевірки, чи стовпець впорядкований за спаданням
bool isDescending(int** A, int n, int col) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i][col] < A[i + 1][col]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Vvedit rozmir n: ";
    cin >> n;

    // Виділення пам’яті
    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }

    // Заповнення випадковими числами
    srand(time(0));
    cout << "Matrusha:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 21 - 10;  // від -10 до 10
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    // Підрахунок впорядкованих за спаданням стовпців
    int countDescending = 0;
    for (int j = 0; j < n; j++) {
        if (isDescending(A, n, j)) {
            countDescending++;
        }
    }

    cout << "Kilkist stovptsiv, uporyadkovanykh za spadannyam: " << countDescending << endl;

    // Звільнення пам’яті
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

