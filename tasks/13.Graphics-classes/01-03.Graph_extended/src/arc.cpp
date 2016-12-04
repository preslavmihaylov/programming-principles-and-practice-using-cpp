#include "arc.h"

void Arc::draw_lines() const 
{
	fl_arc(x, y, w * 2, h * 2, sa, ea);
}
