#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    srand(time(0)); 

    int n;
    cout << "Rozmir (n x n): ";
    cin >> n;

    char** matrix = new char*[n];//дв.м
    for (int i = 0; i < n; i++)
        matrix[i] = new char[n];

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};//м.гб.діаг.

    for (int i = 0; i < n; i++) {//V.S
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                matrix[i][j] = vowels[rand() % 5]; 
            } else {
                char letter;
                do {
                    letter = 'A' + rand() % 26; 
                } while (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U'); //zal pr
                matrix[i][j] = letter; 
            }
        }
    }

    cout << "Zhenerovana matrica: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    string word;
    cout << "Slovo dla poshucy: ";
    cin >> word;

   for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }

    int len = word.length();
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - len; j++) {
            bool match = true;
            for (int k = 0; k < len; k++) {
                if (matrix[i][j + k] != word[k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Slovo znaydeno y radky:" << i  << " pozusciyi" << j + 1 << " - " << j + len << ")\n";
                found = true;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n - len; i++) {
            bool match = true;
            for (int k = 0; k < len; k++) {
                if (matrix[i + k][j] != word[k]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Slovo y stovpcsi  " << j + 1 << " pozuchiyi  " << i << " - " << i + len-1 << ")\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Slovo ne znaydeno y matrici .\n";
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
// колись потрібно буде спробувати класну штуку але з цим потрібно ще буде повозитись: highlight- Віділяє знайдені букви
// проблема №1 яка була полягала в тому що неправильно рахувала в якому рядку( тобто вказувала рядок наступний ніж на якому знаходилось слово)\\\ 
// ПРОБЛУМА №2  неправильно показувалo кординати букв у стовпці ХОЧА  стовпець,вказується: вирішилося тоді коли я замість біля позиці i+1 змінила на просто i 
