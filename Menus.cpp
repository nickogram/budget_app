#include "Menus.h"

void Menus::showTitle(string title) {
    cout << title << endl;
}

void Menus::showHomeMenu() {
    cout << "    >>> HOME MENU <<<" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Login user " << endl;
    cout << "2. Register new user " << endl << endl;
    cout << "9. Exit program " << endl;
    cout << "--------------------------" << endl << endl;
}

void Menus::showMainMenu() {
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Add income " << endl;
    cout << "2. Add expense " << endl;
    cout << "3. Show current month balance " << endl;
    cout << "4. Show previous month balance " << endl;
    cout << "5. Show custom period balance " << endl << endl;
    cout << "6. Change user password " << endl << endl;
    cout << "8. Log out " << endl;
    cout << "--------------------------" << endl << endl;
}
