#include <iostream>
#include "AEROFLOT.h"
#include "List.h"

bool intcomp(int &a, int &b) {
	return a > b;
}
int main() {
	//List<int> a;
	//for (int i = 0; i < 6; i++) {
	//	a.push_back(rand()%10+3);
	//}
	//cout << "original list:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.insert_at_sort(4, intcomp);
	//a.insert_at_sort(4, intcomp);

	//cout << "3 time's insert 4 in sorted arr:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.insert(99, 1);
	//cout << "insert 99 in 1 pos:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.insert(77, 3);
	//cout <<"place 77 in 3 pos and search\n"<< a << "\nsize: " << a.get_size() << "\nsearch res: 77 in " << a.search(77) << " pos" << endl << endl;
	//a.push_back(55);
	//cout << "push back 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.push_front(55);
	//cout << "push front 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.del(55);
	//cout << "delete 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	//a.insertion_sort(intcomp);
	//cout << "after sort\n" << a << "\nsize: " << a.get_size() << endl << endl;

	fstream aeroflot_text("text.txt", ios::in);
	List<AEROFLOT> aeroList;

	int list_size = 0;
	aeroflot_text >> list_size;
	for (int i = 0; i < list_size; i++) {
		aeroflot_text >> aeroList;
	}

	AEROFLOT help("Moskow", 55, "Boening");
	cout << "Original list\n" << aeroList << "Size: " << aeroList.get_size() <<endl << endl;
	aeroList.insertion_sort(AEROFLOT::compNumUp);
	cout << "Sorted list\n" << aeroList << "Size: " << aeroList.get_size() << endl << endl;
	aeroList.insert_at_sort(help, AEROFLOT::compNumUp);
	aeroList.insert_at_sort(help, AEROFLOT::compNumUp);
	aeroList.insert_at_sort(help, AEROFLOT::compNumUp);
	cout << "insert 3 time's\n" << help << "\nat sorted list\n" << aeroList << "Size: " << aeroList.get_size() << endl << endl;
	cout << "search\n" << help << "in " << aeroList.search(help) << " pos\n";
	aeroList.push_back(help);
	cout << "push back\n" << help << "\n\n" << aeroList << "Size: " << aeroList.get_size() << endl << endl; 
	aeroList.push_front(help);
	cout << "push front\n" << help << "\n\n" << aeroList << "Size: " << aeroList.get_size() << endl << endl;
	aeroList.del(help);
	cout << "delete \n" << help << endl << endl << aeroList << "Size: " << aeroList.get_size() << endl << endl;
}