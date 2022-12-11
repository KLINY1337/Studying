#include "functions.h"
#include "random"

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №1 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите, с чем хотите работать:\n1) Статический массив\n2) Динамический массив\n3) Вектор\n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

	system("cls");

	int mas[1000], len = 1;
	int* dynamic_mas = new int[len];
	vector <int> vec;

	switch (choice1) {

	case 1: {
		cout << "Введите количество элементов в статическом массиве: ";

		do {
			cin >> len;

			if (len >= 100) cout << "Введите значение меньше 100:\n";
		} while (len >= 100);

		initialize_array(mas, len);
		cout_array(mas, len);

		break; }

	case 2: {
		cout << "Введите количество элементов в динамическом массиве: ";

		cin >> len;
		dynamic_mas = new int[len];
		initialize_array(dynamic_mas, len);
		cout_array(dynamic_mas, len);

		break; }

	case 3: {
		cout << "Введите количество элементов в векторе: ";

		cin >> len;

		initialize_vector(vec, len);
		cout_vector(vec);

		break; }

	case 0:
		return 0;
	}

	cout << "Выберите номер задания:\n\n";
	cout << "1) Определить, упорядочены ли значения в массиве(векторе) по возрастанию\n";
	cout << "2) Если значения в массиве(векторе) упорядочены по возрастанию, то удалить из массива(вектора) элементы, которые кратны введенному значению\n";
	cout << "3) Если значения в массиве(векторе) не упорядочены по возрастанию, то вставить новый элемент в массив перед первым элементом\n";
	cout << "0) Закончить программу\n";

	int choice2;

	do {
		cin >> choice2;
		if (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 0);
	
	switch (choice2) {

	case 1: {
		if (choice1 == 1) {
			if (is_sorted(mas, len) == true) cout << "Элементы массива упорядочены по возрастанию\n";
			else cout << "Элементы массива не упорядочены по возрастанию\n";
		}

		if (choice1 == 2) {
			if (is_sorted(dynamic_mas, len) == true) cout << "Элементы массива упорядочены по возрастанию\n";
			else cout << "Элементы массива не упорядочены по возрастанию\n";
		}

		if (choice1 == 3) {
			if (is_sorted_vector(vec) == true) cout << "Элементы вектора упорядочены по возрастанию\n";
			else cout << "Элементы вектора не упорядочены по возрастанию\n";
		}
		break; }

	case 2: {
		if (choice1 == 1) {
			int divider;

			cout << "Введите число, кратному которые элементы нужно удалить(если массив отсортирован): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "На ноль делить нельзя, попробуйте другое значение\n";
			} while (divider == 0);

			delete_for_sorted(mas, len, divider);
			cout_array(mas, len);
		}

		if (choice1 == 2) {
			int divider;

			cout << "Введите число, кратному которые элементы нужно удалить(если массив отсортирован): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "На ноль делить нельзя, попробуйте другое значение\n";
			} while (divider == 0);

			delete_for_sorted(dynamic_mas, len, divider);
			cout_array(dynamic_mas, len);
		}

		if (choice1 == 3) {
			int divider;

			cout << "Введите число, кратному которые элементы нужно удалить(если вектор отсортирован): ";

			do {
				cin >> divider;
				if (divider == 0) cout << "На ноль делить нельзя, попробуйте другое значение\n";
			} while (divider == 0);

			delete_for_sorted_vector(vec, divider);
			cout_vector(vec);
		}
		break; }

	case 3: {
		if (choice1 == 1) {
			int paste_element;

			cout << "Введите число, которое хотите вставить в начало (если элементы массива(вектора) не упорядочены по возрастанию): ";

			cin >> paste_element;

			add_for_unsorted(mas, len, paste_element);
			cout_array(mas, len);
		}

		if (choice1 == 2) {
			int paste_element;

			cout << "Введите число, которое хотите вставить в начало (если элементы массива(вектора) не упорядочены по возрастанию): ";

			cin >> paste_element;

			add_for_unsorted(dynamic_mas, len, paste_element);
			cout_array(dynamic_mas, len);
		}

		if (choice1 == 3) {
			int paste_element;

			cout << "Введите число, которое хотите вставить в начало (если элементы вектора не упорядочены по возрастанию): ";

			cin >> paste_element;

			add_for_unsorted_vector(vec, paste_element);
			cout_vector(vec);
		}
		break; }

	case 0:
		return 0;
	}

	main();
}
