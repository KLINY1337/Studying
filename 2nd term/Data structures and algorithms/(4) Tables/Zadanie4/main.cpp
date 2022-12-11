#include "functions.h"
#include <iostream>
using namespace std;

int main(){
setlocale(LC_ALL, "");

cout << "Лабораторная работа №3 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
cout << "Выберите, с чем хотите работать:\n1) Статический массив\n2) Динамический массив\n3) Вектор\n0) Закончить программу\n";

int choice1;

do {
	cin >> choice1;

	if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

system("cls");

Sold_place table[Num][N];
int len1_static = 0;
int len2_static = 0;

Sold_place** table_dyn;
int len1_dyn = 1;
int len2_dyn = 1;
table_dyn = new Sold_place* [2];
table_dyn[0] = new Sold_place[len1_dyn];
table_dyn[1] = new Sold_place[len2_dyn];

vector < vector <Sold_place> > vec;
vec.push_back(vector<Sold_place>());
vec.push_back(vector<Sold_place>());

switch (choice1) {

case 1: {

	cout << "Текущие таблицы:\n\n";
	print_table(table, len1_static, len2_static);
	cout << "\n";
	break; }

case 2: {
	cout << "Текущие таблицы:\n\n";
	print_table_dyn(table_dyn, len1_dyn, len2_dyn);
	cout << "\n";
	break; }

case 3: {
	cout << "Текущие таблицы:\n\n";
	print_table_vec(vec);
	cout << "\n";
	break; }

case 0:
	return 0;
}
while (true) {
	cout << "Выберите действие:\n\n";
	//cout << "1) Заполнение записи по одному проданному билету с клавиатуры\n";
	cout << "1) Вставить запись в таблицу, упорядочивая по номеру зала. Новая запись вставляется в начало подсписка по залу\n";
	cout << "2) Удалить записи по заданной дате\n";
	cout << "3) Определить количество свободных мест на заданный фильм в указанную дату и время\n";
	cout << "4) Вывести таблицы\n";
	cout << "0) Закончить программу\n";

	int choice2;

	do {
		cin >> choice2;
		if (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2!=4  && choice2 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 0);

	switch (choice2) {

	case 1: {
		system("cls");
		if (choice1 == 1) {
			Sold_place Note, Note2;
			Note2 = fill_note(Note);
			paste_note(table, Note2, len1_static, len2_static);
		}

		if (choice1 == 2) {
			Sold_place Note, Note2;
			Note2 = fill_note(Note);
			paste_note_dyn(table_dyn, Note2, len1_dyn, len2_dyn);
		}

		if (choice1 == 3) {
			Sold_place Note, Note2;
			Note2 = fill_note(Note);
			paste_note_vec(vec, Note2);
		}
		break; }

	case 2: {
		system("cls");
		if (choice1 == 1) {
			string date;
			cout << "Введите нужную дату (ДД.ММ.ГГГГ):\n";
			cin >> date;
			delete_note_by_date(table, len1_static, len2_static, date);
			cout << "Записи по выбранной дате удалены\n\n";
		}

		if (choice1 == 2) {
			string date;
			cout << "Введите нужную дату (ДД.ММ.ГГГГ):\n";
			cin >> date;
			delete_note_by_date_dyn(table_dyn, len1_dyn, len2_dyn, date);
			cout << "Записи по выбранной дате удалены\n\n";
		}

		if (choice1 == 3) {
			string date;
			cout << "Введите нужную дату (ДД.ММ.ГГГГ):\n";
			cin >> date;
			delete_note_by_date_vec(vec, date);
			cout << "Записи по выбранной дате удалены\n\n";
		}
		break; }

	case 3: {
		system("cls");
		if (choice1 == 1) {
			string name, date, time;
			cin.ignore(32767, '\n');
			cout << "Введите название фильма:\n";
			getline(cin, name);

			cout << "Введите дату (ДД.ММ.ГГГГ):\n";
			getline(cin, date);

			cout << "Введите время (ЧЧ:ММ):\n";
			getline(cin, time);

			check_free_places(table, len1_static, len2_static, name, date, time);
		}

		if (choice1 == 2) {
			string name, date, time;
			cin.ignore(32767, '\n');
			cout << "Введите название фильма:\n";
			getline(cin, name);

			cout << "Введите дату (ДД.ММ.ГГГГ):\n";
			getline(cin, date);

			cout << "Введите время (ЧЧ:ММ):\n";
			getline(cin, time);

			check_free_places_dyn(table_dyn, len1_dyn, len2_dyn, name, date, time);
		}

		if (choice1 == 3) {
			string name, date, time;
			cin.ignore(32767, '\n');
			cout << "Введите название фильма:\n";
			getline(cin, name);

			cout << "Введите дату (ДД.ММ.ГГГГ):\n";
			getline(cin, date);

			cout << "Введите время (ЧЧ:ММ):\n";
			getline(cin, time);

			check_free_places_vec(vec, name, date, time);
		}
		break; }

	case 4: {
		system("cls");
		if (choice1 == 1) {
			cout << "\n";
			print_table(table, len1_static, len2_static);
		}

		if (choice1 == 2) {
			cout << "\n";
			print_table_dyn(table_dyn, len1_dyn, len2_dyn);
		}

		if (choice1 == 3) {
			cout << "\n";
			print_table_vec(vec);
		}
		break; }
	case 0:
		return 0;
	}
}
main();
}