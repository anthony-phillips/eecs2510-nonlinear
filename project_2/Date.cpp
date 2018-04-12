#include "Date.hpp"
#include <map>
#include <string>
#include <iostream>
using std::string;

Date::Date() : year(0), month(0), day(0){};

Date::Date(string dateString)
{
    bool searching = false;
    
    string monthString = dateString.substr(0, dateString.find(' '));
    dateString = dateString.erase(0, dateString.find(" ")+1);
    this->month = parseMonth(monthString);

    string dayString = dateString.substr(0, dateString.find(" "));
    dateString = dateString.erase(0, dateString.find(" "));
    this->day = std::stoi(dayString.substr(0, dayString.length()-1));

    this->year = std::stoi(dateString);
}

std::map<std::string, int> Date::months =
{
    {"JANUARY", 1},
    {"FEBRUARY", 2},
    {"MARCH", 3},
    {"APRIL", 4},
    {"MAY", 5},
    {"JUNE", 6},
    {"JULY", 7},
    {"AUGUST", 8},
    {"SEPTEMBER", 9},
    {"OCTOBER", 10},
    {"NOVEMBER", 11},
    {"DECEMBER", 12}
};

int Date::parseMonth(string monthName)
{
    for (int i = 0; i < monthName.length(); i++)
        monthName[i] = std::toupper(monthName[i]);

    return months[monthName];
}

string Date::toString()
{
    return std::to_string(this->month) + "/" + 
    std::to_string(this->day) + "/" + std::to_string(this->year);
}