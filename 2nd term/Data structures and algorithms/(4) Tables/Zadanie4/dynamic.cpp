#include "functions.h"
#include <iostream>
#include <iomanip>
using namespace std;

void paste_note_dyn(Sold_place** table, Sold_place Note, int& len1, int& len2) {
	Sold_place** copy;

	copy = new Sold_place * [2];
	copy[0] = new Sold_place[len1];
	copy[1] = new Sold_place[len2];

	if (Note.hall == 1) {
		for (int k = 0; k < len1; k++) {
			copy[0][k] = table[0][k];
		}
		len1++;
		
		table[0] = new Sold_place[len1];
		for (int k = 0; k < len1-1; k++) {
			table[0][k] = copy[0][k];
		}
		for (int i = len1 - 2; i >= 0; i--)
			table[0][i + 1] = table[0][i];
		table[0][0] = Note;
	}

	else if (Note.hall == 2) {
		for (int k = 0; k < len2; k++) {
			copy[1][k] = table[1][k];
		}
		len2++;
		
		table[1] = new Sold_place[len2];
		for (int k = 0; k < len2-1; k++) {
			table[1][k] = copy[1][k];
		}
		for (int i = len2 - 2; i >= 0; i--)
			table[1][i + 1] = table[1][i];
		table[1][0] = Note;
	}

}

void delete_note_by_date_dyn(Sold_place** table, int& len1, int& len2, string date) {
	Sold_place** copy;

	copy = new Sold_place* [2];
	copy[0] = new Sold_place[len1];
	copy[1] = new Sold_place[len2];

	for (int i = 0; i < len1; i++) {
		if (table[0][i].date == date) {
			for (int j = i; j < len1 - 1; j++)
				table[0][j] = table[0][j + 1];
			len1--;
			copy[0] = new Sold_place[len1];
			for (int k = 0; k < len1; k++) {
				copy[0][k] = table[0][k];
			}
			table[0] = new Sold_place[len1];
			for (int k = 0; k < len1; k++) {
				table[0][k] = copy[0][k];
			}
			i--;
		}
	}

	for (int i = 0; i < len2; i++) {
		if (table[1][i].date == date) {
			for (int j = i; j < len2 - 1; j++)
				table[1][j] = table[1][j + 1];
			len2--;
			copy[1] = new Sold_place[len2];
			for (int k = 0; k < len2; k++) {
				copy[1][k] = table[1][k];
			}
			table[1] = new Sold_place[len2];
			for (int k = 0; k < len2; k++) {
				table[1][k] = copy[1][k];
			}
			i--;
		}
	}
}

void check_free_places_dyn(Sold_place** table, int& len1, int& len2, string name, string date, string time) {
	int taken1 = 0, taken2 = 0;

	for (int i = 0; i < len1; i++) {
		if (table[0][i].name == name && table[0][i].date == date && table[0][i].time == time) taken1++;
	}

	for (int i = 0; i < len2; i++) {
		if (table[1][i].name == name && table[1][i].date == date && table[1][i].time == time) taken2++;
	}

	cout << "Количество свободных мест на указанный фильм в указанную дату и время в малом зале: " << 100 - taken1 << "\n";
	cout << "Количество свободных мест на указанный фильм в указанную дату и время в большом зале: " << 100 - taken2 << "\n";
}

void print_table_dyn(Sold_place** table, int& len1, int& len2) {
	cout << "Малый зал:\n";
	cout << left << setw(22) << "Название фильма" << " |";
	cout << left << setw(11) << "Дата" << " |";
	cout << left << setw(6) << "Время" << " |";
	cout << left << setw(4) << "Ряд" << " |";
	cout << left << setw(6) << "Место" << " |";
	cout << left << setw(10) << "Номер зала" << " |";
	cout << "\n----------------------------------------------------------------------\n";
	for (int i = 0; i < len1; i++) {
		if (table[0][i].name != "") {
			cout << left << setw(22) << table[0][i].name << " |";
			cout << left << setw(11) << table[0][i].date << " |";
			cout << left << setw(6) << table[0][i].time << " |";
			cout << left << setw(4) << table[0][i].line << " |";
			cout << left << setw(6) << table[0][i].place << " |";
			cout << left << setw(10) << table[0][i].hall << " |";
			cout << "\n";
		}
	}

	cout << "\n\nБольшой зал:\n";
	cout << left << setw(22) << "Название фильма" << " |";
	cout << left << setw(11) << "Дата" << " |";
	cout << left << setw(6) << "Время" << " |";
	cout << left << setw(4) << "Ряд" << " |";
	cout << left << setw(6) << "Место" << " |";
	cout << left << setw(10) << "Номер зала" << " |";
	cout << "\n----------------------------------------------------------------------\n";
	for (int i = 0; i < len2; i++) {
		if (table[1][i].name != "") {
			cout << left << setw(22) << table[1][i].name << " |";
			cout << left << setw(11) << table[1][i].date << " |";
			cout << left << setw(6) << table[1][i].time << " |";
			cout << left << setw(4) << table[1][i].line << " |";
			cout << left << setw(6) << table[1][i].place << " |";
			cout << left << setw(10) << table[1][i].hall << " |";
			cout << "\n";
		}
	}
}