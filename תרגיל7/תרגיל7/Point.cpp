#include "Point.h"
istream& operator>>(istream& is, Point& p) {
	is >> p.x;
	is >> p.y;
    return is;
}