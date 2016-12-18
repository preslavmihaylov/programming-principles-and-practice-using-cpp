#include "bar_graph.h"

using namespace std;
using namespace Graph_lib;

#define LABEL_OFFSET_Y (20)
#define LABEL_OFFSET_X (20)

void drawRectangle(Point orig, 
				   double width, 
				   double height,
				   string label,
				   Color fcolor, 
				   Color color)
{
	if (fcolor.visibility()) 
	{    // fill
		fl_color(fcolor.as_int());
	    fl_rectf(orig.x, orig.y, width, height);
	}
 
    if (color.visibility()) 
	{    // lines on top of fill
		fl_color(color.as_int());
	    fl_rect(orig.x, orig.y, width, height);
    }
	
	fl_draw(label.c_str(),
			orig.x + LABEL_OFFSET_X,
			orig.y + height + LABEL_OFFSET_Y);
}

BarGraph::BarGraph(double width, 
				   double height, 
				   Point orig, 
				   int barsCnt)
{
	if (width <= 0) error("Invalid width");
	if (height <= 0) error("Invalid height");
	if (barsCnt < 0) error("Invalid bars count");

	this->width = width;
	this->height = height;
	this->orig = orig;
	
	for (int cnt = 0; cnt < barsCnt; ++cnt)
	{
		this->addBar("", 0);
	}
}
	
void BarGraph::addDataToBar(int i, double value)
{
	if (i >= this->data.size()) error("Invalid index for bar");
	this->data[i].value += value;
	this->totalValue += value;
}

void BarGraph::setDataToBar(int i, double value)
{
	if (i >= this->data.size()) error("Invalid index for bar");
	
	this->totalValue -= this->data[i].value;
	this->data[i].value = value;
	this->totalValue += value;
}

void BarGraph::addBar(string label, double value)
{
	if (value < 0) error("value cannot be negative");
	this->data.push_back(BarData(label, value));
	this->totalValue += value;
}

void BarGraph::set_fill_color(int i, Graph_lib::Color fcolor)
{
	if (i >= this->data.size()) error("Invalid index for bar");
	this->data[i].fcolor = fcolor;
}

void BarGraph::set_color(int i, Graph_lib::Color color)
{
	if (i >= this->data.size()) error("Invalid index for bar");
	this->data[i].color = color;
}

void BarGraph::draw_lines() const
{
	double barWidth = this->width / this->data.size();
	double currentBarHeight;
	Point currentPoint = this->orig;

	for (int i = 0; i < this->data.size(); ++i)
	{
		double currentPercent = this->data[i].value / this->totalValue;
		currentBarHeight = currentPercent * this->height;
		currentPoint.y = this->orig.y - currentBarHeight;
		
		drawRectangle(currentPoint, 
					  barWidth, 
					  currentBarHeight,
					  this->data[i].label,
					  this->data[i].fcolor, 
					  this->data[i].color);		
		
		currentPoint.x += barWidth;
	}
}
