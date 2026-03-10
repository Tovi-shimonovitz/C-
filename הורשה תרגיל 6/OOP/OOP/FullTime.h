#pragma once
using namespace std;
#include <string>
#include <iostream>
#include "Employee.h"
class FullTime:public Employee
{
private:
	float salaryPerYear;
public:
	FullTime (string name, int id, int seniority, float salaryPerYear):Employee(name, id, seniority)
	{
		this->salaryPerYear = salaryPerYear;
		this->setPay(salary());
	}
	FullTime () :Employee(), salaryPerYear(0) {}
	FullTime (const FullTime& other):Employee(other),salaryPerYear(other.salaryPerYear){}
	float getSalaryPerYear() const { return salaryPerYear; }

	void setSalaryPerYear(float salaryPerYear)
	{
		this->salaryPerYear = salaryPerYear;
		setPay(salary());
	}
	float salary() { return salaryPerYear / 12; }
	friend istream& operator>>(istream& is, FullTime& f)
	{
		cout << "Enter fullTime employee details:" << endl;

		string name;
		int id;
		int seniority;

		is >> name >> id >> seniority >> f.salaryPerYear;

		f.setName(name);
		f.setId(id);
		f.setSenirity(seniority);

		f.setPay(f.salary());

		return is;
	}
	friend ostream& operator << (ostream& os, FullTime& f)
	{
		os << (Employee&)f;
		os << "\nSalary per Month : " << f.salary();
		return os;
	}
};

