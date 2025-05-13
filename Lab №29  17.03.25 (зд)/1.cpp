#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_WORD_LEN = 100;

void toLowerCase(char* word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    ifstream fin("text.txt");
    if (!fin.is_open()) {
        cout << "Ne vdalosia vidkryty fail!" << endl;
        return 1;
    }

    char word[MAX_WORD_LEN];
    char** threeLetterWords = nullptr;
    char** lowerCaseWords = nullptr;
    int threeCount = 0, lowerCount = 0;

    while (fin >> word) {
        int len = strlen(word);

        while (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }

        if (len == 3) {
            char* temp = new char[len + 1];
            strcpy(temp, word);

            char** newArr = new char*[threeCount + 1];
            for (int i = 0; i < threeCount; i++) newArr[i] = threeLetterWords[i];
            newArr[threeCount++] = temp;

            delete[] threeLetterWords;
            threeLetterWords = newArr;
        }

        if (!isupper(word[0])) {
            char* temp = new char[len + 1];
            strcpy(temp, word);

            char** newArr = new char*[lowerCount + 1];
            for (int i = 0; i < lowerCount; i++) newArr[i] = lowerCaseWords[i];
            newArr[lowerCount++] = temp;

            delete[] lowerCaseWords;
            lowerCaseWords = newArr;
        }
    }

    fin.close();

    cout << "\nSlova z tryokh liter:\n";
    for (int i = 0; i < threeCount; i++) {
        cout << "\"" << threeLetterWords[i] << "\"\n";
        delete[] threeLetterWords[i];
    }
    delete[] threeLetterWords;

    cout << "\nSlova, shcho ne pochynaiutsia z velykoi litery:\n";
    for (int i = 0; i < lowerCount; i++) {
        cout << "\"" << lowerCaseWords[i] << "\"\n";
        delete[] lowerCaseWords[i];
    }
    delete[] lowerCaseWords;

    cout << "\nVvedit slovo dlia poshuku: ";
    char searchWord[MAX_WORD_LEN];
    cin >> searchWord;
    toLowerCase(searchWord);

    fin.open("text.txt");
    if (!fin.is_open()) {
        cout << "Ne vdalosia povtorno vidkryty fail!" << endl;
        return 1;
    }

    int count = 0;
    while (fin >> word) {
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }

        toLowerCase(word);
        if (strcmp(word, searchWord) == 0) {
            count++;
        }
    }

    fin.close();
    cout << "Slovo \"" << searchWord << "\" zustrichaietsia " << count << " raz(³â) u faile.\n";

    return 0;
}

