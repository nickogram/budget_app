#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "Operation.h"
#include "File.h"
#include "Utils.h"

using namespace std;

class OperationFile : public File {

public:
    OperationFile(string fileName) : File(fileName) {}

    vector <Operation> loadOperationsFromFile(const int &loggedUserId);
    bool addOperationToFile (const Operation &operation);
};
