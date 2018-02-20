#include "President.hpp"
#include <string>

using std::string;

President::President(string firstName, string middleName, string lastName,
                     Date termStart, Date termEnd)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->middleName = middleName;
    this->termStart = termStart;
    this->termEnd = termEnd;
}

string President::getFirstName() { return this->firstName; }
string President::getMiddleName() { return this->middleName; }
string President::getLastName() { return this->lastName; }
Date President::getTermStart() { return this->termStart; }
Date President::getTermEnd() { return this->termEnd; }