#ifndef FCT_H
#define FCT_H

#include "Graph.h"

struct Func : public Graph_lib::Shape 
{
public:
	Func(Graph_lib::Fct f, double r1, double r2, Point orig,
        int count = 100, double xscale = 25, double yscale = 25);    

	void setF(Graph_lib::Fct f);
	void setR1(double r1);
	void setR2(double r2);
	void setOrig(Point orig);
	void setCount(int count);
	void setXScale(double xscale);
	void setYScale(double yscale);
private:
	Graph_lib::Fct * f;
	double r1;
	double r2;
	Point orig;
	int count;
	double xscale;
	double yscale;
	void BuildFunction();
};

#endif // FCT_H
