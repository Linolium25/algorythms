#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Знаходження мінімального значення в масиві
int findMin(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// Знаходження максимального значення в масиві
int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int n;
    cout << "Vvedit kilkist elementiv: ";
    cin >> n;

    // Виділення динамічної пам’яті для масиву a
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 6 - 2;  // Заповнення масиву числами від -2 до 3
    }

    // Створення нового масиву для результату
    int* b = new int[n * 2]; // Максимально можлива кількість елементів
    int m = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            if (m > 0) {
                int minVal = findMin(b, m);
                int maxVal = findMax(b, m);
                b[m++] = minVal + maxVal;
            } else {
                b[m++] = 0; // Якщо елемент перший і від’ємний — вставляємо 0
            }
        }
        b[m++] = a[i];
    }

    // Виведення початкового масиву
    cout << "\nOryginal'nyy masyv:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    // Виведення оновленого масиву
    cout << "\n\nOnovlenyy masyv:\n";
    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    // Звільнення пам’яті
    delete[] a;
    delete[] b;

    system("pause"); // Щоб вікно не закрилось одразу
    return 0;
}
