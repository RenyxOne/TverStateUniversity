#pragma once
template <class T>
void BubbleSort1(T* a, int n, bool (*comp)(T&, T&)) {
	int flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; i++)
			if (comp(a[i] , a[i + 1])) {
				flag = true;
				T help = a[i];
				a[i] = a[i + 1];
				a[i + 1] = help;
			}
	}
}