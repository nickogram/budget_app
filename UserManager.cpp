#include "UserManager.h"

bool UserManager::checkIfLoginExist(const string &login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].login == login) {
            cout << endl << "Entered login is already exist. Please try again" << endl;
            return true;
        }
    }
    return false;
}

User UserManager::enterUserData() {
    User user;

    cout << endl << "Enter data for the new user!" << endl;
    user.id = userFile.getLastId() + 1;
    cout << "Login: ";
    user.login = Utils::getLine();

    while (checkIfLoginExist(user.login)) {
        cout << "Login: ";
        user.login = Utils::getLine();
    }
    cout << "Password: ";
    user.password = Utils::getLine();
    cout << "First name: ";
    user.firstName = Utils::getLine();
    cout << "Last name: ";
    user.lastName = Utils::getLine();
    cout << "Please remember this details to log in --> Login: " + user.login + " Password: " + user.password << endl;

    return user;
}

void UserManager::registerUser() {
    if (userFile.addUserToFile(enterUserData())) {
        cout << "\nSuccessfully added new user!\n";
        system("pause");
        users.clear();
        users = userFile.loadUsersFromFile();
    } else {
        cout << "\nSomething goes wrong. New user has not been added!\n";
        system("pause");
    }
}

void UserManager::loginUser() {
    bool loginFindingStatus = false;
    bool passwordStatus = false;
    int numberOfTries = 3;

    string checkUserPassword = "";

    cout << endl << "Enter a Username to log in: ";
    string checkUserLogin = Utils::getLine();

    for (size_t i=0; i < users.size(); i++) {
        if (users[i].login == checkUserLogin) {
            loginFindingStatus = true;

            while (numberOfTries > 0) {
                cout << endl << "Number of tries: " << numberOfTries;
                cout << endl << "Enter a Password to log in: ";
                checkUserPassword = Utils::getLine();

                if (users[i].password == checkUserPassword) {
                    passwordStatus = true;
                    loggedUserId = users[i].id;
                    cout << endl << "User was successfully logged." << endl << endl;
                    system("pause");
                    break;
                } else numberOfTries--;
            }
            if (!passwordStatus) {
                cout << endl << "Limit of incorrectly entered passwords has been exceeded" << endl << endl;
                system("pause");
            }
        }
    }
    if (!loginFindingStatus) {
        cout << "Login not found" << endl;
        system("pause");
    }
}

bool UserManager::isUserLoggedIn() {
    if (loggedUserId == 0) return false;
    else return true;
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::logoutUser() {
    loggedUserId = 0;
    cout << endl << "User has been logout." << endl;
    cout << "Back to HOME MENU" << endl << endl;
    system("pause");
}

void UserManager::changeUserPassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = Utils::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> id == loggedUserId) {
            itr -> password = newPassword;
        }
    }
    if (userFile.changePasswordInFile(loggedUserId, newPassword)) {
        cout << endl << "Password has been changed." << endl << endl;
        system("pause");
        users.clear();
        users = userFile.loadUsersFromFile();
    } else {
        cout << endl << "Something goes wrong. Password has not been changed." << endl << endl;
        system("pause");
    }
}
