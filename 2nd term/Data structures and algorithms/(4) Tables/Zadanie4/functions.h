#pragma once
#include <string>
#include <vector>
using namespace std;

struct Sold_place {
	string name;
	string date;
	string time;
	int line;
	int place;
	int hall;
};

const int Num = 2;
const int N = 100;

Sold_place fill_note(Sold_place); // static.cpp (работает для всех)

void paste_note(Sold_place(*table)[N], Sold_place Note, int& len1, int& len2); // static.cpp
void delete_note_by_date(Sold_place(*table)[N], int& len1, int& len2, string date); // static.cpp
void check_free_places(Sold_place(*table)[N], int& len1, int& len2, string name, string date, string time); // static.cpp
void print_table(Sold_place(*table)[N], int& len1, int& len2); // static.cpp

void paste_note_dyn(Sold_place** table, Sold_place Note, int& len1, int& len2); // dynamic.cpp
void delete_note_by_date_dyn(Sold_place** table, int& len1, int& len2, string date); // dynamic.cpp
void check_free_places_dyn(Sold_place** table, int& len1, int& len2, string name, string date, string time); // dynamic.cpp
void print_table_dyn(Sold_place** table, int& len1, int& len2); // dynamic.cpp

void paste_note_vec(vector< vector<Sold_place> >& vec, Sold_place Note); // vector.cpp
void delete_note_by_date_vec(vector< vector<Sold_place> >& vec, string date); // vector.cpp
void check_free_places_vec(vector< vector<Sold_place> >& vec, string name, string date, string time); // vector.cpp
void print_table_vec(vector< vector<Sold_place> >& vec); // vector.cpp