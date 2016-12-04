#ifndef POINT_UTILS_H
#define POINT_UTILS_H

#include "Graph.h"

Point n(Graph_lib::Rectangle& rect);
Point s(Graph_lib::Rectangle& rect);
Point e(Graph_lib::Rectangle& rect);
Point w(Graph_lib::Rectangle& rect);
Point center(Graph_lib::Rectangle& rect);
Point ne(Graph_lib::Rectangle& rect);
Point se(Graph_lib::Rectangle& rect);
Point sw(Graph_lib::Rectangle& rect);
Point nw(Graph_lib::Rectangle& rect);

#endif
