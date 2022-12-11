#include "functions.h"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void bubble_sort(int* a, int len) {
	for (int i = 0; i < len; i++)
	{
		if (i % 1000 == 0) cout << i << " ";
		for (int j = 0; j < len - 1; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
	}
}

void count_sort(int* a, int len) {
	int maxi = a[0];

	for (int i = 1; i < len; i++)
		if (a[i] > maxi) maxi = a[i];

	int MAXIMUM = max(maxi, len);

	int* count = new int[MAXIMUM+1];
	int* output = new int[MAXIMUM+1];

	fill(count, count+MAXIMUM + 1, 0);

	for (int i = 0; i < len; i++)
		count[a[i]]++;

	for (int i = 1; i <= MAXIMUM; i++) 
		count[i] += count[i - 1];

	for (int i = len - 1; i >= 0; i--) {
		output[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < len; i++) {
		a[i] = output[i];
	}
}
	

int partition(int* a, int left, int right) // перемещение всех элементов меньше опорного влево
{
	int pivot = a[right]; // опорный элемент - последний
	int i = left;

	for (int j = left; j < right; j++) {
		if (a[j] < pivot) {
			swap (a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[right]);

	return i;
}

void quick_sort(int* a, int left, int right)
{
	if (left >= right)
		return;

	int i = partition(a, left, right);

	quick_sort(a, left, i - 1);
	quick_sort(a, i + 1, right);
}

void fill_arr(int* a, int len) {
	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}
}
void fill_random(int* a, int len) {
	for (int i = 0; i < len; i++) {
		a[i] = rand()%100;
	}
}
void print_array(int* a, int len) {
	for (int i = 0; i < len; i++) {
		cout << left << setw(3) << a[i];
	}
}

