#pragma once
using namespace std;
#include "Shape.h";
#include "Point.h";
class Triangle:public Shape
{
public:
	Triangle() :Shape(3){}
	virtual bool isSpecial() const override
	{
		if (this->points[1].distance(this->points[2]) == this->points[2].distance(this->points[0])
			&& this->points[1].distance(this->points[0]) == this->points[1].distance(this->points[2])
			)
			return true;
		return false;
	}
	virtual void printSpecial() const override{
		if(this->isSpecial())
		    cout << "An equilateral triangle with a side length: " << this->points[0].distance(this->points[1]);
	}
	virtual double area()const override{
		double a = points[0].distance(points[1]);
		double b = points[1].distance(points[2]);
		double c = points[2].distance(points[0]);

		double s = (a + b + c) / 2.0;

		double result = std::sqrt(s * (s - a) * (s - b) * (s - c));

		return result;
	}
};

