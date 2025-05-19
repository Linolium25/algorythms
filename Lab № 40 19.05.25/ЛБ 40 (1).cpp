#include <iostream>
#include <string>

using namespace std;

// Базовий клас
class Notification {
protected:
    string title;
    string text;

public:
    Notification(const string& t, const string& txt)
        : title(t), text(txt) {}

    virtual void show() const {
        cout << "Zagolovok: " << title << endl;
        cout << "Tekst: " << text << endl;
    }

    virtual ~Notification() {} // Віртуальний деструктор
};

// Похідний клас
class ImportantNotification : public Notification {
private:
    string priority; // rivень важливості: nyz'kyy, seredniy, vysokyy
    void (*extraAction)(); // вказівник на функцію без параметрів

public:
    ImportantNotification(const string& t, const string& txt, const string& p)
        : Notification(t, txt), priority(p), extraAction(0) {}

    void setExtraAction(void (*action)()) {
        extraAction = action;
    }

    void show() const {
        Notification::show();
        cout << "Riven' vazhlyvosti: " << priority << endl;

        if (priority == "vysokyy" && extraAction) {
            extraAction(); // виклик додаткової дії
        }
    }
};

// Зовнішня функція, яку передамо як додаткову дію
void confirmationMessage() {
    cout << "Potribne pidtverdzhennya!" << endl;
}

// Демонстраційна програма
int main() {
    ImportantNotification notif("Uvaha!", "Tse duzhe vazhlyve povidomlennya.", "vysokyy");

    // Встановлення додаткової дії
    notif.setExtraAction(&confirmationMessage);

    // Виведення сповіщення
    notif.show();

    return 0;
}

