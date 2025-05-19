#include <iostream>
using namespace std;

void insertSorted(double* &b, int &m, double value) {
    double* newB = new double[m + 1];
    int pos = 0;
    while (pos < m && b[pos] < value) {
        ++pos;
    }
    for (int i = 0; i < pos; ++i) {
        newB[i] = b[i];
    }
    newB[pos] = value;
    for (int i = pos; i < m; ++i) {
        newB[i + 1] = b[i];
    }
    delete[] b;
    b = newB;
    ++m;
}

int main() {
    int n;
    cout << "Vedit k-t elementiv masivy: ";
    cin >> n;

    double* a = new double[n];
    cout << "Vvesty " << n << " diysnuh chisel:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double* b = NULL;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int whole = static_cast<int>(a[i]);
        if (whole % 2 == 0) {
            insertSorted(b, m, a[i]);
        }
    }

    cout << "Elementy z parnoyu chiloyu chastinoyu y poradcy zrostanna:\n";
    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;

    system("pause"); // щоб вікно не закрилось
    return 0;
}
