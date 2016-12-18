#ifndef IMMOBILE_CIRCLE
#define IMMOBILE_CIRCLE

class Immobile_Circle : public Circle
{
public:
	Immobile_Circle(Point c, int radius)
		: Circle(c, radius) {};

private:
	void move(int dx, int dy) {}; // delete virtual function	
};

#endif // IMMOBILE_CIRCLE
