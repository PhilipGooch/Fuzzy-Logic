#pragma once
#include <string>
#include "MembershipFunction.h"

using namespace std;

class Trapezoid : public MembershipFunction
{
public:

	Trapezoid(string name, float a, float b, float c, float d);

	void fuzzify(float x);

};

