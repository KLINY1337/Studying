#include "functions1.h"
#include "functions2.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	cout << "������������ ������ �2 \"������� ��������� ������: ��������� � �������� ����\". ���������� ����\n";

	cout << "�������� ����� �������:\n1) ������� ��������� ����, ���������� ���������� �����.\n" <<
		"2) ����� ����������� ���������� �����.\n" <<
		"3) ���������� ����� ������ � ����� ���������� �����.\n" <<
		"4) ��������� �������� ����� �� ��� ����������� ������ � �����.\n" <<
		"5) ������� ����� ���� �� �������� ���������, ����������� � ��� �� ���� ��������� ������� �������� ��� ���������� ���� ��������: �� ������ ������ �������� �����, � �� ������ ������. � ������ ������ ������ ������� ���������� ����� � ������.\n" <<
		"6) ���������� ���������� ����� � �����.\n"<<
		"7) �������������� ���������� ����� � ��������.\n"
		"8) �������������� ��������� ����� � ���������.\n" <<
		"9) ����� ���� ������� ��������� �����.\n" <<
		"10) ������ � ������ ��������� ����� �� �� ������.\n" <<
		"11) �������� ������ � �������� ��������� �����.\n" <<
		"12) �������� ���� ���������� � ���������� � �������� ������� �� ����� ����.\n" <<
		"13) ������������ ������ ���� ����� ������, ��������� ��������� � �������� ����.\n" << 
		"0) ��������� ������ ���������.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 0 && choice1!=12 && choice1 != 13) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 0 && choice1 != 12 && choice1 != 13);

	system("cls");

	switch (choice1)
	{
	case 1: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		filePasteNumbers(file_name);
		cout << "���� ������� ������.";
		break;
	}
	case 2: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "\n���������� ���������� �����:\n\n";
			cout << fileOutput(file_name);
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 3: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			fileAppendString(file_name);
			cout << "������ ������� ��������� � �����.";
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 4: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;

		
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� ������ �������� ��������: ";
			int index;
			cin >> index;
			int res=fileReadNumber(file_name, index);
			cout << "����� � ��������� ��������: " << res;
		}
		else cout << "\n���������� ����� �� ����������.\n";
		
		break;
	}
	case 5: {
		cout << "������� �������� ������� �����: ";
		string file_name_1;
		cin >> file_name_1;
		if (fstream(file_name_1, ios::_Nocreate)) {
			cout << "������� �������� ������� �����: ";
			string file_name_2;
			cin >> file_name_2;
			fileAppendArrays(file_name_1, file_name_2);
		}
		break;
	}
	case 6: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "���������� ����� � �����: " << fileCountNumber(file_name);
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 7: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� �������� ��������� �����: ";
			string file_name_bin;
			cin >> file_name_bin;
			textToBin(file_name, file_name_bin);
			cout << "����������� ��������� �������.";
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 8: {
		cout << "������� �������� ��������� �����: ";
		string file_name_bin;
		cin >> file_name_bin;
		if (fstream(file_name_bin, ios::_Nocreate)) {
			cout << "������� �������� �����: ";
			string file_name;
			cin >> file_name;
			binToText(file_name, file_name_bin);
			cout << "����������� ��������� �������.";
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 9: {
		cout << "������� �������� �����: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "\n���������� ���������� �����:\n\n";
			fileOutputBin(file_name);
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 10: {
		cout << "������� �������� ��������� �����: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� ������ �������� ��������: ";
			int index;
			cin >> index;
			string res =fileGet(file_name, index)=="" ? "�� �������": fileGet(file_name, index);
			cout << "������ � ��������� ��������: " << res;
		}
		else cout << "\n���������� ����� �� ����������.\n";

		break;
	}
	case 11: {
		//void fileDelete(string file_name, int index);
		cout << "������� �������� ��������� �����: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� ������ ���������� ��������: ";
			int index;
			cin >> index;
			fileDelete(file_name, index);
			cout << "������ ������� �������.";
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 12: {
		//void switchTI(string file_name, string number, string date);
		cout << "������� �������� ��������� �����: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� ����� ������� ����������: ";
			string number;
			cin >> number;
			cout << "������� ���������� ����: ";
			string date;
			cin >> date;
			switchTI(file_name, number, date);
			cout << "���� ������� ��������.\n";
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 13: {
		cout << "������� �������� ��������� �����: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "������� ��� ����������: ";
			string car;
			cin >> car;
			cout << "������� ����: ";
			string date;
			cin >> date;
			cout << "�������������� ������:\n";
			checkCars(file_name, car, date);
		}
		else cout << "\n���������� ����� �� ����������.\n";
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";
	main();
}