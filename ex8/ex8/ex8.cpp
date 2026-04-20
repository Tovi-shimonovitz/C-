using namespace std;
#include "Array.h"  
#include <iostream>
#include <string>
#include "Person.h"

int main()
{
    Array<int> a(5);
    for(int i = 0;i < 5; i++)
        a.insert(i * 10, i);

    a.print();
    Array <float> b(5);
    for(int i = 0;i < 5;i++)
        b.insert(i + 10 + 0.5, i);

    b.print();
    Array<Person> p(5);
    Person p1("Tovi", 20);
    Person p2("Rut", 12);
    Person p3("Tamar", 10);
    p.insert(p1, 1);
    p.insert(p2, 2);
    p.insert(p3, 3);

    p.print();



}

