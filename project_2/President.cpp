#include "President.hpp"
#include "Date.hpp"
#include <string>

using std::string;

string President::toString()
{
    string output = "";
    output += this->firstName + "\n";
    output += this->middleName + "\n";
    output += this->lastName + "\n";
    output += this->termStart->toString() + "\n";
    output += this->termEnd->toString() + "\n";
    output += this->party + "\n";
    output += this->state + "\n";
    return output;
}