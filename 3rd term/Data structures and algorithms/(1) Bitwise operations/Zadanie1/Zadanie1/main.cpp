#include <iostream>

#include "functions.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №1 \"Поразрядные операции и их применение\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n1) Установить 1-й, 6-й, 9-й биты в значение 1.\n" <<
		"2) Обнулить 1-й, 6-й, 9-й биты.\n" <<
		"3) Умножить значение, введенное пользователем, на 8.\n" <<
		"4) Разделить значение, введенное пользователем, на 8.\n" <<
		"5) Установить n-ый бит числа, введённого пользователем, в значение 1, используя маску 1.\n" <<
		"0) Завершить работу программы.\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 0);

	system("cls");

	switch (choice1)
	{
	case 1: {
		unsigned short int num;
		cout << "Введите изменяемое число (от 0000 до FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\nДвоичная запись введённого числа: ";
		cout_bin(num);
		num = set_bits_1_6_9(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\nОбновлённое число: " << num << endl;
		cout << "Двоичная запись обновлённого числа: ";
		cout_bin(num);
		break;
	}
	case 2: {
		unsigned short int num;
		cout << "Введите изменяемое число (от 0000 до FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\nДвоичная запись введённого числа: ";
		cout_bin(num);
		num = null_bits_1_6_9(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\nОбновлённое число: " << num << endl;
		cout << "Двоичная запись обновлённого числа: ";
		cout_bin(num);
		break;
	}
	case 3: {
		unsigned short int num;
		cout << "Введите умножаемое число (от 0000 до FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\nДвоичная запись введённого числа: ";
		cout_bin(num);
		num = multiply_by_8(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\nОбновлённое число: " << num << endl;
		cout << "Двоичная запись обновлённого числа: ";
		cout_bin(num);
		break;
	}
	case 4: {
		unsigned short int num;
		cout << "Введите делимое число число (от 0000 до FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\nДвоичная запись введённого числа: ";
		cout_bin(num);
		num = divide_by_8(num);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\nОбновлённое число: " << num << endl;
		cout << "Двоичная запись обновлённого числа: ";
		cout_bin(num);
		break;
	}
	case 5: {
		unsigned short int num;
		int n;
		cout << "Введите изменяемое число (от 0000 до FFFF): ";
		cin.unsetf(ios::dec);
		cin.setf(ios::hex);
		cin >> num;
		cout << "\nДвоичная запись введённого числа: ";
		cout_bin(num);
		cout << "\nВведите номер изменяемого бита (от 0 до 15): ";
		cin.unsetf(ios::hex);
		cin.setf(ios::dec);
		cin >> n;
		num = set_n_bit(num,n);
		cout.unsetf(ios::dec);
		cout.setf(ios::hex);
		cout << "\n\nОбновлённое число: " << num << endl;
		cout << "Двоичная запись обновлённого числа: ";
		cout_bin(num);
		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";
	main();
}