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

	float defuzzify();
	
};

