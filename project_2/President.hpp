#ifndef PRESIDENT_H
#define PRESIDENT_H

#include <string>
#include "Date.hpp"

class President {

public:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string party;
    std::string state;
    Date* termStart;
    Date* termEnd;

    std::string toString();
};

#endif