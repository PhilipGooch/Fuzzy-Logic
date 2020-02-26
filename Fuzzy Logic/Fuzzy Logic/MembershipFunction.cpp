#include "MembershipFunction.h"

MembershipFunction::MembershipFunction()
{
}

MembershipFunction::MembershipFunction(std::string name, float a, float b) :
	name(name),
	a(a),
	b(b)
{
}

MembershipFunction::MembershipFunction(std::string name, float a, float b, float c) :
	name(name),
	a(a),
	b(b),
	c(c)
{
}

MembershipFunction::MembershipFunction(std::string name, float a, float b, float c, float d) :
	name(name),
	a(a),
	b(b),
	c(c),
	d(d)
{

}




