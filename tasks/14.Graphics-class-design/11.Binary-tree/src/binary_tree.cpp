#include "binary_tree.h"
#include <cmath>

#define STARTING_LEVEL (1)
#define NODE_OFFSET_X (50)
#define NODE_OFFSET_Y (50)

Binary_tree::Binary_tree(Point rootPos, 
					     int levels, 
						 int nodeWidth, 
						 int nodeHeight)
{
	this->setRootPos(rootPos);
	this->setNodeWidth(nodeWidth);
	this->setNodeHeight(nodeHeight);
	this->setLevels(levels);
}

void Binary_tree::setRootPos(Point rootPos)
{
	this->rootPos = rootPos;
}

void Binary_tree::setLevels(int levels)
{
	if (levels < 0)
	{
		error("levels cannot be negative");
	}

	this->levels = levels;
}

void Binary_tree::setNodeWidth(int nodeWidth)
{
	if (nodeWidth <= 0)
	{
		error("nodeWidth must be positive");
	}

	this->nodeWidth = nodeWidth;
}

void Binary_tree::setNodeHeight(int nodeHeight)
{
	if (nodeHeight <= 0)
	{
		error("nodeHeight must be positive");
	}

	this->nodeHeight = nodeHeight;
}

void Binary_tree::move(int dx, int dy)
{
	this->rootPos.x += dx;
	this->rootPos.y += dy;
}

void Binary_tree::draw_lines() const
{
	traverse(this->rootPos, 
			 STARTING_LEVEL, 
			 NODE_OFFSET_Y);
}

void Binary_tree::drawLine(Point parentNodePos, Point childNodePos) const
{
	fl_line(
		parentNodePos.x + (this->nodeWidth / 2),
		parentNodePos.y + (this->nodeHeight),
		childNodePos.x + (this->nodeWidth / 2),
		childNodePos.y);	
}

void Binary_tree::drawNode(Point location) const
{
    if (color().visibility()) { 
        fl_color(color().as_int());
        fl_rect(location.x, location.y, this->nodeWidth, this->nodeHeight);
    }
}

void Binary_tree::traverse(Point currentPos, 
						   int currentLevel,
						   int nodeOffsetY) const
{
	if (currentLevel > this->levels)
	{
		return;
	}

	int offsetX = 
		(this->nodeWidth * (this->levels * 2)) / pow(2, currentLevel - 1);
	Point leftNodePos(
		currentPos.x - offsetX, 
		currentPos.y + nodeOffsetY + this->nodeHeight);
	
	Point rightNodePos(
		currentPos.x + offsetX, 
		currentPos.y + nodeOffsetY + this->nodeHeight);

	if (this->levels - currentLevel > 0)
	{
		this->drawLine(currentPos, leftNodePos);
		this->drawLine(currentPos, rightNodePos);
	}
	
	this->drawNode(currentPos);
	traverse(leftNodePos, 
			 currentLevel + 1, 
			 nodeOffsetY);
	
	traverse(rightNodePos, 
			 currentLevel + 1, 
			 nodeOffsetY);
}
