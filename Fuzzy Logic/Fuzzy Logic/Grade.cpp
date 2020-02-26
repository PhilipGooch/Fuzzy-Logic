#include "Grade.h"
#include "Trapezoid.h"

Grade::Grade(string name, float a, float b) : MembershipFunction(name, a, b)
{
	type = "grade";
}

void Grade::fuzzify(float x)
{
	if (x <= a)
		fuzzified = 0;
	else if (x >= b)
		fuzzified = 1;
	else if (x > a && x < b)
		fuzzified = (x - a) / (b - a);
}
