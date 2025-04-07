#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100;
    }

    cout << "Pochatcoviy masiv:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int temp[SIZE];
    int* start = temp;
    int* end = temp + SIZE - 1;

    for (int i = 0; i < SIZE; i++) {
        if (*(arr + i) % 2 == 0) {
            *start = *(arr + i);
            start++;
        } else {
            *end = *(arr + i);
            end--;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = *(temp + i);
    }

    cout << "Masiv pisla zminy:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << " ";
    }

    return 0;
}
