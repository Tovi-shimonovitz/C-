#pragma once
#include <string>
using namespace std;
#include <iostream>

class Person
{
private:
    string name;
    int age;
public:
    Person() : name(""),age(0) {} 
    Person(string n,int age) : name(n) ,age(age){}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "name: "<< p.name << " age: "<< p.age;
        return os;                         
    }
};


