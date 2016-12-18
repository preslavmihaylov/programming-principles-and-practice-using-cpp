#include "group.h"

void Group::draw() const
{
	for (int i = 0; i < this->shapes.size(); ++i)
	{
		this->shapes[i].draw();
	}
}

void Group::move(int dx, int dy)
{
	for (int i = 0; i < this->shapes.size(); ++i)
	{
		this->shapes[i].move(dx, dy);
	}
}

void Group::set_color(Graph_lib::Color col)
{
	for (int i = 0; i < this->shapes.size(); ++i)
	{
		this->shapes[i].set_color(col);
	}
}

void Group::set_style(Graph_lib::Line_style sty) 
{ 
	for (int i = 0; i < this->shapes.size(); ++i)
	{
		this->shapes[i].set_style(sty);
	}
}

void Group::set_fill_color(Graph_lib::Color col) 
{ 
	for (int i = 0; i < this->shapes.size(); ++i)
	{
		this->shapes[i].set_fill_color(col);
	}
}
