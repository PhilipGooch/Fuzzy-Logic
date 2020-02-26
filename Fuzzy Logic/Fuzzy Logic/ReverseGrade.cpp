#include "ReverseGrade.h"

ReverseGrade::ReverseGrade(string name, float a, float b) : MembershipFunction(name, a, b)
{
	type = "reverse grade";
}

void ReverseGrade::fuzzify(float x)
{
	if (x <= a)
		fuzzified = 1;
	else if (x >= b)
		fuzzified = 0;
	else if (x > a&& x < b)
		fuzzified = (b - x) / (b - a);
}
