#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Array
{
private:
	T* arr;
	int size;
public:
	Array(int s) : size(s) {
		arr = new T[size]();
	}
	~Array() {
		delete[] arr;
	}
	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return arr[index];
	}
	/*const T& operator[](int index) const {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return arr[index];
	}*/
	void insert( const T& value,int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Insert index out of bounds");
		}
		arr[index] = value; 
	}
	void print() const {
		for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
		}
		cout << endl;
	}
};

