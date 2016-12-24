#include "skip_list.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

std::ostream& operator<<(std::ostream& os, const SkipList::Link& l)
{
	os << '(';
	if (l.val == INT_MIN)
	{
		os << "X ";
	}
	else
	{
		os << l.val << ' ';
	}

	if (l.up) 
	{
		os << '^';
		if (l.up->val == INT_MIN) os << "X ";
		else os << l.up->val << " ";
	}

	if (l.down) 
	{
		os << 'v';
		if (l.down->val == INT_MIN) os << "X ";
		else os << l.down->val << " ";
	}
	if (l.left) 
	{
		os << '<'; 
		if (l.left->val == INT_MIN) os << "X ";
		else os << l.left->val << " ";
	}
	if (l.right) 
	{
		os << '>'; 
		if (l.right->val == INT_MIN) os << "X ";
		else os << l.right->val << " ";
	}
	os << ')';

	return os;
}

std::ostream& operator<<(std::ostream& os, const SkipList& sl)
{
	SkipList::Link* currentHead = sl.head;
	while (currentHead)
	{
		SkipList::Link* currentNode = currentHead;
		while (currentNode)
		{
			os << *currentNode << ' ';
			currentNode = currentNode->right;
		}
		
		os << '\n';
		currentHead = currentHead->down;
	}

	return os;
}

SkipList::SkipList() // constructor
	: levels(0)
{
	this->head = new Link();
}

SkipList::~SkipList() // destructor
{
	destroyObject();
}

SkipList::SkipList(const SkipList& sl) // copy constructor
{
	copyObject(sl);
}

SkipList& SkipList::operator=(const SkipList& sl) // copy assignment
{
	destroyObject();
	copyObject(sl);

	return *this;
}

// currentLevel is used for debug purposes
// for "Release" version, commented code is used
bool SkipList::insertVal(int value, int currentLevel)
{
/*
	int generated = rand() % 2;
	int currentLevel = 0;
	while (generated)
	{
		++currentLevel;
		generated = rand() % 2;
	}
*/

	while (this->levels < currentLevel)
	{
		Link* newHead = new Link();
		newHead->down = this->head;
		this->head->up = newHead;
		this->head = newHead;
		
		++this->levels;
	}

	int insertionDepth = this->levels - currentLevel;
	Link* currentRowHead = this->head;
	
	// find topmost row in which to insert value
	while (insertionDepth--) 
	{
		currentRowHead = currentRowHead->down;
		assert(currentRowHead != NULL);
	}

	Link* topNode = NULL;

	// insert on every lower row
	while (currentRowHead)
	{
		Link* currentNode = currentRowHead;

		// insert the new node into the correct order on the current row
		while (currentNode->right &&
			   currentNode->right->val <= value)
		{	
			currentNode = currentNode->right;
		}
		
		// if not already inserted
		if (currentNode->val != value)
		{
			Link* newNode = new Link(value);
			
			// connect node to neighbours
			newNode->left = currentNode;
			newNode->right = currentNode->right;

			// connect neighbours to node
			if (currentNode->right) currentNode->right->left = newNode;
			currentNode->right = newNode;

			// connect node to top row
			if (topNode) topNode->down = newNode;
			newNode->up = topNode;
			
			// the newly added node becomes the top node for the lower row
			topNode = newNode;
		}
		else
		{
			return false;
		}

		// go to lower row
		currentRowHead = currentRowHead->down;
	}

	return true;
}

bool SkipList::findVal(int value)
{
	Link* foundNode = this->findNode(value);
	if (foundNode) return true;

	return false;
}

bool SkipList::deleteVal(int value)
{
	Link* foundNode = this->findNode(value);
	bool result = false;
	
	while (foundNode)
	{
		// remove node from current row
		if (foundNode->left) foundNode->left->right = foundNode->right;
		if (foundNode->right) foundNode->right->left = foundNode->left;
		
		// delete current node and move to lower row
		Link* nodeToDel = foundNode;
		foundNode = foundNode->down;
		delete nodeToDel;
		
		result = true;
	}

	return result;
}

SkipList::Link* SkipList::findNode(int value)
{
	Link* currentNode = this->head;
	
	// while the row exists
	while (currentNode)
	{
		// find correct position for searched node in current row
		while (currentNode->right &&
			   currentNode->right->val <= value)
		{
			currentNode = currentNode->right;
		}

		if (currentNode->val == value)
		{
			return currentNode;
		}

		// move to lower row, but skip lesser elements
		currentNode = currentNode->down;
	}

	return NULL;
}
	
void SkipList::destroyObject()
{
	Link* currentRowHead = this->head;
	Link* currentNode;
	Link* delNode;

	while (currentRowHead)
	{
		currentNode = currentRowHead->right;
		
		// delete current row
		while (currentNode)
		{
			delNode = currentNode;
			currentNode = currentNode->right;
			delete delNode;
		}
		
		// delete current row head and move to the lower row
		delNode = currentRowHead;
		currentRowHead = currentRowHead->down;
		delete delNode;
	}
}

void SkipList::copyObject(const SkipList& sl)
{
	// reinitialize object
	this->head = new Link();
	this->levels = 0;
	
	Link* currentRow = sl.head;
	Link* currentNode;
	int currentLevel = sl.levels;
	
	// copy row
	while (currentRow)
	{
		currentNode = currentRow->right;
		// copy row contents
		while (currentNode)
		{
			// if value already inserted, nothing will happen
			this->insertVal(currentNode->val, currentLevel);
			currentNode = currentNode->right;
		}

		--currentLevel;
		currentRow = currentRow->down;
	}
	
	// all levels inserted
	assert(currentLevel == -1);
}
