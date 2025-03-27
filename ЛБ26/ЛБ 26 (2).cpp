#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << " Vesty k-t ryadkiv: ";
    cin >> rows;
    cout << "Vesty k-t stovpciv: ";
    cin >> cols;
    
    int matrix[rows][cols]; 
    cout << "Elementy matrishi:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Visnovoc:\n";
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
        } else { 
            for (int j = cols - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

