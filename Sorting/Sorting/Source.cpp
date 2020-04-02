#include <iostream>
#include <fstream>
#include "sorting.h"
#include "AEROFLOT.h"
#include "MyArr.h"
using namespace std;

int comp(const void* a, const void* b) {
	int A = *((int*)a);
	int B = *((int*)b);
	return A - B;
}


int main() {
	fstream in("text.txt", ios::in);
	MyArr<AEROFLOT> A;
	in >> A;

	cout << "Original arr\n";
	cout << A << endl;
	
	MyArr<AEROFLOT> Cpy(A);

	cout << "Insert sort\n";
	Cpy.insert_mysort(AEROFLOT::compNumUp);
	cout << Cpy << endl;

	Cpy = A;

	cout << "Select sort\n";
	Cpy.select_mysort(AEROFLOT::compNumDown);
	cout << Cpy << endl;

	Cpy = A;

	cout << "Bubble sort\n";
	Cpy.bubble_mysort(AEROFLOT::compTypeUp);
	cout << Cpy << endl;

	Cpy = A;

	cout << "Shell sort\n";
	Cpy.shell_mysort(AEROFLOT::compTypeDown);
	cout << Cpy << endl;

	Cpy = A;

	/*cout << "Hoar sort\n";
	Cpy.hoar_mysort(AEROFLOT::compDestination);
	cout << Cpy << endl;*/

	Cpy = A;

	cout << "Qsort\n";
	Cpy.sortQsort(AEROFLOT::complex);
	cout << Cpy << endl;

	MyArr<int> i(5);
	
	i[0] = 1;
	i[1] = 3;
	i[2] = 2;
	i[3] = 2;
	i[4] = 5;
	i.hoar_mysort(comp);
	cout << i;
}