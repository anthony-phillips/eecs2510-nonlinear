#include "Date.hpp"

using std::string;

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getYear() { return this->year; }
int Date::getMonth() { return this->month; }
int Date::getDay()  { return this->day; }

Date Date::parseDate(string input)
{
    
}