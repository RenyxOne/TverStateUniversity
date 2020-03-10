#include <iostream>
#include <vector>
#include "AEROFLOT.h"
#include "MyArr.h"


int main()
{
	//init
	//vector<AEROFLOT> list;
	MyArr<AEROFLOT> list;
	fstream file("text.txt",ios::in);
	file >> list;
	list.sortQsort(AEROFLOT::complex);
	//list.sortQsort(AEROFLOT::compDestination);
	cout << list;
	////Read file
	//while (!file.eof()) {
	//	AEROFLOT temp;
	//	file >> temp;
	//	list.push_back(temp);
	//}
	////file.close();

	////Sorting and output
	//qsort(&list.front(), list.size(), sizeof(AEROFLOT), AEROFLOT::comp); 
	//for (AEROFLOT i : list) {
	//	cout << i << endl;
	//	file << i << endl;
	//}
	//file.close();

	////Search
	//cout << endl << "input desistation for search" << endl;
	//string search;
	//cin >> search;
	//
	//bool flag = false;
	//for (AEROFLOT i : list)
	//	if (i == search) {
	//		cout << i; flag = true;
	//	}
	//if (!flag) cout << "Haven't flight to this desistation";
}