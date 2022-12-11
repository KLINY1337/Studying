#include <iostream>
#include "functions.h"
#include "random"
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №5 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	
	cout << "Введите количество элементов в списке L:\n";
	int len1;
	cin >> len1;

	cout << "\nВведите количество элементов в списке M:\n";
	int len2;
	cin >> len2;

	list l, m;

	cout << "\nСгенерированный список L: ";
	l.generate(len1);
	l.print();
	cout << "\n";

	cout << "\nСгенерированный список M: ";
	m.generate(len2);
	m.print();
	cout << "\n";

	cout << "Выберите задание:\n1) Создать и вывести список LM\n2) Удалить из списка M последние (длина списка M - длина списка L) элементов\n0) Закончить программу\n";
	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 0);

	system("cls");

	switch (choice1) {

	case 1: {
		cout << "Сгенерированный список LM:\n";
		list2 lm;
		lm.match(l, m);
		lm.print();
		cout << "\n";
		break; }

	case 2: {
		cout << "Список M без удаленных элементов: ";
		delete_M(l, m);
		m.print();
		cout << "\n\n";
		break; }

	case 0:
		return 0;
	}
	main();
}