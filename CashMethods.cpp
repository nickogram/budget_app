#include "CashMethods.h"

bool CashMethods::validateAmount(string amount) {
    if (amount.empty()) {
        cout << "Entered value is empty. Try again." << endl;
        system("pause");
        return false;
    } else {
        if (!std::regex_match(amount, std::regex("[0-9]+\\.[0-9]{2}"))) {
            cout << "Incorrect amount format. Try again." << endl;
            return false;
        } else return true;
    }
}
