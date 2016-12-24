#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <climits>
#include <iostream>

class SkipList
{
private:
	struct Link
	{
		int val;
		Link* right;
		Link* left;
		Link* up;
		Link* down;

		Link(int value = INT_MIN)
			: val(value), right(NULL), left(NULL), up(NULL), down(NULL) {};

	};
	
	int levels;
	Link* head;
	Link* findNode(int value);
	void destroyObject();
	void copyObject(const SkipList& sl);
public:
	SkipList(); // constructor
	~SkipList(); // destructor
	SkipList(const SkipList& sl); // copy constructor
	SkipList& operator=(const SkipList& sl); // copy assignment

	bool insertVal(int value, int currentLevel);
	bool findVal(int value);
	bool deleteVal(int value);
		
	friend std::ostream& operator<<(std::ostream& os, const SkipList::Link& l);
	friend std::ostream& operator<<(std::ostream& os, const SkipList& sl);
};

#endif // SKIP_LIST_H
