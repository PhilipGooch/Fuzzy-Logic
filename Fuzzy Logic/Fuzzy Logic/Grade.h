#pragma once
#include <string>
#include "MembershipFunction.h"

using namespace std;

class Grade : public MembershipFunction
{
public:

	Grade(string name, float a, float b);

	virtual void fuzzify(float x);

};

