#pragma once

#include <iostream>
#include <vector>

#include "User.h"
#include "File.h"
#include "Utils.h"

using namespace std;

class UserFile : public File {

public:
    UserFile(string userFileName) : File(userFileName) {}

    vector <User> loadUsersFromFile();

    bool addUserToFile(const User &user);
    bool changePasswordInFile(int id, const string &password);
};
