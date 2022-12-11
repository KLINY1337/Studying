#include "functions1.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Функция конвертации текстового файла в бинарный
void textToBin(string file_name_txt, string file_name_bin) {
	fstream fin = fstream(file_name_txt, ios::in);
	fstream fout = fstream(file_name_bin, ios::binary | ios::out);
	if (fin.is_open() && fout.is_open()) {

		fout << fin.rdbuf();

		if (fin.eof())
			fin.close();
		if (fout.fail() != ios::failbit)
			fout.close();
	}
}
//Функция конвертации бинарного файла в текстовый
void binToText(string file_name_txt, string file_name_bin) {
	fstream fin = fstream(file_name_bin, ios::binary | ios::in);
	fstream fout = fstream(file_name_txt, ios::binary | ios::out);
	if (fin.is_open() && fout.is_open()) {

		fout << fin.rdbuf();

		if (fin.eof())
			fin.close();
		if (fout.fail() != ios::failbit)
			fout.close();
	}
}
//Функция вывода содержимого бинарного файла
void fileOutputBin(string file_name) {
	fstream fin(file_name, ios::binary | ios::in);
	
	if (fin.is_open()) cout << fin.rdbuf();


	if (fin.eof())
		fin.close();	
}
//Функция получения записи по ее индексу
string fileGet(string file_name, int index) {
	ifstream fin(file_name, ios::in | ios::binary);
	string line = "";
	string str = "";
	if (fin.is_open()) {
		ifstream fin2(file_name, ios::in | ios::binary);
		while (fin2) {
			str += fin2.get();
		}
		fin2.close();
		
		if (index * 37 <= str.size() + 10) {
			fin.seekg(index * 37 * sizeof(char));
			getline(fin, line);
		}
	}
	if (fin.fail() != ios::failbit)
		fin.close();
	return line;
 }
//Функция удаления записи по ее индексу
void fileDelete(string file_name, int index) {
	string str = fileOutput(file_name);
	string strToCopy="";
	for (int i = str.rfind("\n") + 1; i < str.length(); i++) {
		strToCopy += str[i];
	}
	for (int i = index * 37; i < index * 37 + strToCopy.length(); i++) {
		str[i] = strToCopy[i - index * 37];
	}
	
	str[index * 37+1] = index + '0';

	str=str.erase(str.rfind("\n"), strToCopy.length());
	fileInput(file_name, str);
}
//Функция замены даты техосмотра
 void switchTI(string file_name, string number, string date){
	fstream fin(file_name, ios::in | ios::binary | ios::out);
	string num, mark, color, fam, no, data;
	string hash;
	string index="-1";
	while (fin) {
		fin >> hash;
		fin >> num;
		fin >> mark;
		fin >> color;
		fin >> fam;
		fin >> no;
		fin >> data;
		if (number == num) { index = hash; break; }
	}
	if (index != "-1") {
		fin.seekp(atoi(index.c_str()) * 37);
		data = date;
		fin << hash << " ";
		fin << num << " ";
		fin << mark << " ";
		fin << color << " ";
		fin << fam << " ";
		fin << no << " ";
		fin << data;
	}
	if (fin.fail() != ios::failbit) 
		fin.close();
}
//Функция вывода списка автомобилей определенной марки с определенной
//датой техосмотра
void checkCars(string file_name, string car, string date){
	fstream fin(file_name, ios::in | ios::binary);
	string num, mark, color, fam, no, data;
	string hash;
	while (!fin.eof()) {
		fin >> hash;
		fin >> num;
		fin >> mark;
		fin >> color;
		fin >> fam;
		fin >> no;
		fin >> data;
		if (car == mark && date == data) 
			cout << hash << " " << num << " " << mark << " " << color << " " << fam << " " << no << " " << data<<"\n";
	}
	if (fin.fail() != ios::failbit)
		fin.close();
}
