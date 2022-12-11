#include <iostream>
#include "Task.h"
#include <windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №8 \"Алгоритмические стратегии или методы разработки алгоритмов. Перебор и методы его сокращения\". Черномуров Семён\n";

	cout << "Выберите номер задания:\n" <<
		"1) Задача о рюкзаке (о салате, жире и калориях)\n" <<
		"0) Завершить работу программы\n\n";

	int choice1;
	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 0);

	system("cls");
	switch (choice1)
	{
	case 1: {
		cout << "Введите размер массивов: ";
		int size;
		cin >> size;
		cout << "\nВведите массив жирности:\n";
		int* fat = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> fat[i];
		}
		cout << "\nВведите массив калорий:\n";
		int* calories = new int[size];
		for (int i = 0; i < size; i++) {
			cin >> calories[i];
		}
		cout << "\nВведите максимальное число калорий: ";
		int maxCalories;
		cin >> maxCalories;

		BackpackProblem obj(calories, fat, maxCalories, size);
		tuple<int, int, vector<pair<int, int>>> answer = obj.solve();

		cout << "Набранная жирность: " << get<0>(answer) << "; Набранные калории: " << get<1>(answer)<<".\n";
		cout << "Были выбраны ингредиенты (жирность, калорийность, номер в массиве):\n";

		for (int i = 0; i < get<2>(answer).size(); i++) {
			cout << get<2>(answer)[i].first << " " << get<2>(answer)[i].second << " ("<<i+1<<")\n";
		}

		break;
	}
	case 0:
		return 0;
	}
	cout << "\n\n";

	main();
}