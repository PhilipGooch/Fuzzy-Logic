#include "LinguisticVariable.h"

LinguisticVariable::LinguisticVariable(std::string name) :
	name(name)
{

}

void LinguisticVariable::addGradeMF(std::string name, float a, float b)
{
	membershipFunctions.emplace(name, new Grade(name, a, b));
}

void LinguisticVariable::addReverseGradeMF(std::string name, float a, float b)
{
	membershipFunctions.emplace(name, new ReverseGrade(name, a, b));
}

void LinguisticVariable::addTriangleMF(std::string name, float a, float b, float c)
{
	membershipFunctions.emplace(name, new Triangle(name, a, b, c));
}

void LinguisticVariable::addTrapezoidMF(std::string name, float a, float b, float c, float d)
{
	membershipFunctions.emplace(name, new Trapezoid(name, a, b, c, d));
}

void LinguisticVariable::fuzzify(float inputValue)
{
	std::map<std::string, MembershipFunction*>::iterator it;
	for (it = membershipFunctions.begin(); it != membershipFunctions.end(); it++)
	{
		it->second->fuzzify(inputValue);
	}
}

