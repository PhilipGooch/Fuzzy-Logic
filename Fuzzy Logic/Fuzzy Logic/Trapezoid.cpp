#include "Trapezoid.h"

Trapezoid::Trapezoid(string name, float a, float b, float c, float d) : MembershipFunction(name, a, b, c, d)
{
	type = "trapezoid";
}

void Trapezoid::fuzzify(float x)
{
	if (x <= a || x >= d)
		fuzzified = 0;
	else if (x >= b && x <= c)
		fuzzified = 1;
	else if (x > a && x < b)
		fuzzified = (x - a) / (b - a);
	else if (x > c && x < d)
		fuzzified = (d - x) / (d - c);
}
