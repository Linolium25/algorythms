#include <iostream>
#include <fstream>  
#include <cstdlib>  
#include <ctime>   

using namespace std;

int main() {
    int n;
    cout << "(n)Rozmir matrushi: ";
    cin >> n;

    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }

    srand(time(0)); 

    int sum = 0;
    cout << "Matricha:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 21 - 10; 
            cout << A[i][j] << "\t";
            sum += A[i][j];
        }
        cout << endl;
    }

    double average = sum / double(n * n);
    cout << "Seredne: " << average << endl;

    int* countArray = new int[n];

    for (int i = 0; i < n; i++) {
        countArray[i] = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] < average) {
                countArray[i]++;
            }
        }
    }

    cout << "Kilkist chysel menshykh za serednye u kozhnomu ryadku:\n";
    for (int i = 0; i < n; i++) {
        cout << "Radoc " << i + 1 << ": " << countArray[i] << endl;
    }

    ofstream file("result.txt");

    // Додаємо матрицю до файлу
    file << "Matrusha:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file << A[i][j] << "\t";
        }
        file << endl;
    }

    file << "Serednje arifmetychne: " << average << endl;

    for (int i = 0; i < n; i++) {
        file << "Ryadok " << i + 1 << ": " << countArray[i] << endl;
    }
    file.close();
    cout << "Zapisane y file result.txt\n";

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;
    delete[] countArray;

    return 0;
}

