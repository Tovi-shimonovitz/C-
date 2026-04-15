#include "Shape.h"

ostream& operator<<(ostream& os, const Shape& s) {
	os << "points:" << endl;
	for (int i = 0; i < s.numOfPoints; ++i) {

		os << "(" << s.points[i].getX() << "," << s.points[i].getY() << ")";
		if (i < s.numOfPoints - 1) {
			os << " ";
		}
	}

	return os;
}
