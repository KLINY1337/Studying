#include <iostream>
#include <string>
#include "functions.h"
#include "random"
using namespace std;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №6 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите номер задания:\n1) Разработать рекурсивную функцию, которая реализует синтаксический анализатор для понятия идентификатор\n2) Сформировать новый список из значений узлов исходного, занеся в него значения в обратном порядке \n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 &&  choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2  && choice1 != 0);

	system("cls");

	switch (choice1) {

	case 1: {
		cout << "Введите строку, которую нужно проанализировать:\n";

		string s;
		cin.ignore(32767, '\n');
		getline(cin, s);
		
		if (is_identifier(s, 0)) cout << "Строка является идентификатором\n\n";
		else cout << "Строка не является идентификатором\n\n";
		break; }

	case 2: {
		list l, m;
		cout << "Введите длину генерируемого списка:\n";
		
		int list_len;
		cin >> list_len;

		l.generate(list_len);

		cout << "Сгенерированный список: ";
		l.print();
		cout << "\n";

		reverse2(l, list_len, m);

		cout << "Рекурсивно развернутый список: ";
		m.print();
		cout << "\n";

		break; }

	case 0:
		return 0;
	}
	main();
}