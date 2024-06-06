#include "Utils.h"

char Utils::getCharacter() {
    string in = "";
    char character  = {0};

    while (true) {
        getline(cin, in);

        if (in.length() == 1) {
            character = in[0];
            break;
        }
        cout << "Thats not a single character. Try again." << endl;
    }
    return character;
}

string Utils::getLine() {
    string getIn = "";
    getline (cin, getIn);
    return getIn;
}
