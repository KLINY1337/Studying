#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "functions.h"
using namespace std;

int main()
{
	
	setlocale(LC_ALL, "");

	cout << "������������ ������ �3 ����-13-21 ���������� �.�. ������� 23" << endl << endl;
	cout << "��������, � ��� ������ ��������:\n1) ������ ������ string C++\n2) ������ �� ���������� string.h ����� C\n0) ��������� ���������\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 0);

	system("cls");

	string text, dict;
	char* textc = new char[200];
	char* dictc = new char[200];
	vector <Field> vec;
	switch (choice1) {

	case 1: {
		cout << "������� �����:\n";
		cin.ignore(32767, '\n');
		getline(cin, text);

		cout << "������� �������(����� �������� ����� ������):\n";
		
		getline(cin, dict);

		nabor_slovo(text, dict, vec);
		cout << "������������� ����� (����� : ����������):\n";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].word2 << " : " << vec[i].amount << "\n";
		}
		break; }

	case 2: {
		cout << "������� �����:\n";
		cin.ignore(32767, '\n');
		fgets(textc, 150, stdin);
		fflush(stdin);

		cout << "������� �������(����� �������� ����� ������):\n";

		fgets(dictc, 150, stdin);
		fflush(stdin);

		 nabor_slovo_�(textc, dictc, vec);
		 cout << "������������� ����� (����� : ����������):\n";
		 for (int i = 0; i < vec.size(); i++) {
			 cout << vec[i].word << " : " << vec[i].amount<<"\n";
		 }
		break; }

	case 0:
		return 0;
	}

	main();
}