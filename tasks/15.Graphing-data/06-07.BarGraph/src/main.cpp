#include "Simple_window.h"
#include "Graph.h"
#include "bar_graph.h"

using namespace std;

#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define SCREEN_TITLE ("Bar Graph")

#define INPUT_TEXTFILE ("values.txt")
#define BAR_COLORS_CNT (6)
#define AXIS_OFFSET (20)

struct Reading
{
	int height;
	int peopleCnt;
};

Color barColors[] =
{
	Color::red,
	Color::green,
	Color::magenta,
	Color::cyan,
	Color::black,
	Color::yellow
};

istream& operator>>(istream& inputStream, Reading& r)
{
	char ch1, ch2, ch3;
	int height;
	int peopleCnt;
	inputStream >> ch1 >> height >> ch2 >> peopleCnt >> ch3;
	if (!inputStream)
	{
		return inputStream;
	}
	else if (ch1 != '(' ||
		     ch2 != ',' ||
			 ch3 != ')')
	{
		inputStream.clear(ios::failbit);
		return inputStream;
	}

	r.height = height;
	r.peopleCnt = peopleCnt;
	return inputStream;
}

void readData(BarGraph & bg)
{
	ifstream is(INPUT_TEXTFILE);
	Reading currentReading;
	
	while (is >> currentReading)
	{
		if (currentReading.height <= 0) error("Invalid height");
		if (currentReading.peopleCnt < 0) error("Invalid count of people");
		
		bg.addBar(to_string(currentReading.height), 
				  currentReading.peopleCnt);
	}
}

int main()
{
	using namespace Graph_lib;

	Point tl(100, 100);
	Simple_window window(tl, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	int axisHeight = 400;
	int notchesCnt = 20;
	int notchSize = axisHeight / notchesCnt;
	string axisLabel = "1 == ";
	axisLabel += to_string(notchSize);
	axisLabel += " people";

	Point orig(100, 500);

	Axis yAxis(Axis::y, 
			   Point(orig.x - AXIS_OFFSET, orig.y), 
			   axisHeight, 
			   notchesCnt,
			   axisLabel);	

	//window.attach(xAxis);
	window.attach(yAxis);
	
	BarGraph bg(axisHeight, axisHeight, orig);
	readData(bg);
	
	for (int i = 0; i < bg.getBarsCount(); ++i)
	{
		bg.set_fill_color(i, barColors[i % BAR_COLORS_CNT]);
	};
	
	window.attach(bg);
	window.wait_for_button();
}
