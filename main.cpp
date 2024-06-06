#include <iostream>

#include "HomeBudgetApp.h"
#include "Menus.h"

using namespace std;

int main() {
    HomeBudgetApp homeBudgetApp ("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true) {
        system("cls");

        if (!homeBudgetApp.isUserLoggedIn()) {
            Menus::showHomeMenu();

            cout << "Your choice: ";
            choice = Utils::getCharacter();

            switch (choice) {
            case '1':
                homeBudgetApp.loginUser();
                break;
            case '2':
                homeBudgetApp.registerUser();
                break;
            case '9':
                cout << "\nSee you next time.\n";
                exit(0);
                break;
            default:
                cout << "\nCharacter not used. Try again.\n" << endl;
                system("pause");
                break;
            }
        } else {
            Menus::showMainMenu();

            cout << "Your choice: ";
            choice = Utils::getCharacter();

            switch (choice) {
            case '1':
                homeBudgetApp.addIncome();
                break;
            case '2':
                homeBudgetApp.addExpense();
                break;
            case '3':
                homeBudgetApp.showCurrentMonthBalance();
                break;
            case '4':
                homeBudgetApp.showPreviousMonthBalance();
                break;
            case '5':
                homeBudgetApp.showCustomPeriodBalance();
                break;
            case '6':
                homeBudgetApp.changeUserPassword();
                break;
            case '8':
                homeBudgetApp.logoutUser();
                break;
            default:
                cout << "\nCharacter not used. Try again.\n" << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
