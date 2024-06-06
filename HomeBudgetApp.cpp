#include "HomeBudgetApp.h"

void HomeBudgetApp::registerUser() {
    userManager.registerUser();
}

void HomeBudgetApp::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager (INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

bool HomeBudgetApp::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void HomeBudgetApp::changeUserPassword() {
    userManager.changeUserPassword();
}

void HomeBudgetApp::logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void HomeBudgetApp::addIncome() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->addIncome();
    }
}

void HomeBudgetApp::addExpense() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->addExpense();
    }
}

void HomeBudgetApp::showCurrentMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->showCurrentMonthBalance();
    }
}

void HomeBudgetApp::showPreviousMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->showPreviousMonthBalance();
    }
}

void HomeBudgetApp::showCustomPeriodBalance() {
    if (userManager.isUserLoggedIn()) {
        budgetManager->showCustomPeriodBalance();
    }
}
