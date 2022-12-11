#include "functions1.h"
#include "functions2.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	cout << "Лабораторная работа №2 \"Внешние структуры данных: текстовый и двоичный файл\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n1) Создать текстовый файл, содержащий десятичные числа.\n" <<
		"2) Вывод содержимого текстового файла.\n" <<
		"3) Добавление новой строки в конец текстового файла.\n" <<
		"4) Прочитать значение числа по его порядковому номеру в файле.\n" <<
		"5) Создать новый файл из значений исходного, представить в нем на двух отдельных строках значения для заполнения двух массивов: на первой строке нечетные числа, а на второй четные. В начале каждой строки указать количество чисел в строке.\n" <<
		"6) Определить количество чисел в файле.\n"<<
		"7) Преобразование текстового файла в двоичный.\n"
		"8) Преобразование двоичного файла в текстовый.\n" <<
		"9) Вывод всех записей двоичного файла.\n" <<
		"10) Доступ к записи двоичного файла по ее номеру.\n" <<
		"11) Удаление записи с заданным значением ключа.\n" <<
		"12) Заменить дату техосмотра у автомобиля с заданным номером на новую дату.\n" <<
		"13) Сформировать список авто одной модели, прошедших техосмотр в заданную дату.\n" << 
		"0) Завершить работу программы.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 0 && choice1!=12 && choice1 != 13) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6 && choice1 != 7 && choice1 != 8 && choice1 != 9 && choice1 != 10 && choice1 != 11 && choice1 != 0 && choice1 != 12 && choice1 != 13);

	system("cls");

	switch (choice1)
	{
	case 1: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		filePasteNumbers(file_name);
		cout << "Файл успешно создан.";
		break;
	}
	case 2: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "\nСодержимое выбранного файла:\n\n";
			cout << fileOutput(file_name);
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 3: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			fileAppendString(file_name);
			cout << "Строка успешно добавлена к файлу.";
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 4: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;

		
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите индекс искомого элемента: ";
			int index;
			cin >> index;
			int res=fileReadNumber(file_name, index);
			cout << "Число с указанным индексом: " << res;
		}
		else cout << "\nУказанного файла не существует.\n";
		
		break;
	}
	case 5: {
		cout << "Введите название первого файла: ";
		string file_name_1;
		cin >> file_name_1;
		if (fstream(file_name_1, ios::_Nocreate)) {
			cout << "Введите название второго файла: ";
			string file_name_2;
			cin >> file_name_2;
			fileAppendArrays(file_name_1, file_name_2);
		}
		break;
	}
	case 6: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Количество чисел в файле: " << fileCountNumber(file_name);
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 7: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите название бинарного файла: ";
			string file_name_bin;
			cin >> file_name_bin;
			textToBin(file_name, file_name_bin);
			cout << "Конвертация произошла успешно.";
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 8: {
		cout << "Введите название бинарного файла: ";
		string file_name_bin;
		cin >> file_name_bin;
		if (fstream(file_name_bin, ios::_Nocreate)) {
			cout << "Введите название файла: ";
			string file_name;
			cin >> file_name;
			binToText(file_name, file_name_bin);
			cout << "Конвертация произошла успешно.";
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 9: {
		cout << "Введите название файла: ";
		string file_name;
		cin >> file_name;
		if (fstream(file_name, ios::_Nocreate)) {
			cout << "\nСодержимое выбранного файла:\n\n";
			fileOutputBin(file_name);
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 10: {
		cout << "Введите название бинарного файла: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите индекс искомого элемента: ";
			int index;
			cin >> index;
			string res =fileGet(file_name, index)=="" ? "Не найдена": fileGet(file_name, index);
			cout << "Запись с указанным индексом: " << res;
		}
		else cout << "\nУказанного файла не существует.\n";

		break;
	}
	case 11: {
		//void fileDelete(string file_name, int index);
		cout << "Введите название бинарного файла: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите индекс удаляемого элемента: ";
			int index;
			cin >> index;
			fileDelete(file_name, index);
			cout << "Запись успешно удалена.";
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 12: {
		//void switchTI(string file_name, string number, string date);
		cout << "Введите название бинарного файла: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите номер нужного автомобиля: ";
			string number;
			cin >> number;
			cout << "Введите изменяемую дату: ";
			string date;
			cin >> date;
			switchTI(file_name, number, date);
			cout << "Дата успешно изменена.\n";
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 13: {
		cout << "Введите название бинарного файла: ";
		string file_name;
		cin >> file_name;

		if (fstream(file_name, ios::_Nocreate)) {
			cout << "Введите код автомобиля: ";
			string car;
			cin >> car;
			cout << "Введите дату: ";
			string date;
			cin >> date;
			cout << "Сформированный список:\n";
			checkCars(file_name, car, date);
		}
		else cout << "\nУказанного файла не существует.\n";
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";
	main();
}