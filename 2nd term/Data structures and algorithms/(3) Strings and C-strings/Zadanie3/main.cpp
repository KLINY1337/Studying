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

	cout << "Лабораторная работа №3 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите, с чем хотите работать:\n1) Строка класса string C++\n2) Строка из библиотеки string.h языка C\n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 0);

	system("cls");

	string text, dict;
	char* textc = new char[200];
	char* dictc = new char[200];
	vector <Field> vec;
	switch (choice1) {

	case 1: {
		cout << "Введите текст:\n";
		cin.ignore(32767, '\n');
		getline(cin, text);

		cout << "Введите словарь(слова вводятся через пробел):\n";
		
		getline(cin, dict);

		nabor_slovo(text, dict, vec);
		cout << "Встретившиеся слова (слово : количество):\n";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].word2 << " : " << vec[i].amount << "\n";
		}
		break; }

	case 2: {
		cout << "Введите текст:\n";
		cin.ignore(32767, '\n');
		fgets(textc, 150, stdin);
		fflush(stdin);

		cout << "Введите словарь(слова вводятся через пробел):\n";

		fgets(dictc, 150, stdin);
		fflush(stdin);

		 nabor_slovo_с(textc, dictc, vec);
		 cout << "Встретившиеся слова (слово : количество):\n";
		 for (int i = 0; i < vec.size(); i++) {
			 cout << vec[i].word << " : " << vec[i].amount<<"\n";
		 }
		break; }

	case 0:
		return 0;
	}

	main();
}