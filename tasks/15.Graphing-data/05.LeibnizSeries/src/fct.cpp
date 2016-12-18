#include "fct.h"

void Func::BuildFunction()
{
	if (r2 < r1) error("Invalid range");
	if (count < 1) error("Invalid count");

	double step = (r2 - r1) / count;
	Point dest;
	int currentPoint;

	for (double currentX = r1; currentX <= r2; currentX += step)
	{
		dest = Point(orig.x + (currentX * xscale), 
				     orig.y - (f(currentX) * yscale));
		
		currentPoint = (currentX - r1) / step;
		if (currentPoint < Shape::number_of_points())
		{
			set_point(currentPoint, dest);
		}
		else
		{
			add(dest);
		}
	}

	while (currentPoint < Shape::number_of_points())
	{
		set_point(currentPoint, dest);
		++currentPoint;
	}
}

Func::Func(Graph_lib::Fct f, double r1, double r2, Point orig,
	int count, double xscale, double yscale)
{
	this->f = f;
	this->r1 = r1;
	this->r2 = r2;
	this->orig = orig;
	this->count = count;
	this->xscale = xscale;
	this->yscale = yscale;
	BuildFunction();
}
	
void Func::setF(Graph_lib::Fct f)
{
	this->f = f;
	this->BuildFunction();
}

void Func::setR1(double r1)
{
	this->r1 = r1;
	this->BuildFunction();
}

void Func::setR2(double r2)
{
	this->r2 = r2;
	this->BuildFunction();
}

void Func::setOrig(Point orig)
{
	this->orig = orig;
	this->BuildFunction();
}

void Func::setCount(int count)
{
	this->count = count;
	this->BuildFunction();
}

void Func::setXScale(double xscale)
{
	this->xscale = xscale;
	this->BuildFunction();
}

void Func::setYScale(double yscale)
{
	this->yscale = yscale;
	this->BuildFunction();
}
