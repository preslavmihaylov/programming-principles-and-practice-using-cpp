#ifndef GROUP_H
#define GROUP_H

#include "Graph.h"

class Group 
{
public:
	Group() {};
	void draw() const;
	void move(int dx, int dy);
	
	void set_color(Graph_lib::Color col);
	void set_style(Graph_lib::Line_style sty);
	void set_fill_color(Graph_lib::Color col);
	
	void add(Graph_lib::Shape& shape) { this->shapes.push_back(shape); }
private:
	Graph_lib::Vector_ref<Graph_lib::Shape> shapes;
};

#endif // GROUP_H
