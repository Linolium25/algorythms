#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void generateRandomArray(vector<int>& arr, int size) {
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 100);
    }
}

int countEqualFirst(const vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == arr[0]) {
            count++;
        }
    }
    return count;
}

void swapElements(vector<int>& arr, int idx1, int idx2) {
    if (idx1 >= 0 && idx2 >= 0 && idx1 < arr.size() && idx2 < arr.size()) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
}

void insertElement(vector<int>& arr, int element, int position) {
    if (position >= 0 && position <= arr.size()) {
        arr.insert(arr.begin() + position, element);
    }
}

int longestIdenticalSection(const vector<int>& arr) {
    int maxLength = 1;
    int currentLength = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    return maxLength;
}

void sortBetweenMinMax(vector<int>& arr) {
    if (arr.empty()) return;

    int minIdx = 0, maxIdx = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }

    if (minIdx > maxIdx) {
        swap(minIdx, maxIdx);
    }

    vector<int> subArray(arr.begin() + minIdx + 1, arr.begin() + maxIdx);
    sort(subArray.begin(), subArray.end());

    for (int i = 0; i < subArray.size(); i++) {
        arr[minIdx + 1 + i] = subArray[i];
    }
}

int main() {
    srand(time(0));

    vector<int> arr;
    generateRandomArray(arr, 10);

    cout << "Zghenerovanyy masyv: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Kilkist elementiv, rivnykh pershomu: " << countEqualFirst(arr) << endl;

    swapElements(arr, 2, 5);
    cout << "Masyv pislya obminu elementiv na indeksakh 2 ta 5: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertElement(arr, 99, 3);
    cout << "Masyv pislya vstavky 99 u pozytsiyu 3: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Dovzhyna naydovshoyi poslidovnosti odnakovykh elementiv: " << longestIdenticalSection(arr) << endl;

    sortBetweenMinMax(arr);
    cout << "Masyv pislya sortuvannya mizh min ta max elementamy: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


