#include <iostream> 
#include <cstdlib>  
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    srand(time(0));  

    int n; 
    cout << "Rozmir matrichii (n x n): ";
    cin >> n;  

    // Дин.дв.м
    char** matrix = new char*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new char[n];

    char vowels[] = {'A', 'E', 'I', 'O', 'U'}; 

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {  
                matrix[i][j] = vowels[rand() % 5];  
            } else {
                char letter;
                do {
                    letter = 'A' + rand() % 26;  
                } while (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
                matrix[i][j] = letter;
            }
        }
    }

    cout << "Zhenerovana matrica:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";  
        cout << endl;
    }

    string word;
    cout << "Slovo dla poshuku: ";
    cin >> word;  

    //рег.
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }

    int len = word.length();  
    bool found = false;  

    // гор.
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
                cout << "Slovo znaydeno y radky: " << i + 1 << " pozuchiyi " << j + 1 << " - " << j + len << ")\n";
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
                cout << "Slovo znaydeno y stovpci " << j + 1 << " pozuchiyi " << i + 1 << " - " << i + len << ")\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Slovo ne znaydeno y matrici.\n";
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i]; 
    delete[] matrix;  

    return 0;
}

