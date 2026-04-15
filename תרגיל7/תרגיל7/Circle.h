#pragma once
#include "Shape.h";
using namespace std;
class Circle:public Shape
{
private:
	float radius;
	static constexpr double PI = 3.14;
public:
	Circle(float r):Shape(1),radius(r) {}
	Circle(const Circle& other) : Shape(other), radius(other.radius) {}
	virtual double area() const override { return radius * radius * PI; }
	virtual void printSpecial() const override {}
	virtual  bool isSpecial() const override { return false; }
	};

