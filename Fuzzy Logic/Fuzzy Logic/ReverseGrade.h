#pragma once
#include <string>
#include "MembershipFunction.h"

using namespace std;

class ReverseGrade : public MembershipFunction
{
public:

	ReverseGrade(string name, float a, float b);

	void fuzzify(float x);

};

