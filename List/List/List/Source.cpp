#include <iostream>
#include "List.h"

int main() {
	List<int> a;
	for (int i = 0; i < 6; i++) {
		a.push_back(rand()%10);
	}
	cout << "original list:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.insert_at_sort(4);
	a.insert_at_sort(4);
	a.insert_at_sort(4);
	cout << "3 time's insert 4 in sorted arr:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.insert(99, 1);
	cout << "insert 99 in 1 pos:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.DeDupe();
	cout << "after delete duplicates:\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.place_max_to_start_min_to_end();
	cout << "place max to start, min to end\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.insert(77, 3);
	cout <<"place 77 in 3 pos and search\n"<< a << "\nsize: " << a.get_size() << "\nsearch res: 77 in " << a.search(77) << " pos" << endl << endl;
	a.push_back(55);
	cout << "push back 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.push_front(55);
	cout << "push front 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.del(55);
	cout << "delete 55\n" << a << "\nsize: " << a.get_size() << endl << endl;
	a.insert_sort();
	cout << "after sort\n" << a << "\nsize: " << a.get_size() << endl << endl;
}