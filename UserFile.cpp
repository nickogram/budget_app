#include "UserFile.h"

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    bool fileExistStatus = xmlDoc.Load(getFileName());

    if (!fileExistStatus) {
        cout << "Hello! I see you first time open this app :)" << endl;
        cout << "For proper work of application - add new user." << endl;
        cout << "I hope you will like it ;)" << endl << endl;
        system("pause");
    } else {
        xmlDoc.ResetPos();
        xmlDoc.FindElem();
        xmlDoc.IntoElem();

        while (xmlDoc.FindElem("User")) {
            xmlDoc.IntoElem();
            xmlDoc.FindElem("id");
            user.id = atoi(MCD_2PCSZ(xmlDoc.GetData()));
            xmlDoc.FindElem("login");
            user.login = xmlDoc.GetData();
            xmlDoc.FindElem("password");
            user.password = xmlDoc.GetData();
            xmlDoc.FindElem("name");
            user.firstName = xmlDoc.GetData();
            xmlDoc.FindElem("surname");
            user.lastName = xmlDoc.GetData();
            xmlDoc.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}

bool UserFile::addUserToFile(const User &user) {
    bool addUserStatus = false;
    bool fileExistStatus = xmlDoc.Load(getFileName());

    if (!fileExistStatus) {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("Users");
    }
    xmlDoc.ResetPos();
    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("User");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("id", user.id);
    xmlDoc.AddElem("login", user.login);
    xmlDoc.AddElem("password", user.password);
    xmlDoc.AddElem("name", user.firstName);
    xmlDoc.AddElem("surname", user.lastName);
    addUserStatus = true;

    xmlDoc.Save(File::getFileName());

    return addUserStatus;
}

bool UserFile::changePasswordInFile(int loggedUserId,const string &newPassword) {
    bool changePasswordStatus = false;
    bool fileExistStatus = xmlDoc.Load(getFileName());

    if (!fileExistStatus) {
        cout << "File not found: " << getFileName() << endl;
        cout << "To create new file - add new user" << endl;
        system("pause");
    } else {
        xmlDoc.ResetPos();
        xmlDoc.FindElem();
        xmlDoc.IntoElem();

        while (xmlDoc.FindElem("User")) {
            xmlDoc.IntoElem();
            xmlDoc.FindElem("id");
            if (loggedUserId == atoi(MCD_2PCSZ(xmlDoc.GetData()))) {
                xmlDoc.FindElem("password");
                xmlDoc.SetData(newPassword);
                changePasswordStatus = true;
                xmlDoc.Save(File::getFileName());
                break;
            } else xmlDoc.OutOfElem();
        }
    }
    return changePasswordStatus;
}
