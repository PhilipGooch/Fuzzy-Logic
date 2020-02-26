#pragma once
#include <string>

class MembershipFunction
{
public:

	MembershipFunction();
	MembershipFunction(std::string name, float a, float b);
	MembershipFunction(std::string name, float a, float b, float c);
	MembershipFunction(std::string name, float a, float b, float c, float d);

	std::string name;

	std::string type;

	float a, b, c, d;

	float fuzzified;

	virtual void fuzzify(float inputValue) {};

	// for output membership function.
	// the degree at which the the membership function is true after rules have been applied.
	float degree;
};

