#pragma once;
using namespace std;
#include "Point.h"
#include <iostream>


class Shape
{
protected:
	int numOfPoints;
	Point* points;
public:

	Shape() : numOfPoints(0), points(nullptr) {}

	// 2. Constructor - בנאי המקבל את מספר הנקודות וקולט ערכים
	Shape(int num) : numOfPoints(num) {
		if (numOfPoints > 0) {
			points = new Point[numOfPoints];

			std::cout << "Enter values of " << numOfPoints << " points:" << std::endl;
			for (int i = 0; i < numOfPoints; ++i) {

				std::cin >> points[i];
			}
		}
		else {
			points = nullptr;
		}
	}

	Shape(const Shape& other) : numOfPoints(other.numOfPoints) {
		if (other.points != nullptr) {
			points = new Point[numOfPoints];
			for (int i = 0; i < numOfPoints; ++i) {
				points[i] = other.points[i];
			}
		}
		else {
			points = nullptr;
		}
	}
	// Move Constructor
	Shape(Shape&& other) noexcept {

		this->numOfPoints = other.numOfPoints;
		this->points = other.points;


		other.points = nullptr;
		other.numOfPoints = 0;
	}
	virtual ~Shape() {
		if (points != nullptr) {
			delete[] points;
		}
	}
	friend ostream& operator<<(ostream& os, const Shape& s);
	virtual double area() const = 0;
	virtual bool isSpecial() const = 0;
	virtual void printSpecial() const = 0;
};

