#include <iostream>
#include <vector>
#include "AEROFLOT.h"
#include "conio.h"

int comp(const void* a, const void* b)
{
	AEROFLOT A = *((AEROFLOT*)a);
	AEROFLOT B = *((AEROFLOT*)b);
	if (A < B)
		return -1;
	if (A == B)
		return 0;
	return 1;
}

int main()
{
	//init
	vector<AEROFLOT> list;
	fstream file("text.txt");

	//Read file
	while (!file.eof()) {
		AEROFLOT temp;
		file >> temp;
		list.push_back(temp);
	}
	//file.close();

	//Sorting and output
	qsort(&list.front(), list.size(), sizeof(AEROFLOT), comp); 
	for (AEROFLOT i : list) {
		cout << i << endl;
		file << i << endl;
	}
	file.close();

	//Search
	cout << endl << "input desistation for search" << endl;
	string search;
	cin >> search;
	
	bool flag = false;
	for (AEROFLOT i : list)
		if (i == search) {
			cout <= i; flag = true;
		}
	if (!flag) cout << "Haven't flight to this desistation";
}