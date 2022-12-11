#include "functions.h"
#include "random"

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "������������ ������ �1 ����-13-21 ���������� �.�. ������� 23" << endl << endl;
	cout << "��������, � ��� ������ ��������:\n1) ����������� ������\n2) ������������ ������\n3) ������\n0) ��������� ���������\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

	system("cls");

	int mas[1000], len = 1;
	int* dynamic_mas = new int[len];
	vector <int> vec;

	switch (choice1) {

	case 1: {
		cout << "������� ���������� ��������� � ����������� �������: ";

		do {
			cin >> len;

			if (len >= 100) cout << "������� �������� ������ 100:\n";
		} while (len >= 100);

		initialize_array(mas, len);
		cout_array(mas, len);

		break; }

	case 2: {
		cout << "������� ���������� ��������� � ������������ �������: ";

		cin >> len;
		dynamic_mas = new int[len];
		initialize_array(dynamic_mas, len);
		cout_array(dynamic_mas, len);

		break; }

	case 3: {
		cout << "������� ���������� ��������� � �������: ";

		cin >> len;

		initialize_vector(vec, len);
		cout_vector(vec);

		break; }

	case 0:
		return 0;
	}

	cout << "�������� ����� �������:\n\n";
	cout << "1) ����������, ����������� �� �������� � �������(�������) �� �����������\n";
	cout << "2) ���� �������� � �������(�������) ����������� �� �����������, �� ������� �� �������(�������) ��������, ������� ������ ���������� ��������\n";
	cout << "3) ���� �������� � �������(�������) �� ����������� �� �����������, �� �������� ����� ������� � ������ ����� ������ ���������\n";
	cout << "0) ��������� ���������\n";

	int choice2;

	do {
		cin >> choice2;
		if (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 0);
	
	switch (choice2) {

	case 1: {
		if (choice1 == 1) {
			if (is_sorted(mas, len) == true) cout << "�������� ������� ����������� �� �����������\n";
			else cout << "�������� ������� �� ����������� �� �����������\n";
		}

		if (choice1 == 2) {
			if (is_sorted(dynamic_mas, len) == true) cout << "�������� ������� ����������� �� �����������\n";
			else cout << "�������� ������� �� ����������� �� �����������\n";
		}

		if (choice1 == 3) {
			if (is_sorted_vector(vec) == true) cout << "�������� ������� ����������� �� �����������\n";
			else cout << "�������� ������� �� ����������� �� �����������\n";
		}
		break; }

	case 2: {
		if (choice1 == 1) {
			int divider;

			cout << "������� �����, �������� ������� �������� ����� �������(���� ������ ������������): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "�� ���� ������ ������, ���������� ������ ��������\n";
			} while (divider == 0);

			delete_for_sorted(mas, len, divider);
			cout_array(mas, len);
		}

		if (choice1 == 2) {
			int divider;

			cout << "������� �����, �������� ������� �������� ����� �������(���� ������ ������������): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "�� ���� ������ ������, ���������� ������ ��������\n";
			} while (divider == 0);

			delete_for_sorted(dynamic_mas, len, divider);
			cout_array(dynamic_mas, len);
		}

		if (choice1 == 3) {
			int divider;

			cout << "������� �����, �������� ������� �������� ����� �������(���� ������ ������������): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "�� ���� ������ ������, ���������� ������ ��������\n";
			} while (divider == 0);

			delete_for_sorted_vector(vec, divider);
			cout_vector(vec);
		}
		break; }

	case 3: {
		if (choice1 == 1) {
			int paste_element;

			cout << "������� �����, ������� ������ �������� � ������ (���� �������� �������(�������) �� ����������� �� �����������): ";

			cin >> paste_element;

			add_for_unsorted(mas, len, paste_element);
			cout_array(mas, len);
		}

		if (choice1 == 2) {
			int paste_element;

			cout << "������� �����, ������� ������ �������� � ������ (���� �������� �������(�������) �� ����������� �� �����������): ";

			cin >> paste_element;

			add_for_unsorted(dynamic_mas, len, paste_element);
			cout_array(dynamic_mas, len);
		}

		if (choice1 == 3) {
			int paste_element;

			cout << "������� �����, ������� ������ �������� � ������ (���� �������� ������� �� ����������� �� �����������): ";

			cin >> paste_element;

			add_for_unsorted_vector(vec, paste_element);
			cout_vector(vec);
		}
		break; }

	case 0:
		return 0;
	}

	main();
}
