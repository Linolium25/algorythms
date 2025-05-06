#include <iostream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

int countNotDivisibleByThree(double* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (static_cast<int>(arr[i]) % 3 != 0) {
            count++;
        }
    }
    return count;
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); 

    int n, m;
    cout << "rozmir masivy n: ";
    cin >> n;
    cout << "rozmirmasivy m: ";
    cin >> m;

    
    double* a = new double[n];
    double* M = new double[m];

    
    for (int i = 0; i < n; i++) {
        a[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < m; i++) {
        M[i] = 1 + rand() % 100;
    }

    
    cout << "\nMasiv a: ";
    printArray(a, n);
    cout << "Masiv M: ";
    printArray(M, m);

    int countA = countNotDivisibleByThree(a, n);
    int countM = countNotDivisibleByThree(M, m);

    cout << "\n K-t elementiv y masuvi a,ne cratni 3 : " << countA << endl;
    cout << "K-t elementiv y masuvi M,ne cratni 3: " << countM << endl;

    if (countA > countM) {
        cout << "\nMasiv a maye bilshe elementiv, ne cratni 3:" << endl;
        printArray(a, n);
    } else if (countM > countA) {
        cout << "\nMasiv M maye bilshe elementiv, ne cratni 3:" << endl;
        printArray(M, m);
    } else {
        cout << "\n Dva masivu mayut odnacovy kilkist elementiv." << endl;
    }

    delete[] a;
    delete[] M;

    return 0;
}

