#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// === ѕункт а) Ч "dubliuvaty slova z 2+ holosnymy"
bool hasMoreThanTwoVowels(const string& slovo) {
    string vowels = "аеЇи≥њоую€ј≈™»≤ѓќ”ёя";
    int count = 0;
    for (size_t i = 0; i < slovo.length(); ++i) {
        if (vowels.find(slovo[i]) != string::npos) {
            count++;
        }
    }
    return count > 2;
}

void duplicateWords(const string& fileName, stringstream& result) {
    ifstream in(fileName.c_str());
    string word;
    while (in >> word) {
        result << word << " "; // "zvychayne slovo"
        if (hasMoreThanTwoVowels(word)) {
            result << word << " "; // "dubliuvano slovo z 2+ holosnymy"
        }
    }
    in.close();
}

// === ѕункт б) Ч "3 naidovshi slova"

bool compareLength(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first.length() > b.first.length();
}

void topThreeLongestWords(const string& fileName, stringstream& result) {
    ifstream in(fileName.c_str());
    string word;
    map<string, int> freq;
    while (in >> word) {
        freq[word]++;
    }

    vector<pair<string, int> > wordList;
    map<string, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); ++it) {
        wordList.push_back(make_pair(it->first, it->second));
    }

    sort(wordList.begin(), wordList.end(), compareLength);

    result << "\n\"Top 3 longest words\" Ц \"3 naidovshi slova\":\n";
    for (int i = 0; i < 3 && i < wordList.size(); ++i) {
        result << "\"" << wordList[i].first << "\" Ц " << wordList[i].second << " raziv\n";
    }

    in.close();
}

// === ѕункт в) Ч "rechenniia z zadanym slovom"

void sentencesWithWord(const string& fileName, const string& searchWord) {
    ifstream in(fileName.c_str());
    stringstream buffer;
    buffer << in.rdbuf();
    string text = buffer.str();

    size_t start = 0;
    cout << "\n[Rechenniia, yaki mistiat slovo] \"" << searchWord << "\":\n";
    for (size_t i = 0; i < text.length(); ++i) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            string sentence = text.substr(start, i - start + 1);
            if (sentence.find(searchWord) != string::npos) {
                cout << sentence << endl;
            }
            start = i + 1;
        }
    }
    in.close();
}

// === ѕункт г) Ч "zberezhennia rezultat u z2.txt"

void saveToFile(const stringstream& result) {
    string path;
    cout << "\nVvedit shliakh dlia zberezhennia (napr.: z2.txt abo C:\\\\text\\\\z2.txt): ";
    cin.ignore();
    getline(cin, path);
    ofstream out(path.c_str());
    out << result.str();
    out.close();
    cout << "Rezultat zberezheno u file: \"" << path << "\"\n";
}

// === ѕункт д) Ч "obroblennia slova, yake zustrichaiet'sia bilshe 1 razu"

class MyString {
public:
    string slovo;
    MyString(string s) {
        slovo = s;
    }
};

void searchWordLogic(const string& fileName, const string& slovo) {
    ifstream in(fileName.c_str());
    stringstream text;
    text << in.rdbuf();
    string content = text.str();

    size_t first = content.find(slovo);
    size_t last = content.rfind(slovo);
    int count = 0;
    size_t pos = 0;

    while ((pos = content.find(slovo, pos)) != string::npos) {
        count++;
        pos += slovo.length();
    }

    if (count <= 1) {
        cout << "? Slovo \"" << slovo << "\" zustrichaiet'sia lish 1 raz abo ne znaideno.\n";
        return;
    }

    content.erase(first + slovo.length(), last - first - slovo.length());

    ofstream out("z3.txt");
    out << "Slovo: \"" << slovo << "\"\nZustrichaiet'sia: " << count << " raziv\n";
    out << "\nObroblenyi tekst:\n" << content;
    out.close();

    cout << "Rezultat zberezheno u z3.txt\n";
}

// === ѕункт е) Ч "formuvannia s1 s2 ta sortuvannia v alfavitnomu poriadku"

void wordSorting(const string& mainFile, const string& tFile) {
    ifstream inMain(mainFile.c_str());
    ifstream inT(tFile.c_str());
    vector<string> s1, s2;
    string word;

    while (inMain >> word) s2.push_back(word);
    while (s1.size() < s2.size() && inT >> word) s1.push_back(word);

    vector<string> s3 = s1;
    for (size_t i = 0; i < s2.size(); ++i) s3.push_back(s2[i]);

    sort(s3.begin(), s3.end());

    ofstream out("z4.txt");
    out << "s1: (slova z t.txt)\n";
    for (size_t i = 0; i < s1.size(); ++i) out << s1[i] << " ";

    out << "\n\ns2: (slova z z1.txt)\n";
    for (size_t i = 0; i < s2.size(); ++i) out << s2[i] << " ";

    out << "\n\ns3 (sorted): (vsi slova v alfavitnomu poriadku)\n";
    for (size_t i = 0; i < s3.size(); ++i) out << s3[i] << " ";

    out.close();
    cout << "Rezultat zberezheno u z4.txt\n";
}

// === ћ≈Ќё Ч пункт Ї)
int main() {
    string fileName = "z1.txt";
    stringstream result;
    int vybir;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1 Ц Dubluvaty slova z 2+ holosnymy (a)\n";
        cout << "2 Ц Naidovshi slova (b)\n";
        cout << "3 Ц Rechenniia z zadanym slovom (v)\n";
        cout << "4 Ц Zberehty rezultat u z2.txt (g)\n";
        cout << "5 Ц Poshuk i obroblennia slova (d)\n";
        cout << "6 Ц Sortuvannia s1+s2 u z4.txt (e)\n";
        cout << "0 Ц Vykhid\n";
        cout << "Vash vybir: ";
        cin >> vybir;

        switch (vybir) {
            case 1:
                result.str("");
                duplicateWords(fileName, result);
                cout << "\n[REZULTAT a)]\n" << result.str();
                break;
            case 2:
                result.str("");
                topThreeLongestWords(fileName, result);
                cout << "\n[REZULTAT b)]\n" << result.str();
                break;
            case 3: {
                string shukane;
                cout << "Vvedit slovo dlia poshuku: ";
                cin >> shukane;
                sentencesWithWord(fileName, shukane);
                break;
            }
            case 4:
                saveToFile(result);
                break;
            case 5: {
                string slovo;
                cout << "Vvedit slovo dlia obroblennia: ";
                cin >> slovo;
                MyString m(slovo);
                searchWordLogic(fileName, m.slovo);
                break;
            }
            case 6:
                wordSorting(fileName, "t.txt");
                break;
            case 0:
                cout << "Do pobachennia!\n";
                break;
            default:
                cout << "Nevirnyi vybir. Sprobuite shche raz.\n";
        }

    } while (vybir != 0);

    return 0;
}

// проблема у зв'€зку з файлами.//
