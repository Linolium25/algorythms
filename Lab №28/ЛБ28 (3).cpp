#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funktsiia sortuvannia odnovymirnoho masyvu za spadanniam
void sortDescending(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Vyvid matrytsi
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Vvedit rozmirnist matrici (n): ";
    cin >> n;

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 100 + rand() % 900;
        }
    }

    for (int i = 0; i < n; ++i) {
        sortDescending(matrix[i], n);
    }

    cout << "\nMatrytsia pislia sortuvannia riadkiv za spadanniam:\n";
    printMatrix(matrix, n);

    ofstream fout("matrix_output (завд 3).txt");
    if (fout.is_open()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                fout << matrix[i][j] << "\t";
            }
            fout << endl;
        }
        fout.close();
        cout << "\nMatrytsia zapysana u fail 'matrix_output.txt'\n";
    } else {
        cout << "Pomylka vidkryttia faylu dlia zapysu.\n";
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

