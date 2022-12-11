#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №7 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите номер задания:\n1) Посчитать значение префиксного выражения\n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 0);

	system("cls");

	switch (choice1) {

	case 1: {
		cout << "Введите выражение в префиксной форме: ";
		string expression;
		cin.ignore(32767, '\n');
		getline(cin, expression);
		cout << "Значение выражения: " << solve_prefix(expression)<<"\n\n";
		break; }

	case 0:
		return 0;
	}
	main();
}