#include "functions.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void paste_note_vec(vector< vector<Sold_place> >& table, Sold_place Note) {
	if (Note.hall == 1 ) table[0].insert(table[0].begin(), Note);

	else if (Note.hall == 2) table[1].insert(table[1].begin(), Note);
}

void delete_note_by_date_vec(vector< vector<Sold_place> >& table, string date) {

	for (int i = 0; i < table[0].size(); i++)
		if (table[0][i].date == date) table[0].erase(table[0].begin() + i);

	for (int i = 0; i < table[1].size(); i++)
		if (table[1][i].date == date) table[1].erase(table[1].begin() + i);
}

void check_free_places_vec(vector< vector<Sold_place> >& table, string name, string date, string time) {
	int taken1 = 0, taken2 = 0;

	for (int i = 0; i < table[0].size(); i++) {
		if (table[0][i].name == name && table[0][i].date == date && table[0][i].time == time) taken1++;
	}

	for (int i = 0; i < table[1].size(); i++) {
		if (table[1][i].name == name && table[1][i].date == date && table[1][i].time == time) taken2++;
	}

	cout << "Количество свободных мест на указанный фильм в указанную дату и время в малом зале: " << 100 - taken1 << "\n";
	cout << "Количество свободных мест на указанный фильм в указанную дату и время в большом зале: " << 100 - taken2 << "\n";
}

void print_table_vec(vector< vector<Sold_place> >& table) {
	cout << "Малый зал:\n";
	cout << left << setw(22) << "Название фильма" << " |";
	cout << left << setw(11) << "Дата" << " |";
	cout << left << setw(6) << "Время" << " |";
	cout << left << setw(4) << "Ряд" << " |";
	cout << left << setw(6) << "Место" << " |";
	cout << left << setw(10) << "Номер зала" << " |";
	cout << "\n----------------------------------------------------------------------\n";
	for (int i = 0; i < table[0].size(); i++) {
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
	for (int i = 0; i < table[1].size(); i++) {
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