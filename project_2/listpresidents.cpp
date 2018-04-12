#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include "Date.hpp"
#include "President.hpp"

using namespace std;

President* presidents [100];

int main()
{
    ifstream inFile;
    inFile.open("presidents.txt");

    int lineCount = 0;
    int presCount = 0;
    string line;
    {
        President* president = new President();
        while (std::getline(inFile, line))
        {
            switch (lineCount)
            {
                case 0:
                    president = new President();
                    president->firstName = line;
                    break;
                case 1:
                    president->middleName = line;
                    break;
                case 2:
                    president->lastName = line;
                    break;
                case 3:
                    president->termStart = new Date(line);
                    break;
                case 4:
                    president->termEnd = new Date(line);
                    break;
                case 5:
                    president->party = line;
                    break;
                case 6:
                    president->state = line;
                    presidents[presCount++] = president;
                    lineCount = 0;
                    continue;
            }
            lineCount++;
        }
    }

    while (true)
    {
        string userInput;
        string arg;
        getline(cin, userInput);
        char command = userInput.at(0);
        arg = userInput.substr(userInput.find(" "), userInput.length()-1);

        switch (command)
        {
            case 'L':
                for (President* president : presidents)
                    cout << president->toString() << endl;
                continue;
            case 'A':
            {
                President* president = new President();
                cout << "Enter first name : ";
                cin >> president->firstName;

                cout << "Enter middle name : ";
                cin >> president->middleName;

                cout << "Enter last name : ";
                cin >> president->lastName;

                string input;
                cout << "Enter start of term : ";
                cin >> input;
                president->termStart = new Date(input);

                cout << "Enter end of term : ";
                cin >> input;
                president->termEnd = new Date(input);

                cout << "Enter party : ";
                cin >> president->party;

                cout << "Enter state : ";
                cin >> president->state;
                continue;
            }
            case 'F':
            {
                for (President* president : presidents)
                {
                    if (president->state == arg)
                        cout << president->toString() << endl;
                }
            }
            case 'P':
            {
                string firstName, middleName, lastName;
                cout << "First Name: ";
                cin >> firstName;
                cout << "Middle Name: ";
                cin >> middleName;
                cout << "Last Name: ";
                cin >> lastName;
            }
            case 'N':
            {
                string firstName, middleName, lastName;
                cout << "First Name: ";
                cin >> firstName;
                cout << "Middle Name: ";
                cin >> middleName;
                cout << "Last Name: ";
                cin >> lastName;
            }
            case 'Q':
            {
                ofstream outFile;
                outFile.open("presidents.txt", ofstream::trunc);
                for (President* president : presidents)
                {
                    outFile << president->toString();
                }
                return 0;
            }
            default:
                cout << "Invalid command." << endl;
        }
    }
    return 0;
}
