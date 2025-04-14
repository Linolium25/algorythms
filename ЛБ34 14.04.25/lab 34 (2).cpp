#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int size;

public:
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

    void input() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> data[i][j];
    }

    void print() const {
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
     int n;
     cout<< "Vvedit rozmir kvadratnoyi matrici: ";
    cin >> n;

    Matrix A(n), B(n);

        cout << "\nVvedit matricyu A:\n";
          A.input();

                cout << "\nVvedit matricyu B:\n";
                     B.input();

                    cout << "\nMatrix A:\n";
                        A.print();

                            cout << "\nMatrix B:\n";
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
                                                                cout << "Yes\n";
                                                                   else
                                                                     cout << "No\n";
    return 0;
}

