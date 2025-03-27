#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n; 
    cout << "Rozmir masivy: ";
    cin >> n;

    int* arr = new int[n];

    cout << "zapovnenuy masiv: ";
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % 100;  
        cout << *(arr + i) << " ";  
    }
    cout << endl;

    delete[] arr;

    return 0;
}

