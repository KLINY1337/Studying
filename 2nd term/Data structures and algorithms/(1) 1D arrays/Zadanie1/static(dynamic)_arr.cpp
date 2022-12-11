#include <iostream>
#include "random"
using namespace std;

void initialize_array(int* arr, int len) {
	int choice;

	cout << "Введите способ заполнения массива:\n1) Вручную\n2) Случайными числами\n";

	do {
		
		cin >> choice;

		if (choice != 1 && choice != 2) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice != 1 && choice != 2);

	switch (choice) {

	case 1:
		for (int i = 0; i < len; i++) {
			cout << "Введите " << i + 1 << "-й элемент массива: ";

			cin >> arr[i];
		}
		break;

	case 2:
		for (int i = 0; i < len; i++)
			arr[i] = rand() % 100 + 1;
		break;
	}
}

void cout_array(int* arr, int len) {
	cout << "Массив: ";

	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";

	cout << endl;
}


bool is_sorted(int *arr, int len) {
	for (int i = 0; i < len-1; i++)
		if (arr[i] > arr[i + 1]) return false;

	return true;
}

void delete_for_sorted(int* arr, int &len, int divider) {
	if (is_sorted(arr, len) == true) {
		for (int i = 0; i < len; i++) {
			if (arr[i] % divider == 0) {for (int j = i; j < len - 1; j++) arr[j] = arr[j + 1];
			len--; i--;
			}
		}
	}
}

void add_for_unsorted(int* arr, int& len, int paste_element) {
	if (is_sorted(arr, len) == false) {
		len++;

		for (int i = len - 1; i >= 0; i--)
			arr[i + 1] = arr[i];

		arr[0] = paste_element;

	}
}