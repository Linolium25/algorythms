#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Vvedit kilkist chisel: ";
    cin >> n;

    int nums[100]; 

    for (int i = 0; i < n; i++) {
        cout << "Chislo " << (i + 1) << ": ";
        cin >> nums[i];
    }

    int maxValue = findMax(nums, n);
    cout << "Max znachenna: " << maxValue << endl;

    return 0;
}


