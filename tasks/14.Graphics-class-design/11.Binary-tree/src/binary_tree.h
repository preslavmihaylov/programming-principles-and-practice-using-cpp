#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Graph.h"

class Binary_tree : public Graph_lib::Shape
{
public:
	class Invalid {};
	Binary_tree(Point rootPos, int levels, int nodeWidth, int nodeHeight);
	void move(int dx, int dy);

	// setters
	void setRootPos(Point rootPos);
	void setLevels(int levels);
	void setNodeWidth(int nodeWidth);
	void setNodeHeight(int nodeHeight);
	
	// getters
	Point getRootPos() const { return this->rootPos; }
	int getLevels() const { return this->levels; }
	int getNodeWidth() const { return this->nodeWidth; }
	int getNodeHeight() const { return this->nodeHeight; }

protected:
	void draw_lines() const;
	virtual void drawNode(Point location) const;
	virtual void drawLine(Point parentNodePos, Point childNodePos) const;
private:
	Point rootPos;
	int levels;
	int nodeWidth;
	int nodeHeight;

	void traverse(Point currentPos, 
				  int currentLevel,
	     		  int nodeOffsetY) const;
};

#endif // BINARY_TREE_H
