#include "tri_binary_tree.h"

void Tri_Binary_tree::drawNode(Point location) const
{
	Point top(location.x + (this->getNodeWidth() / 2), location.y);
	Point left(location.x, location.y + this->getNodeHeight());
	Point right(location.x + this->getNodeWidth(), 
				location.y + this->getNodeHeight());

	// top-left
	fl_line(top.x, top.y, left.x, left.y);
	// top-right
	fl_line(top.x, top.y, right.x, right.y);
	// left-right
	fl_line(left.x, left.y, right.x, right.y);
}

void Tri_Binary_tree::drawLine(Point parentNodePos, 
							   Point childNodePos) const
{
	fl_color(Graph_lib::Color::red);
	fl_line(
		parentNodePos.x + (this->getNodeWidth() / 2),
		parentNodePos.y + (this->getNodeHeight()),
		childNodePos.x + (this->getNodeWidth() / 2),
		childNodePos.y);	
	
	fl_color(this->color().as_int());
}
