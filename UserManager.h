#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager {

    int loggedUserId;

    vector <User> users;
    UserFile userFile;

    bool checkIfLoginExist(const string &login);
    User enterUserData();

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    }

    void registerUser();

    void loginUser();
    bool isUserLoggedIn();
    int getLoggedUserId();

    void changeUserPassword();
    void logoutUser();
};

#endif
