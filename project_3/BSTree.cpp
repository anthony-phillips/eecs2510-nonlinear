#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::MovieNode::MovieNode(string title, int year, string rating,
	int runningTime, string url,
	MovieNode * left, MovieNode * right,
	MovieNode *parent)
{
	this->title = title;
	this->year = year;
	this->rating = rating;
	this->runningTime = runningTime;
	this->url = url;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

/* 
 * Iterative method to insert a new movie into the binary search tree.  The routine
 * is responsible for allocating the node and inserting in place in the tree. 
 */
void BSTree::insert(string title, int year, string rating, int runningTime, string url) 
{
	MovieNode* newMovie = new MovieNode(title, year, rating, runningTime, url);
	
	cout << "PARSED:" << endl << newMovie->toString();

	// If tree is empty insert the node
	if (root == nullptr) {
		cout << "NULLPTR";
		root = newMovie;
		return;
	}

	// If the tree is not empty then find the insertion point, insert, and return
	MovieNode* current = root;
	do {
		if (*newMovie < *current) {  // add to left
			if (current->getLeft() == nullptr) {
				current->setLeft(newMovie);
				newMovie->setParent(current);
				return;
			}
			else {
				current = current->getLeft();
			}
		}
		else { // add to right
			if (current->getRight() == nullptr) {
				current->setRight(newMovie);
				newMovie->setParent(current);
				return;
			}
			else {
				current = current->getRight();
			}

		}
	} while (true);
}

// Remove a matching node from the tree
void BSTree::remove(string title, int year)
{
	throw exception();
}
// Read the contents of a file to build the tree
void BSTree::readFromFile(string filename)
{
    ifstream inFile;
    inFile.open(filename);

    int lineCount = 0;
    string line;

	string title, rating, url;
	int year, runningTime;

	while (getline(inFile, line))
	{
		cout << "LINE " + to_string(lineCount) + ": " + line << endl;
		switch (lineCount)
		{
			case 0: {
				title = line;
				year = 0;
				rating = "";
				runningTime = 0;
				url = "";
				break;
			}
			case 1: {
				year = stoi(line);
				break;
			}
			case 2: {
				rating = line;
				break;
			}
			case 3: {
				runningTime = stoi(line);
				break;
			}
			case 4: {
				url = line;
				cout << title + ", " + to_string(year) + ", " + rating + ", " + to_string(runningTime) + ", " + url << endl;
				insert(title, year, rating, runningTime, url);
				lineCount = -1;
				break;
			}
		}
		lineCount++;
	}
}

// Write the contents of the tree to a file
void BSTree::writeToFile(string filename)
{
	throw exception();
}

// Return a pointer to the searched movie node or a null pointer if not found
BSTree::MovieNode* BSTree::search(string title, int year)
{
	return root->search(title, year);
}

// List all the items in the tree using inorder traversal
void BSTree::list() {
	root->list();
}