
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h";
#include <iostream>
enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE=4 };
int main() {
	Point p;

	int numShapes, choice;
	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;
	Shape** shapes = new Shape * [numShapes];
	for (int i = 0; i < numShapes; i++) {
		cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
		cin >> choice;
		switch (choice) {
		case CIRCLE:
			int radius;
			cout << "Enter radius :\n";
			cin >> radius;
			shapes[i] = new Circle(radius);
			break;
		case TRIANGLE:
			cout << "Enter 3 points :\n";
			shapes[i] = new Triangle();
			break;
		case RECTANGLE:
			cout << "Enter 4 points :\n";
			shapes[i] = new Rectangle();
			break;
		default:
			cout << "invalid input\n";
			i--;
		}

	}

	for (int i = 0; i < numShapes; i++) {
		double sArea = shapes[i]->area();
		cout << *shapes[i] << "Area: " << sArea << endl;
		shapes[i]->printSpecial();
		
	}

}




