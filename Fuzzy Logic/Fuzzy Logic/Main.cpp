#pragma once

#include "Application.h"

#include <string>
using namespace std;

class Employee {
public:
    virtual void raiseSalary()
    {
        /* common raise salary code */
        cout << "employee raiseSalary" << endl;
    }

    virtual void promote()
    {
        cout << "employee promote" << endl;
        /* common promote code */
    }
};

class Manager : public Employee {
    virtual void raiseSalary()
    {
        cout << "manager raiseSalary" << endl;
        /* Manager specific raise salary code, may contain
          increment of manager specific incentives*/
    }

    virtual void promote()
    {
        cout << "manager promote" << endl;
        /* Manager specific promote */
    }
};

// Similarly, there may be other types of employees 

// We need a very simple function 
// to increment the salary of all employees 
// Note that emp[] is an array of pointers 
// and actual pointed objects can 
// be any type of employees. 
// This function should ideally 
// be in a class like Organization, 
// we have made it global to keep things simple 
void globalRaiseSalary(Employee* emp[], int n)
{
    for (int i = 0; i < n; i++)

        // Polymorphic Call: Calls raiseSalary() 
        // according to the actual object, not 
        // according to the type of pointer 
        emp[i]->raiseSalary();
}


void main()
{
   /* Employee* employees[2] = { new Employee, new Manager };


    globalRaiseSalary(employees, 2);

    cin.get();

	return;*/

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fuzzy Logic");
	window.setPosition(sf::Vector2i(100, 90));
	window.setFramerateLimit(60);

	Application application(&window);
	
}

