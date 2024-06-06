#ifndef HOMEBUDGETAPP_H
#define HOMEBUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class HomeBudgetApp {

    UserManager userManager;
    BudgetManager *budgetManager;

    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    HomeBudgetApp(string userFileName, string incomeFileName, string expenseFileName)
        : userManager(userFileName),
          INCOME_FILE_NAME(incomeFileName),EXPENSE_FILE_NAME(expenseFileName) {
        budgetManager = NULL;
    };

    ~HomeBudgetApp() {
        delete budgetManager;
        budgetManager = NULL;
    };

    void registerUser();

    void loginUser();
    bool isUserLoggedIn();

    void changeUserPassword();
    void logoutUser();

    void addIncome();
    void addExpense();

    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
};

#endif
