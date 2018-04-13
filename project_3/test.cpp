#include <iostream>
#include <string>
#include <cstdlib>
#include "BSTree.cpp"
using namespace std;

int main(int argCount, char *argValues[]) {
    BSTree tree;
	tree.readFromFile("movies.txt");

	while (true)
    {
        cout << "Command: ";
		string input;
		cin >> input;
		char command = input.at(0);

		string title, rating, url;
		int year, runningTime;

        switch (command)
        {			
            case 'L': {
				tree.list();
				break;
			}
            case 'I': {
                cout << "Enter title : ";
                cin >> title;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter Rating : ";
                cin >> rating;
                cout << "Enter length : ";
                cin >> runningTime;
                cout << "Enter URL: ";
                cin >> url;
				
				tree.insert(title, year, rating, runningTime, url);
				break;
			}
            case 'S': {
                cout << "Enter title : ";
                cin >> title;
                cout << "Enter year: ";
                cin >> year;

                BSTree::MovieNode* result = tree.search(title, year);

				if (result == nullptr)
					cout << "Movie not found.";
				break;
			}
            case 'D': {
                cout << "Enter title : ";
                cin >> title;
                cout << "Enter year: ";
                cin >> year;

				tree.remove(title, year);
				break;
			}
            case 'Q': {
				tree.writeToFile("movies.txt");
				return EXIT_SUCCESS;
			}
            default:
                cout << "Invalid command." << endl;
        }
    }
	return EXIT_SUCCESS;
}