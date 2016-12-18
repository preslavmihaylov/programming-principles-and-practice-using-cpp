#ifndef TRI_BINARY_TREE_H
#define TRI_BINARY_TREE_H

#include "binary_tree.h"

class Tri_Binary_tree : public Binary_tree
{
public:
	Tri_Binary_tree(Point rootPos, 
					int levels, 
					int nodeWidth, 
					int nodeHeight)
		: Binary_tree(rootPos, levels, nodeWidth, nodeHeight) {};
protected:
	void drawNode(Point location) const;	
	void drawLine(Point parentNodePos, Point childNodePos) const;
};

#endif // TRI_BINARY_TREE_H
