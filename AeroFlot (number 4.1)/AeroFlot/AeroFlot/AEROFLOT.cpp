#include "AEROFLOT.h"

AEROFLOT::AEROFLOT()
{
	Destination = "";
	Num = 0;
	Type = "";
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
	Num = 0;
	Type.clear();
}

AEROFLOT& AEROFLOT::operator=(const AEROFLOT& a)
{
	Destination = a.Destination;
	Num = a.Num;
	Type = a.Type;
	return *this;
}

void AEROFLOT::setDestinanion(const string& a)
{
	Destination = a;
}

string AEROFLOT::getDestinanion()
{
	return Destination;
}

string AEROFLOT::getType()
{
	return Type;
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
 int  AEROFLOT::compNum(const void* a, const void* b)
{
	AEROFLOT A = *((AEROFLOT*)a);
	AEROFLOT B = *((AEROFLOT*)b);
	if (A < B)
		return -1;
	if (A == B)
		return 0;
	return 1;
}
 int  AEROFLOT::compDestination(const void* a, const void* b)
 {
	 AEROFLOT* A = ((AEROFLOT*)a);
	 AEROFLOT* B = ((AEROFLOT*)b);
	 return A->getDestinanion().compare(B->getDestinanion());
 }
 int AEROFLOT::compType(const void* a, const void* b)
 {
	 AEROFLOT* A = ((AEROFLOT*)a);
	 AEROFLOT* B = ((AEROFLOT*)b);
	 return A->getType().compare(B->getType());
 }
 bool AEROFLOT::compDestinationUp(AEROFLOT& a, AEROFLOT& b)
 {
	 return a.getDestinanion().compare(b.getDestinanion())>0;
 }
 bool AEROFLOT::compDestinationDown(AEROFLOT& a, AEROFLOT& b)
 {
	 return a.getDestinanion().compare(b.getDestinanion()) < 0;
 }
 bool AEROFLOT::compNumUp(AEROFLOT& a, AEROFLOT& b)
 {
	 return a > b;
 }
 bool AEROFLOT::compNumDown(AEROFLOT& a, AEROFLOT& b)
 {
	 return a < b;
 }
 void AEROFLOT::writeBin(fstream& file)
 {
	 file.write((char*)this, sizeof(*this));
 }
 void AEROFLOT::readBin(fstream& file)
 {
	 file.read((char*)this, sizeof(*this));
 }
 int AEROFLOT::getKey()
 {
	 return Num;
 }
 int AEROFLOT::complex(const void* a, const void* b)
 {
	 if (!compDestination(a, b))
		 if (!compNum(a, b))
			 return compType(a, b);
		 else return compNum(a, b);
	 else return(compDestination(a, b));
 }
ostream& operator<<(ostream& os, const AEROFLOT& a)
{
	return os << a.Destination << '\t' << a.Num << '\t' << a.Type;
}
