#include "AEROFLOT.h"

AEROFLOT::AEROFLOT()
{
	Num = NULL;
}

AEROFLOT::AEROFLOT(string d, int n, string t)
{
	Destination = d; Num = n; Type = t;
}

AEROFLOT::AEROFLOT(const AEROFLOT& a)
{
	Destination = a.Destination;
	Num = a.Num;
	Type = a.Type;
}

AEROFLOT::~AEROFLOT()
{
	Destination.clear();
	Num = NULL;
	Type.clear();
}

AEROFLOT& AEROFLOT::operator=(const AEROFLOT& a)
{
	Destination = a.Destination;
	Num = a.Num;
	Type = a.Type;
	return *this;
}


bool AEROFLOT::operator>(const AEROFLOT& a)
{
	return Num > a.Num;
}

bool AEROFLOT::operator<(const AEROFLOT& a)
{
	return Num < a.Num;
}

bool AEROFLOT::operator==(const AEROFLOT& a)
{
	return Num == a.Num;
}

bool AEROFLOT::operator==(const string& a)
{
	return Destination == a;
}

istream& operator >>(istream& is, AEROFLOT& a)
{
	return is >> a.Destination >> a.Num >> a.Type;
}

ostream& operator<<(ostream& os, const AEROFLOT& a)
{
	return os << a.Destination << '\t' << a.Num << '\t' << a.Type;
}

ostream& operator<=(ostream & os, const AEROFLOT & a)
{
	return os << a.Num << '\t' << a.Type << endl;
}
