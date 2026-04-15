#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <cmath>

class Point

{
private:
	int x;
	int y;
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point() :x(0), y(0) {}
	Point(const Point& other)
		: x(other.x), y(other.y) {
	}
	int getX() const { return this->x; }
	int getY() const { return this->y; }

	double distance(const Point& other) const {
		int dx = this->x - other.x;
		int dy = this->y - other.y;
		return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
	}
	friend istream& operator>>(istream& is, Point& p);
};


