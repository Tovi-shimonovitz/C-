#pragma once
#include "Employee.h"
#include <string>
using namespace std;

class PartTime : public Employee
{
private:
	int hoursOfWork;
	float payPerHour;
public:
	PartTime(string name, int id, int seniority, int hoursOfWork, float payPerHour)
		: Employee(name, id, seniority), hoursOfWork(hoursOfWork), payPerHour(payPerHour)
	{
		setPay(salary());
	}

	PartTime() : Employee(), hoursOfWork(0), payPerHour(0) {}

	float salary() { return hoursOfWork * payPerHour; }

	int getHoursOfWork() const { return hoursOfWork; }
	float getPayPerHour() const { return payPerHour; }

	void setHoursOfWork(int hours) { hoursOfWork = hours; setPay(salary()); }
	void setPayPerHour(float rate) { payPerHour = rate; setPay(salary()); }
	PartTime(const PartTime& other) : Employee(other), hoursOfWork(other.hoursOfWork), payPerHour(other.payPerHour)
	{
		setPay(salary());
	}
	friend istream& operator>>(istream& is, PartTime& p)
	{
		cout << "Enter employee details:" << endl;

		is >> (Employee&)p;

		cout << "Enter hours worked in the month: ";
		is >> p.hoursOfWork;

		cout << "Enter pay per hour: ";
		is >> p.payPerHour;
		p.setPay(p.salary());

		return is;
	}

	friend ostream& operator<<(ostream& os, const PartTime& p)
	{
		os << "Employee: " << p.getName() << "\n";
		os << "Employee ID: " << p.getId() << "\n";
		os << "Years Seniority: " << p.getSeniority() << "\n";
		os << "Hours: " << p.hoursOfWork << "\n";
		os << "Salary per Month: " << p.getPay() << "\n";

		return os;
	}
};

