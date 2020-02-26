#include "Triangle.h"

Triangle::Triangle(string name, float a, float b, float c) : MembershipFunction(name, a, b, c)
{
	type = "triangle";
}

void Triangle::fuzzify(float x)
{
	if (x <= a || x >= c)
		fuzzified = 0;
	else if (x == b)
		fuzzified = 1;
	else if (x > a && x < b)
		fuzzified = (x - a) / (b - a);
	else if (x > b && x < c)
		fuzzified = (c - x) / (c - b);
}
