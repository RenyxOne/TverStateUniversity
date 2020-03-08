#pragma once
#include <string>
#include <fstream>
using namespace std;
class AEROFLOT
{
private:
	string Destination;
	int Num;
	string Type;
public:
	AEROFLOT();
	AEROFLOT(string d, int n, string t);
	AEROFLOT(const AEROFLOT& a);
	~AEROFLOT();

	AEROFLOT& operator = (const AEROFLOT& a);

	bool operator > (const AEROFLOT& a);
	bool operator < (const AEROFLOT& a);
	bool operator == (const AEROFLOT& a);
	bool operator == (const string& a);

	friend istream& operator >> (istream& is, AEROFLOT& a);
	friend ostream& operator << (ostream& os, const AEROFLOT& a);
	friend ostream& operator <= (ostream& os, const AEROFLOT& a);
};

