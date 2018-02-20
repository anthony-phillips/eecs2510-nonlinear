#include <string>

class Date
{
private:
    int year;
    int month;
    int day;
 
public:
    Date(int year, int month, int day);
 
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay()  { return day; }

    static Date parseDate(std::string input);
};