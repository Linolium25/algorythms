#include <iostream>
#include <limits> 
using namespace std;

int main() {
    int size;
    cout << "Rozmir matrisi: ";
    cin >> size;
    
    int matrix[size][size];
    cout << "matrix elements:\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cin >> matrix[row][col]; 
        }
    }
    
    int max_main = numeric_limits<int>::min(); 
    int min_side = numeric_limits<int>::max(); 
    
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] > max_main) {
            max_main = matrix[i][i];
        }
        if (matrix[i][size - i - 1] < min_side) {
            min_side = matrix[i][size - i - 1];
        }
    }
    
    cout << "Difference,Riznusa: " << (max_main - min_side) << endl;
    return 0;
}

