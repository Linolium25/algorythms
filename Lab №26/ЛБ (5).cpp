#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Kilkist radkiv: ";
    cin >> rows;
    cout << "Kilkist stovp.: ";
    cin >> cols;
    
    int matrix[rows][cols];
    cout << "Elementy matrishi:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int diag_size = min(rows, cols);
    int *diag_elements = new int[diag_size];
    for (int i = 0; i < diag_size; i++) {
        diag_elements[i] = matrix[i][i];
    }
    
    for (int i = 1; i < diag_size; i++) {
        int key = diag_elements[i];
        int j = i - 1;
        while (j >= 0 && diag_elements[j] > key) {
            diag_elements[j + 1] = diag_elements[j];
            j--;
        }
        diag_elements[j + 1] = key;
    }
    
    for (int i = 0; i < diag_size; i++) {
        matrix[i][i] = diag_elements[i];
    }
    delete[] diag_elements;
    
    cout << ": Elementy golovhoi diagonali\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

