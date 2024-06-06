#include "DateMethods.h"

void DateMethods::calculateCurrentDate(std::map<std::string, int> &currentDate) {
    auto currentTime = std::chrono::system_clock::now();
    time_t currentDateTime = std::chrono::system_clock::to_time_t(currentTime);

    std::tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;
}

bool DateMethods::validateDate(string &date) {
    int year, month, day;
    std::map<std::string, int> currentDate;
    std::stringstream ss;

    calculateCurrentDate(currentDate);

    if (date == "y" || date == "Y") {
        ss << currentDate["year"] << "-" << (currentDate["month"] < 10 ? "0" : "") << currentDate["month"] << "-" << (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
        date = ss.str();
        return true;
    }

    if (date.length() != 10) {
        cout << "Incorrect date format. Try again" << endl;
        return false;
    }

    if (!std::regex_match(date, std::regex("[0-9]{4}-[0-9]{2}-[0-9]{2}"))) {
        cout << "Incorrect date format. Try again" << endl;
        return false;
    }

    try {
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(5,2));
        day = stoi(date.substr(8,2));
    } catch (const exception& e) {
        cout << "Exception occured: " << e.what() << endl;
        return false;
    }

    if (year < 2000 || year > currentDate["year"]) {
        cout << "Invalid year. Try again. " << endl;
        return false;
    }

    if (month < 1 || month > 12 || (year == currentDate["year"] && month > currentDate["month"])) {
        cout << "Invalid month. Try again. " << endl;
        return false;
    }

    switch (month) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if (day > 31) {
                cout << "Invalid day. Try again. " << endl;
                return false;
            }
            break;
        case 4:case 6:case 9:case 11:
            if (day > 30) {
                cout << "Invalid day. Try again. " << endl;
                return false;
            }
        case 2:
            if (DateMethods::isYearLeap(year)) {
                if (day > 29) {
                    cout << "Invalid day. Try again. " << endl;
                    return false;
                }
            } else {
                if (day > 28) {
                    cout << "Invalid day. Try again. " << endl;
                    return false;
                }
            }
            break;
        default:
            cout << "Invalid day. Try again. " << endl;
            return false;
        }
    return true;
}

bool DateMethods::isYearLeap(int year) {
    if ((year%400 == 0 || year%100 != 0) && (year%4 == 0)) return true;
    else return false;
}

int DateMethods::convertStringDateToInt(string &dateAsString) {
    int dateAsInt = 0;

    dateAsString.erase(dateAsString.begin() + 4);
    dateAsString.erase(dateAsString.begin() + 6);
    dateAsInt = stoi(dateAsString);

    return dateAsInt;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt) {
    std::stringstream ss;
    string dateAsString = to_string(dateAsInt);

    dateAsString.insert(4,"-");
    dateAsString.insert(7,"-");

    return dateAsString;
}

int DateMethods::getCurrentDate() {
    std::stringstream ss;
    string currentDate = "";

    time_t now = time(0);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    ss << currentYear << (currentMonth < 10 ? "0" : "") << currentMonth << (currentDay < 10 ? "0" : "") << currentDay;
    currentDate = ss.str();

    int currentDateAsInt = stoi(currentDate);

    return currentDateAsInt;
}

int DateMethods::getCurrentMonthFirstDayDate() {
    std::stringstream ss;
    string currentMonthFirstDayDate = "";

    time_t now = time(0);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int firstDay = 1;

    ss << currentYear << (currentMonth < 10 ? "0" : "") << currentMonth << (firstDay < 10 ? "0" : "") << firstDay;
    currentMonthFirstDayDate = ss.str();

    int currentMonthFirstDayDateAsInt = stoi(currentMonthFirstDayDate);

    return currentMonthFirstDayDateAsInt;
}

int DateMethods::getPreviousMonthLastDayDate() {
    std::stringstream ss;
    string previousMonthLastDayDate = "";

    time_t now = time(0);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int lastMonth = ltm->tm_mon;
    int lastDay = getLastDayOfMonth(lastMonth, currentYear);

    ss << currentYear << (lastMonth < 10 ? "0" : "") << lastMonth << (lastDay < 10 ? "0" : "") << lastDay;
    previousMonthLastDayDate = ss.str();

    int previousMonthLastDayDateAsInt = stoi(previousMonthLastDayDate);

    return previousMonthLastDayDateAsInt;
}

int DateMethods::getPreviousMonthFirstDayDate() {
    std::stringstream ss;
    string previousMonthLastDayDate = "";

    time_t now = time(0);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int lastMonth = ltm->tm_mon;
    int firstDay = 1;

    ss << currentYear << (lastMonth < 10 ? "0" : "") << lastMonth << (firstDay < 10 ? "0" : "") << firstDay;
    previousMonthLastDayDate = ss.str();

    int lastMonthFirstDayDateAsInt = stoi(previousMonthLastDayDate);

    return lastMonthFirstDayDateAsInt;
}

int DateMethods::getLastDayOfMonth (int month, int year) {
    int numberOfDays = 0;
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if(month==2 && ((year%400==0) || ((year%100!=0)&&(year%4==0))))
        numberOfDays = arr[month-1]+1;

    else numberOfDays = arr[month-1];

    return numberOfDays;
}
