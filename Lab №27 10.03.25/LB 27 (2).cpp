#include <iostream>
using namespace std;

// Тип функції, яка створює масив b з масиву a
typedef double* (*FilterFunc)(double*, int, int&);

// Функція, яка створює масив b — парні елементи з непарних індексів
double* createFilteredArray(double* a, int n, int& m) {
    m = 0;

    // Підрахунок кількості відповідних елементів
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && static_cast<int>(a[i]) % 2 == 0) {
            m++;
        }
    }

    // Виділення динамічної пам’яті для масиву b
    double* b = new double[m];
    int j = 0;

    // Заповнення b
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && static_cast<int>(a[i]) % 2 == 0) {
            b[j++] = a[i];
        }
    }

    return b;
}

int main() {
    int n;
    cout << "Rozmir masivy a: ";
    cin >> n;

    // Динамічне виділення пам’яті для масиву a
    double* a = new double[n];
    cout << "Elementu masivy a:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Вказівник на функцію
    FilterFunc filter = createFilteredArray;

    int m; // розмір нового масиву
    double* b = filter(a, n, m); // Виклик функції через вказівник

    // Виведення результату
    cout << "\n Masiv b (parni elem. z neparnih indecsiv a): ";
    for (int j = 0; j < m; j++) {
        cout << b[j] << " ";
    }
    cout << endl;

    // Звільнення пам’яті
    delete[] a;
    delete[] b;

    return 0;
}

