#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Utils {

public:
    static char getCharacter();
    static string getLine();
    string readLine();
    bool validateInput(string input);
};
