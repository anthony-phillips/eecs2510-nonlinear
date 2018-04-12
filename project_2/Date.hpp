#ifndef DATE_H
#define DATE_H
#include <string>
#include <map>

class Date
{
public:
    int year;
    int month;
    int day;
    static std::map<std::string, int> months;

    Date();
    Date(std::string dateString);

    static int parseMonth(std::string monthName);
    std::string toString();
};

#endif