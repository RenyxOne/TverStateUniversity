#include <iostream>
#include "AEROFLOT.h"
#include "MyArr.h"

int F(int a) {
	return a % 100;
}

template<class T>
void createHash(MyArr<T>& arr, int n, int (*F)(int a), int** Hash) {
	for (int i = 0; i < n; i++) {
		int k = arr[i].getKey();
		int k1 = F(k);
		int ai = 0;
		while (Hash[k1 + ai*ai][0] != -1) {
			ai++;
		}
		Hash[k1+ai*ai][0] = k;
		Hash[k1+ai*ai][1] = i;
	}
}

int _find(int** Hash, int key, int (*F)(int a)) {
	int ai = 0;
	int k1 = F(key);
	while (Hash[k1 + ai * ai][0] != key) {
		ai++;
	}
	return Hash[k1][1];
}

int main()
{
	//init
	ofstream out1("AEROFLOT.bin", ios::binary);
	out1.close();
	fstream out("AEROFLOT.bin", ios::out | ios::in | ios::binary | ios::ate);
	MyArr<AEROFLOT> list;
	fstream file("text.txt",ios::in);
	file >> list;
	file.close();
	//list.sortQsort(AEROFLOT::complex);
	//cout << list;

	for (int i = 0; i < list.getSize(); i++) {
		list[i].writeBin(out);
	}
	int** Hash;
	int M = list.getSize() * 5;
	Hash = new int* [M];
	for (int i = 0; i < M; i++) {
		Hash[i] = new int[2];
		Hash[i][0] = -1;
		Hash[i][1] = -1;
	}

	createHash(list, list.getSize(), F, Hash);

	int k = _find(Hash, 15, F);
	
	out.seekg(k * sizeof(AEROFLOT));

	AEROFLOT help;
	help.readBin(out);
	//out.read((char*)&help, sizeof(help));
	
	cout << help;

	//////Sorting and output
	////qsort(&list.front(), list.size(), sizeof(AEROFLOT), AEROFLOT::comp); 
	////for (AEROFLOT i : list) {
	////	cout << i << endl;
	////	file << i << endl;
	////}
	////file.close();

	//////Search
	////cout << endl << "input desistation for search" << endl;
	////string search;
	////cin >> search;
	////
	////bool flag = false;
	////for (AEROFLOT i : list)
	////	if (i == search) {
	////		cout << i; flag = true;
	////	}
	////if (!flag) cout << "Haven't flight to this desistation";
	//in.close();
	return 0;
}