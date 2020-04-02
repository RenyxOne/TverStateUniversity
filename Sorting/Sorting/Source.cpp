#include <iostream>
#include <fstream>
#include "sorting.h"
#include "AEROFLOT.h"
#include "MyArr.h"
using namespace std;


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

	cout << "Hoar sort\n";
	Cpy.hoar_mysort(AEROFLOT::compDestination);
	cout << Cpy << endl;

	Cpy = A;

	cout << "Qsort\n";
	Cpy.sortQsort(AEROFLOT::complex);
	cout << Cpy << endl;
}