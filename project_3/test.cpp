#include <iostream>
#include <string>
#include <cstdlib>
#include "BSTree.h"
using namespace std;

int main(int argCount, char *argValues[]) {
	/*
	 * See if MovieNode constructs and compares items correctly.
	 */
	BSTree::MovieNode item1, item2("Animal House", 1980, "PG-13", 90),
		item3("Animal House", 1980, "", 1000, "http://nowhere.com/animalhouse.mov");

	if (item1 == item2) {
		cout << "The items are equal" << endl;
	}
	if (item3 == item2) {
		cout << "The items are equal" << endl;
	}

	/*
	 * Create a binary search tree -- checking insert function in BSTree...
	 */
	BSTree firstTree;
	firstTree.insert("Animal House", 1980, "PG-13", 90);
	firstTree.insert("Batman", 1990, "PG-13", 98);
	firstTree.insert("Catch 22", 1960, "PG");
	firstTree.insert("Amelie", 1993);
	firstTree.insert("Act 2", 1999);
	firstTree.insert("Ants", 1000);
	return EXIT_SUCCESS;
}