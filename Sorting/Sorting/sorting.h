#pragma once

template <class T>
void insert_sort(T* arr, int n) {
	for (int i = 1; i < n; i++) {
		T help = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > help){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = help;
	}
}

template <class T>
void select_sort(T* arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++)
			if (arr[j] < arr[min]) min = j;
		T help = arr[i];
		arr[i] = arr[min];
		arr[min] = help;
	}
}

template <class T>
void bubble_sort(T* arr, int n) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				flag = true;
				T help = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = help;
			}
		}
	}
}

template <class T>
void shell_sort(T* arr, int n) {
	for (int step = n / 2; step > 0; step /= 2)
		for (int now = step; now < n; now++)
			for (int s = now - step; s >= 0 && arr[s] > arr[s + step]; s -= step) {
				T help = arr[s];
				arr[s] = arr[s + step];
				arr[s + step] = help;
			}
}

template <class T>
void hoar_sort(T* arr, int right, int left = 0, bool start = true) {
	if (start) right -= 1; 
	int mid = (left + right) / 2;
	int l = left; int r = right;
	while (l < r) {
		while (arr[l] < arr[mid]) l++;
		while (arr[r] > arr[mid]) r--;
		if (l < r) {
			T help = arr[l];
			arr[l] = arr[r];
			arr[r] = help;
		}
	}
	if (left < l) 
		hoar_sort(arr, l, left, false);
	if (right < r)
		hoar_sort(arr, right, r, false);
}