#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    ifstream inputFile("text.txt"); 
    if (!inputFile) {
        cout << "File not found!\n";
        return 1;
    }

    char words[100][100]; 
    int totalWords = 0;

    while (inputFile >> words[totalWords]) { 
        totalWords++;
    }
    inputFile.close();

    cout << "Slova z 3-kh liter:\n";
    for (int i = 0; i < totalWords; i++) {
        if (strlen(words[i]) == 3) {
            cout << words[i] << " ";
        }
    }
    cout << endl;

    cout << "Slova, yaki ne pochynaiut'sia z velykoi litery:\n";
    for (int i = 0; i < totalWords; i++) {
        if (!isupper(words[i][0])) {
            cout << words[i] << " ";
        }
    }
    cout << endl;

    cout << "Vvedit slovo dlia poshuku: ";
    char searchWord[100];
    cin >> searchWord;

    for (int i = 0; searchWord[i]; i++) {
        searchWord[i] = tolower(searchWord[i]);
    }

    int matchCount = 0;
    for (int i = 0; i < totalWords; i++) {
        char temp[100];
        strcpy(temp, words[i]);

        for (int j = 0; temp[j]; j++) {
            temp[j] = tolower(temp[j]);
        }

        if (strcmp(temp, searchWord) == 0) {
            matchCount++;
        }
    }

    cout << "Slovo \"" << searchWord << "\" zustrichaietsia " << matchCount << " raziv.\n";

    return 0;
}

