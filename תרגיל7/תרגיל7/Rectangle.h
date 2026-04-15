#pragma once
#include "Shape.h";
using namespace std;
class Rectangle: public Shape
{
public:
	Rectangle() :Shape(4) {}
	virtual bool isSpecial() const override {
		if (points[0].distance(points[1]) == points[1].distance(points[2]) &&
			points[1].distance(points[2]) == points[2].distance(points[3]) &&
			points[2].distance(points[3]) == points[3].distance(points[0]))
			return true;
		return false;
	}
	virtual void  printSpecial() const override {
		if (this->isSpecial())
			cout << "Square with side length" << points[0].distance(points[1]);
	}
	virtual double area() const override {
		return points[0].distance(points[1]) * points[1].distance(points[2]);
	}
};

