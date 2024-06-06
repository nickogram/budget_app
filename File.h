#pragma once

#include <iostream>
#include "Markup.h"

using namespace std;

class File {

    const string FILE_NAME;

protected:
    File (string fileName) : FILE_NAME(fileName) {
        lastId = getLastId();
    }
    int lastId = 0;
    CMarkup xmlDoc;
    string getFileName();
public:
    int getLastId();
};
