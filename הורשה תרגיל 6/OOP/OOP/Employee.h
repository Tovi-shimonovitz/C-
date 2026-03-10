#pragma once
#include <string>
#include <iostream>

using namespace std;
class Employee
{
private:
	string name;
	int id;
	int seniority;
	float pay;
public:
	Employee(string name, int id, int seniority)
		: name(name), id(id), seniority(seniority), pay(0) {
	}
	Employee() :name(""), id(0), seniority(0), pay(0) {}
	Employee(const Employee& other)
		: name(other.name), id(other.id), seniority(other.seniority), pay(other.pay) {
	}
	string getName() const { return this->name; }
	int getId() const { return this->id; }
	int getSeniority() const { return this->seniority; }
	float getPay() const { return this->pay; }
	void setName(string name) { this->name = name; }
	void setId(int id) { this->id = id; }
	void setSenirity(int seniority) { this->seniority = seniority; }
	void setPay(float pay) { this->pay = pay; }
	void salaryAfterBonus() {
		if (this->seniority <= 5) {
			this->pay += 500;
		}
		else
			this->pay *= 1.25;
	}
	
	friend istream& operator>>(istream& is, Employee& e)
	{
		cout << "Enter employee details:" << endl;

		is >> e.name >> e.id >> e.seniority >> e.pay;

		return is;
	}
	friend ostream& operator << (ostream& os, Employee& e) 
	{
		os << "Employee: " << e.getName() << "\nEmployee ID: " << e.getId()  << "\nYears Seniority: " << e.getSeniority() ;
		return os;
	}
};





