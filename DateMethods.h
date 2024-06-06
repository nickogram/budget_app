#pragma once

#include <iostream>
//#include <string>
#include <chrono>
#include <regex>
#include <map>
#include <sstream>


using namespace std;

class DateMethods {

    static void calculateCurrentDate(std::map<std::string, int> &currentDate);
    static bool isYearLeap(int year);
    static int getLastDayOfMonth(int month, int year);

public:
    static bool validateDate(string &date);
    static int convertStringDateToInt(string &dateAsString);

    static string convertIntDateToStringWithDashes(int dateAsInt);

    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();

    static int getPreviousMonthLastDayDate();
    static int getPreviousMonthFirstDayDate();
};
