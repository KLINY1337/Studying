#include <iostream>

#include "functions.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "������������ ������ �1 \"����������� �������� � �� ����������\". ���������� ����\n";

	cout << "�������� ����� �������:\n1) ���������� 1-�, 6-�, 9-� ���� � �������� 1.\n" <<
		"2) �������� 1-�, 6-�, 9-� ����.\n" <<
		"3) �������� ��������, ��������� �������������, �� 8.\n" <<
		"4) ��������� ��������, ��������� �������������, �� 8.\n" <<
		"5) ���������� n-�� ��� �����, ��������� �������������, � �������� 1, ��������� ����� 1.\n" <<
		"0) ��������� ������ ���������.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);

	system("cls");

	switch (choice1)
	{
	case 1: {
		unsigned short int num;
		cout << "������� ���������� ����� (�� 0000 �� FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\n�������� ������ ��������� �����: ";
		cout_bin(num);
		num = set_bits_1_6_9(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\n���������� �����: " << num << endl;
		cout << "�������� ������ ����������� �����: ";
		cout_bin(num);
		break;
	}
	case 2: {
		unsigned short int num;
		cout << "������� ���������� ����� (�� 0000 �� FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\n�������� ������ ��������� �����: ";
		cout_bin(num);
		num = null_bits_1_6_9(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\n���������� �����: " << num << endl;
		cout << "�������� ������ ����������� �����: ";
		cout_bin(num);
		break;
	}
	case 3: {
		unsigned short int num;
		cout << "������� ���������� ����� (�� 0000 �� FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\n�������� ������ ��������� �����: ";
		cout_bin(num);
		num = multiply_by_8(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\n���������� �����: " << num << endl;
		cout << "�������� ������ ����������� �����: ";
		cout_bin(num);
		break;
	}
	case 4: {
		unsigned short int num;
		cout << "������� ������� ����� ����� (�� 0000 �� FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\n�������� ������ ��������� �����: ";
		cout_bin(num);
		num = divide_by_8(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\n���������� �����: " << num << endl;
		cout << "�������� ������ ����������� �����: ";
		cout_bin(num);
		break;
	}
	case 5: {
		unsigned short int num;
		int n;
		cout << "������� ���������� ����� (�� 0000 �� FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\n�������� ������ ��������� �����: ";
		cout_bin(num);
		cout << "\n������� ����� ����������� ���� (�� 0 �� 15): ";
		cin.unsetf(ios::hex);
		cin.setf(ios::dec);
		cin >> n;
		num = set_n_bit(num,n);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\n���������� �����: " << num << endl;
		cout << "�������� ������ ����������� �����: ";
		cout_bin(num);
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";
	main();
}