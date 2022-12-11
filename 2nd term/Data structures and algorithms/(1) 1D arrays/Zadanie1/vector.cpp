#include <iostream>
#include <vector>
#include "random"
using namespace std;

void initialize_vector(vector <int> &vecInt, int len) {
	int choice;

	do {
		cout << "������� ������ ���������� �������:\n1) �������\n2) ���������� �������\n";
		cin >> choice;
		if (choice != 1 && choice != 2) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice != 1 && choice != 2);

	switch (choice) {

	case 1:
		for (int i = 0; i < len; i++) {
			int digit;
			cout << "������� " << i + 1 << "-� ������� �������: ";
			cin >> digit;
			vecInt.push_back(digit);
		}
		break;

	case 2:
		for (int i = 0; i < len; i++) {
			int digit;
			digit = rand() % 100 + 1;
			vecInt.push_back(digit);
		}
		break;
	}
}
void cout_vector(vector <int>& vecInt) {
	cout << "������: ";

	for (int i = 0; i < vecInt.size(); i++)
		cout << vecInt[i] << " ";

	cout << endl;
}

bool is_sorted_vector(vector <int> &vecInt)
{
	for (int i = 0; i < vecInt.size() - 1; i++)
		if (vecInt[i] > vecInt[i + 1]) return false;

	return true;
}

void delete_for_sorted_vector(vector <int> &vecInt, int divider) {
	if (is_sorted_vector(vecInt) == true) {
		for (int i = 0; i < vecInt.size(); i++)
			if (vecInt[i] % divider == 0) {vecInt.erase(vecInt.begin() + i); i--;}
	}
}

void add_for_unsorted_vector(vector <int> &vecInt, int paste_element) {
	if (is_sorted_vector(vecInt) == false) {
		vecInt.insert(vecInt.begin(), paste_element);
	}
}
