#ifndef BAR_GRAPH_H
#define BAR_GRAPH_H

#include "Graph.h"
#include <vector>

class BarGraph : public Graph_lib::Shape
{
public:
	BarGraph(double width, double height, Point orig, int barsCnt = 0);
	
	void addDataToBar(int i, double value);
	void setDataToBar(int i, double value);
	void addBar(string label = "", double value = 0);
	void set_fill_color(int i, Graph_lib::Color fcolor);
	void set_color(int i, Graph_lib::Color color);
	double getTotalValue() { return this->totalValue; };
	int getBarsCount() { return this->data.size(); };
protected:
	void draw_lines() const;
private:
	struct BarData
	{
		BarData(string label, 
				double value, 
				Graph_lib::Color color = Graph_lib::Color::blue,
				Graph_lib::Color fcolor = Graph_lib::Color::blue)
			: label(label), value(value), color(color), fcolor(fcolor) {};

		string label = "";
		double value;
		Graph_lib::Color color;
		Graph_lib::Color fcolor;
	};
	
	std::vector<BarData> data;
	double totalValue = 0;
	double width;
	double height;
	Point orig;
};

#endif // BAR_GRAPH_H
