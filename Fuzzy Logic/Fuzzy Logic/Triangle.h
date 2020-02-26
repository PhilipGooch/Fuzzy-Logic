#pragma once
#include <string>
#include "MembershipFunction.h"

using namespace std;

class Triangle : public MembershipFunction
{
public:

	Triangle(string name, float a, float b, float c);

	void fuzzify(float x);

};

