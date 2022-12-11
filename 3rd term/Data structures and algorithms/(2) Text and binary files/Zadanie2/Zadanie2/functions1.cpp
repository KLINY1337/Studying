#include <iostream>
#include <fstream>
#include <string>
#include "random"
using namespace std;

//Функция записи в файл
void fileInput(string file_name, string data) {
	ofstream fout;
	fout.open(file_name);

	if (fout.is_open()) {
		if (fout.good()) fout << data;
	}

	if (fout.good()) fout.close();
}
//Функция дозаписи в конец файла
void fileAppend(string file_name, string data) {
	ofstream fout;
	fout.open(file_name, ios::app);

	if (fout.is_open()) {
		if (fout.good())
			fout << data;
	}

	if (fout.good()) fout.close();
}
//Функция чтения файла
string fileOutput(string file_name) {
	ifstream fin;
	fin.open(file_name);
	char chr;
	string res = "";
	if (fin.is_open()) {
		while (fin.get(chr) && fin.good()) {
			res+=chr;
		}
	}

	if (fin.eof())
		fin.close();

	return res;
}
//Функция заполнения файла десятичными числами
void filePasteNumbers(string file_name){
	int strNumber = rand() % 11+1;
	string finalStr = "";

	for (int i = 0; i < strNumber; i++) {
		int digitsNumber = rand() % 11 + 1;
		for (int j = 0; j < digitsNumber; j++) {
			finalStr += to_string(rand() % 90+10);
			if (j != digitsNumber - 1) finalStr += " ";
		}
		if (i != strNumber - 1) finalStr += "\n";
	}
	fileInput(file_name, finalStr);

}
//Функция добавления строки в файл
void fileAppendString(string file_name){
	string finalStr = "";
	int digitsNumber = rand() % 11 + 1;
	for (int j = 0; j < digitsNumber; j++) {
		finalStr += to_string(rand() % 90 + 10);
		if (j != digitsNumber - 1) finalStr += " ";
	}
	finalStr = "\n" + finalStr;
	
	fileAppend(file_name, finalStr);
}

//Функция чтения числа по его индексу
int fileReadNumber(string file_name, int index){
	
	string finalStr=fileOutput(file_name);

	for (int i = 0; i < finalStr.length(); i++) {
		if (finalStr[i] == '\n') finalStr[i] = ' ';
	}

	string res = "";
	res += finalStr[3 * (index - 1)];
	res += finalStr[3 * (index - 1)+1];
	int num = atoi(res.c_str());

	return num;
}
//Функция подсчета количества чисел
int fileCountNumber(string file_name){

	string finalStr = fileOutput(file_name);

	for (int i = 0; i < finalStr.length(); i++) {
		if (finalStr[i] == '\n') finalStr[i] = ' ';
	}
	int count = 0;
	for (int i = 0; i < finalStr.length(); i++) {
		if (finalStr[i] == ' ') count++;
	}
	return count+1;
}
//Функция добавления массивов в конец файла
void fileAppendArrays(string file_name_1,string file_name_2) {
	string strToInp = fileOutput(file_name_1);
	string finalStr = strToInp;
	for (int i = 0; i < finalStr.length(); i++) {
		if (finalStr[i] == '\n') finalStr[i] = ' ';
	}

	string even = "";
	string odd = "";

	for (int i = 0; i < finalStr.length(); i+=3) {
		string s = "";
		s += finalStr[i];
		s += finalStr[i + 1];
		int num = atoi(s.c_str());

		if (num % 2 == 0) even = even + " " + s;
		else odd = odd + " " + s;


	}
	even = to_string(even.length() / 3) + even;
	odd = to_string(odd.length() / 3) + odd;

	strToInp = strToInp + "\n\n" + odd + "\n" + even;
	fileInput(file_name_2, strToInp);
}

//int main() {
//	srand(time(0));
//	setlocale(LC_ALL, "");
//	filePasteNumbers("test.txt");
//	cout<<fileOutput("test.txt")<<"\n\n";
//	//if (ifstream("test.txt", ios::_Nocreate)) cout << "true";
//	//else cout << "false";
//	fileAppendArrays("test.txt", "test2.txt");
//	
//}