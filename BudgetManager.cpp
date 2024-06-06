#include "BudgetManager.h"

void BudgetManager::addIncome() {
    if (incomeFile.addOperationToFile(addOperationDetails(INCOME))) {
        cout << "Income operation has been added to file." << endl;
        system("pause");
        incomes.clear();
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
    } else {
        cout << "Something goes wrong. Income operation has not been added to file." << endl;
        system("pause");
    }
}

void BudgetManager::addExpense() {
    if (expenseFile.addOperationToFile(addOperationDetails(EXPENSE))) {
        cout << "Expense operation has been added to file." << endl;
        system("pause");
        expenses.clear();
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
    } else {
        cout << "Something goes wrong. Expense operation has not been added to file." << endl;
        system("pause");
    }
}

void BudgetManager::showCurrentMonthBalance() {
    showBalance(DateMethods::getCurrentMonthFirstDayDate(), DateMethods::getCurrentDate());
}

void BudgetManager::showPreviousMonthBalance() {
    showBalance(DateMethods::getPreviousMonthFirstDayDate(), DateMethods::getPreviousMonthLastDayDate());
}

void BudgetManager::showCustomPeriodBalance() {
    string startDate ="";
    string endDate ="";

    cout << endl << "--> Set periods for custom balance. " << endl;

    do {
        cout << "Enter start date in yyyy-mm-dd format or press 'y' if you want to enter current date: ";
        startDate = Utils::getLine();

    } while (!DateMethods::validateDate(startDate));

    do {
        cout << "Enter end date in yyyy-mm-dd format or press 'y' if you want to enter current date: ";
        endDate = Utils::getLine();

    } while (!DateMethods::validateDate(endDate));

    showBalance(DateMethods::convertStringDateToInt(startDate), DateMethods::convertStringDateToInt(endDate));
}

Operation BudgetManager::addOperationDetails (const Type &type) {
    string typeDescription, tempDate, tempAmount;
    Operation operation;

    Menus::showTitle("ADD OPERATION DETAILS");

    switch (type) {
    case INCOME:
        operation.id = incomeFile.getLastId() + 1;
        typeDescription = "income";
        break;
    case EXPENSE:
        operation.id = expenseFile.getLastId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    do {
        cout << "Enter " << typeDescription << " date in yyyy-mm-dd format or press 'y' if you want to enter current date: ";
        tempDate = Utils::getLine();

    } while (!DateMethods::validateDate(tempDate));

    operation.date = DateMethods::convertStringDateToInt(tempDate);
    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::getLine();

    do {
        cout << "Add " << typeDescription << " amount with up to decimal places: ";
        tempAmount = Utils::getLine();

        for (size_t i=0; i < tempAmount.length(); i++) {
            if (tempAmount[i] == ',') {
                tempAmount[i] = '.';
            }
        }
    } while (!CashMethods::validateAmount(tempAmount));

    operation.amount = stod(tempAmount);
    return operation;
}

void BudgetManager::showBalance (int startDate, int endDate) {
    double balanceIncome = 0.0;
    double balanceExpense = 0.0;
    double balanceSummary = 0.0;

    cout << endl << "--> Here your Incomes from: " << DateMethods::convertIntDateToStringWithDashes(startDate) <<
         " to " << DateMethods::convertIntDateToStringWithDashes(endDate) << endl;
    cout << "----------------------------------------------------" << endl;

    for (size_t i=0; i < incomes.size(); i++) {
        if (startDate <= incomes[i].date && endDate >= incomes[i].date) {
            cout << endl << DateMethods::convertIntDateToStringWithDashes(incomes[i].date) << endl;
            cout << "Income name: " << incomes[i].item << endl;
            cout << "Income amount: " << incomes[i].amount << endl;
            balanceIncome = balanceIncome + incomes[i].amount;
        }
    }

    cout << endl << "--> Here your Expenses from: " << DateMethods::convertIntDateToStringWithDashes(startDate) <<
         " to " << DateMethods::convertIntDateToStringWithDashes(endDate) << endl;
    cout << "----------------------------------------------------" << endl;

    for (size_t i=0; i < expenses.size(); i++) {
        if (startDate <= expenses[i].date && endDate >= expenses[i].date) {
            cout << endl << DateMethods::convertIntDateToStringWithDashes(expenses[i].date) << endl;
            cout << "Income name: " << expenses[i].item << endl;
            cout << "Income amount: " << expenses[i].amount << endl;

            balanceExpense = balanceExpense + expenses[i].amount;
        }
    }

    cout << endl << "------------ Summary ------------" << endl;

    balanceSummary = balanceIncome - balanceExpense;

    cout << "Summed up incomes: " << balanceIncome << endl;
    cout << "Summed up expenses: " << balanceExpense << endl << endl;
    cout << "Balance : " << balanceSummary << endl << endl;

    cout << "Press any button to back to MAIN MENU." << endl;
    system("pause");
}
