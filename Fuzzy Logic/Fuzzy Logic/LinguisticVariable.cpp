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

float LinguisticVariable::defuzzify()
{
	float maxima = 0;

	MembershipFunction* maxMembershipFunction = nullptr;

	std::map<std::string, MembershipFunction*>::iterator it;
	for (it = membershipFunctions.begin(); it != membershipFunctions.end(); it++)
	{
		if (maxMembershipFunction == nullptr)
		{
			maxMembershipFunction = it->second;
		}
		else if (it->second->degree > maxMembershipFunction->degree)
		{
			maxMembershipFunction = it->second;
		}
	}

	float a = maxMembershipFunction->a;
	float b = maxMembershipFunction->b;
	float c = maxMembershipFunction->c;
	float d = maxMembershipFunction->d;
	float degree = maxMembershipFunction->degree;

	float difference = b - a;
	b = a + difference * degree;

	difference = d - c;
	c += difference * degree;

	float average = b + (c - b) / 2;

	return average;


	//float maxima = 0;

	//std::map<std::string, MembershipFunction*>::iterator it;
	//for (it = membershipFunctions.begin(); it != membershipFunctions.end(); it++)
	//{
	//	MembershipFunction* membershipFunction = it->second;

	//	// what happens when trying to find the mean of max for grade membership functions where they go on for infinity?
	//	// do you just design output membership functions to not have them?
	//	// only trapezoids?
	//	// just use singleton output membership functions?
	//	// (just constant numbers that get multiplied by the degree to which the membership function is true)
	//	if (membershipFunction->type == "grade" ||
	//		membershipFunction->type == "reverse grade")
	//	{
	//		cout << "Invalid output membership function." << endl;
	//		assert(false);
	//	}

	//	float a = membershipFunction->a;
	//	float b = membershipFunction->b;
	//	float c = membershipFunction->c;
	//	float d = membershipFunction->d;
	//	float degree = membershipFunction->degree;

	//	float difference = b - a;
	//	b = a + difference * degree;

	//	difference = d - c;
	//	c += difference * degree;

	//	float average = b + (c - b) / 2;

	//	maxima += average;
	//}

	//float meanOfMaxima = maxima / membershipFunctions.size();

	//return meanOfMaxima;
}

