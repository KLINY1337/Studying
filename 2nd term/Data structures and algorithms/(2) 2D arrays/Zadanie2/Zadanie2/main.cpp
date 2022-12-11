#include "functions.h"
#include "random"
#include <iomanip>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "Лабораторная работа №2 ИКБО-13-21 Черномуров С.А. Вариант 23" << endl << endl;
	cout << "Выберите, с чем хотите работать:\n1) Статический массив\n2) Динамический массив\n3) Вектор\n0) Закончить программу\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

	system("cls");

	double mas[Rows][Cols], len = 1;
	double** dynamic_mas = new double*[len];
	vector <string> vec;

	switch (choice1) {

	case 1: {
		cout << "Введите количество строк и столбцов (инициализируется одним значением, так как матрица квадратная, но не более 7) в статическом двумерном массиве: ";

		do {
			cin >> len;

			if (len > 7) cout << "Введите значение меньше 8:\n";
		} while (len > 7);

		initialize_static(mas, len);
		cout << "Введённая матрица:\n";
		cout_static(mas, len);

		break; }

	case 2: {
		cout << "Введите количество строк и столбцов (инициализируется одним значением, так как матрица квадратная) в динамическом двумерном массиве: ";

		do {
			cin >> len;

			if (len > 30) cout << "Нет смысла вводить значения выше 30, попробуйте другое значение:\n";
		} while (len > 30);

		dynamic_mas = new double* [len];

		for (int i = 0; i < len; i++) 
			dynamic_mas[i] = new double[len];

		initialize_dynamic(dynamic_mas, len);
		cout << "Введённая матрица:\n";
		cout_dynamic(dynamic_mas, len);

		break; }

	case 3: {
		

		break; }

	case 0:
		return 0;
	}

	cout << "Выберите номер задания:\n\n";
	
	if (choice1 <= 2) cout << "1) Найти определитель данной матрицы методом Гаусса\n0) Завершить работу программы\n";
	else cout << "1) Текст вводится как последовательность символов, заканчивающаяся точкой.\n   Определить количество различных пар букв в этом тексте\n0) Завершить работу программы\n";

	int choice2;

	do {
		cin >> choice2;

		if (choice2 != 1  && choice2 != 0) cout << "Введено неверное значение, попробуйте снова.\n";
	} while (choice2 != 1  && choice2 != 0);

	switch (choice2) {

	case 1: {
		if (choice1 == 1) {

			double result;

			result = static_determinant(mas, len);

			cout << "Преобразованная матрица:\n";

			for (int i = 0; i < len; i++) {
				cout << endl;
				for (int j = 0; j < len; j++) {
					cout << setw(8) << fixed << setprecision(4) << mas[i][j] << " ";
				}
			}

			cout << "\nОпределитель матрицы равен " << fixed << setprecision(0)<< round(result)<<"\n";
		}

		if (choice1 == 2) {

			double result;

			result = dynamic_determinant(dynamic_mas, len);

			cout << "Преобразованная матрица:\n";

			for (int i = 0; i < len; i++) {
				cout << endl;
				for (int j = 0; j < len; j++) {
					cout << setw(8) << fixed << setprecision(4) << mas[i][j] << " ";
				}
			}

			cout << "\nОпределитель матрицы равен " << fixed << setprecision(0) << round(result)<<"\n";
		}

		if (choice1 == 3) {

			string start_s;

			cout << "Введите ваш текст (все символы после точки учитываться не будут):\n";

			cin.ignore(32767, '\n');
			getline(cin, start_s);

			string s;

			s = cut_str(start_s);

			str_sort(s);

			cout << "Количество различных пар букв: " << letters_pairs(s, vec)<<endl;

			cout << "Все различные пары букв:\n";
			cout_vector(vec);
			
			}
			cout << endl;
		
		break; }
	case 0:
		return 0;
	}
	main();
}
