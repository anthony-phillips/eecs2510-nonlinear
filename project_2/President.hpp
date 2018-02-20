#include <string>
#include "Date.hpp"

class President {

private:
    std::string firstName;
    std::string middleName;
    std::string lastName;
    Date termStart;
    Date termEnd;

public:
    President(string firstName, string middleName, string lastName,
              Date termStart, Date termEnd);
    std::string getFirstName();
    std::string getMiddleName();
    std::string getLastName();
    Date getTermStart();
    Date getTermEnd();
    
}