#pragma once
#include <string>
#include <vector>
#include <map>
#include "MembershipFunction.h"
#include "Grade.h"
#include "ReverseGrade.h"
#include "Triangle.h"
#include "Trapezoid.h"

#include <cassert>
#include <iostream>

using namespace std;

class LinguisticVariable
{
public:

	LinguisticVariable() {}
	LinguisticVariable(std::string name);

	void addGradeMF(std::string name, float a, float b);
	void addReverseGradeMF(std::string name, float a, float b);
	void addTriangleMF(std::string name, float a, float b, float c);
	void addTrapezoidMF(std::string name, float a, float b, float c, float d);

	std::map<std::string, MembershipFunction*> membershipFunctions;

	std::string name;

	void fuzzify(float inputValue);

	void truncate()
	{
		std::map<std::string, MembershipFunction*>::iterator it;
		for (it = membershipFunctions.begin(); it != membershipFunctions.end(); it++)
		{
			MembershipFunction* membershipFunction = it->second;

			// what happens when trying to find the mean of max for grade membership functions where they go on for infinity?
			// do you just design output membership functions to not have them?
			// only trapezoids?
			// just use singleton output membership functions?
			// (just constant numbers that get multiplied by the degree to which the membership function is true)
			if (membershipFunction->type == "grade" ||
				membershipFunction->type == "grade")
			{
				cout << "Invalid output membership function." << endl;
				assert(false);
			}

			float a = membershipFunction->a;
			float b = membershipFunction->b;
			float c = membershipFunction->c;
			float d = membershipFunction->d;
			float degree = membershipFunction->degree;

			float difference = b - a;
			b = a + difference * degree;

			difference = d - c;
			c += difference * degree;
		}
	}
};

