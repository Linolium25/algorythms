#include <iostream>   
#include <cstdlib>   
#include <ctime>     
using namespace std;  

class Matrix {  
private:
    int** data;  // мас. зб.
    int size;    // Розм.

public:
    // Конст. задан.
    Matrix(int n) {
        size = n;
        data = new int*[size];
        for (int i = 0; i < size; ++i)
            data[i] = new int[size];
    }

    
    ~Matrix() {
        for (int i = 0; i < size; ++i)
            delete[] data[i];
        delete[] data;
    }

    //зап. вип.
    void randomFill(int min, int max) {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                data[i][j] = rand() % (max - min + 1) + min;
    }
    
    void print() const {// екр.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }

    
    friend Matrix operator+(const Matrix& a, const Matrix& b);  
    friend Matrix operator-(const Matrix& a, const Matrix& b);  
    friend Matrix operator*(const Matrix& a, const Matrix& b);  
    friend bool operator==(const Matrix& a, const Matrix& b);   
};

// Перев. оп 
Matrix operator+(const Matrix& a, const Matrix& b) {
    Matrix result(a.size);
    for (int i = 0; i < a.size; i++)
        for (int j = 0; j < a.size; j++)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}


Matrix operator-(const Matrix& a, const Matrix& b) {
    Matrix result(a.size);
    for (int i = 0; i < a.size; i++)
        for (int j = 0; j < a.size; j++)
            result.data[i][j] = a.data[i][j] - b.data[i][j];
    return result;
}


Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix result(a.size);
    for (int i = 0; i < a.size; i++)
        for (int j = 0; j < a.size; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.size; k++)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    return result;
}


bool operator==(const Matrix& a, const Matrix& b) {
    for (int i = 0; i < a.size; i++)
        for (int j = 0; j < a.size; j++)
            if (a.data[i][j] != b.data[i][j])
                return false;
    return true;
}

int main() {
    srand(time(0)); 

    int n;  
    int minVal = -10, maxVal = 10;  // Меж. в.ч

   
    cout << "Vvedit rozmir kvadratnoyi matritsi: ";
    cin >> n;

    Matrix A(n), B(n);  

   
    cout << "\nMatritsya A (vypadkova):\n";
    A.randomFill(minVal, maxVal);
    A.print();

 
    cout << "\nMatritsya B (vypadkova):\n";
    B.randomFill(minVal, maxVal);
    B.print();

  
    cout << "\nA + B:\n";
    Matrix C = A + B;
    C.print();

 
    cout << "\nA - B:\n";
    Matrix D = A - B;
    D.print();


    cout << "\nA * B:\n";
    Matrix E = A * B;
    E.print();

 
    cout << "\nA == B: ";
    if (A == B)
        cout << "Tak\n";
    else
        cout << "Ni\n";

    return 0; 
}

