#include "analogClock_window.h"
#include <ctime>
#include <unistd.h>

#define CENTER_POINT (Point(x_max() / 2, y_max() / 2))
#define CLOCK_R (100)

using namespace Graph_lib;

Point calculateAngle(Point center, double radius, double coefficient)
{
	double angle = (M_PI/2) + (coefficient * 2 * M_PI);

	double dx = radius * cos(angle);
	double dy = radius * sin(angle);

	return Point(center.x - dx, center.y - dy);
}

Point getHoursPoint(Point center)
{
	time_t t;
	t = time(0);
	tm* ltm = localtime(&t);
	double hours = ltm->tm_hour % 12;

	return calculateAngle(center, CLOCK_R, (hours/12));
}

Point getMinutesPoint(Point center)
{
	time_t t;
	t = time(0);
	tm* ltm = localtime(&t);
	double minutes = ltm->tm_min;

	return calculateAngle(center, CLOCK_R, (minutes/60));
}

Point getSecondsPoint(Point center)
{
	time_t t;
	t = time(0);
	tm* ltm = localtime(&t);
	double seconds = ltm->tm_sec;

	return calculateAngle(center, CLOCK_R, (seconds/60));
}

AnalogClock_window::AnalogClock_window(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	  clock(CENTER_POINT, CLOCK_R + 10),
	  m(CENTER_POINT, 'X'),
	  quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
	this->initClock();

	attach(*hours_line);
	attach(*minutes_line);
	attach(*seconds_line);
	
	attach(clock);
	attach(m);
	attach(quit_button);

	Fl::add_timeout(1, cb_updateClock, this);
};

AnalogClock_window::~AnalogClock_window()
{
	this->destroyResources();
}

void AnalogClock_window::cb_updateClock(Address data)
{
	Graph_lib::reference_to<AnalogClock_window>(data).updateClock();
}

void AnalogClock_window::updateClock()
{
	this->destroyResources();
	this->initClock();
	Fl::redraw();
	Fl::add_timeout(1, cb_updateClock, this);
}

void AnalogClock_window::cb_quit(Graph_lib::Address callee, Graph_lib::Address pw)
{
	Graph_lib::reference_to<AnalogClock_window>(pw).quit();
}

void AnalogClock_window::quit()
{
	hide();
}

void AnalogClock_window::initClock()
{
	hours_line = new Line(CENTER_POINT, getHoursPoint(CENTER_POINT));
	minutes_line = new Line(CENTER_POINT, getMinutesPoint(CENTER_POINT));
	seconds_line = new Line(CENTER_POINT, getSecondsPoint(CENTER_POINT));
	
	hours_line->set_style(Line_style(Line_style::solid, 4));
	minutes_line->set_style(Line_style(Line_style::solid, 2));
	seconds_line->set_style(Line_style(Line_style::solid, 1));
}

void AnalogClock_window::destroyResources()
{
	delete this->hours_line;
	delete this->minutes_line;
	delete this->seconds_line;
}
