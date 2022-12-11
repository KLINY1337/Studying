#include <iostream>
#include "Task.h"
#include <windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");

	cout << "������������ ������ �8 \"��������������� ��������� ��� ������ ���������� ����������. ������� � ������ ��� ����������\". ���������� ����\n";

	cout << "�������� ����� �������:\n" <<
		"1) ������ � ������� (� ������, ���� � ��������)\n" <<
		"0) ��������� ������ ���������\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 0);

	system("cls");
	switch (choice1)
	{
	case 1: {
		cout << "������� ������ ��������: ";
		int size;
		cin >> size;
		cout << "\n������� ������ ��������:\n";
		int* fat = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> fat[i];
		}
		cout << "\n������� ������ �������:\n";
		int* calories = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> calories[i];
		}
		cout << "\n������� ������������ ����� �������: ";
		int maxCalories;
		cin >> maxCalories;

		BackpackProblem obj(calories, fat, maxCalories, size);
		tuple<int, int, vector<pair<int, int>>> answer = obj.solve();

		cout << "��������� ��������: " << get<0>(answer) << "; ��������� �������: " << get<1>(answer)<<".\n";
		cout << "���� ������� ����������� (��������, ������������, ����� � �������):\n";

		for (int i = 0; i < get<2>(answer).size(); i++) {
			cout << get<2>(answer)[i].first << " " << get<2>(answer)[i].second << " ("<<i+1<<")\n";
		}

		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}