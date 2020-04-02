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
	void setDestinanion(const string& a);
	string getDestinanion();
	string getType();
	int getNum();
	bool operator > (const AEROFLOT& a);
	bool operator < (const AEROFLOT& a);
	bool operator == (const AEROFLOT& a);
	bool operator == (const string& a);
	static int compNum(const void* a, const void* b);
	static int compDestination(const void* a, const void* b);
	static int compType(const void* a, const void* b);

	static bool compDestinationUp (const void* a, const void* b);
	static bool compDestinationDown(const void* a, const void* b);

	static bool compNumUp(const void* a, const void* b);
	static bool compNumDown(const void* a, const void* b);

	static bool compTypeUp(const void* a, const void* b);
	static bool compTypeDown(const void* a, const void* b);

	void writeBin(fstream& file);
	void readBin(fstream& file);
	int getKey();

	static int complex(const void* a, const void* b);


	friend istream& operator >> (istream& is, AEROFLOT& a);
	friend ostream& operator << (ostream& os, const AEROFLOT& a);
};

