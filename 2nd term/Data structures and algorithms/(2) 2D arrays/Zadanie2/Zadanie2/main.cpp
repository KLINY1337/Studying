#include "functions.h"
#include "random"
#include <iomanip>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");

	cout << "������������ ������ �2 ����-13-21 ���������� �.�. ������� 23" << endl << endl;
	cout << "��������, � ��� ������ ��������:\n1) ����������� ������\n2) ������������ ������\n3) ������\n0) ��������� ���������\n";

	int choice1;

	do {
		cin >> choice1;

		if (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 0);

	system("cls");

	double mas[Rows][Cols], len = 1;
	double** dynamic_mas = new double*[len];
	vector <string> vec;

	switch (choice1) {

	case 1: {
		cout << "������� ���������� ����� � �������� (���������������� ����� ���������, ��� ��� ������� ����������, �� �� ����� 7) � ����������� ��������� �������: ";

		do {
			cin >> len;

			if (len > 7) cout << "������� �������� ������ 8:\n";
		} while (len > 7);

		initialize_static(mas, len);
		cout << "�������� �������:\n";
		cout_static(mas, len);

		break; }

	case 2: {
		cout << "������� ���������� ����� � �������� (���������������� ����� ���������, ��� ��� ������� ����������) � ������������ ��������� �������: ";

		do {
			cin >> len;

			if (len > 30) cout << "��� ������ ������� �������� ���� 30, ���������� ������ ��������:\n";
		} while (len > 30);

		dynamic_mas = new double* [len];

		for (int i = 0; i < len; i++) 
			dynamic_mas[i] = new double[len];

		initialize_dynamic(dynamic_mas, len);
		cout << "�������� �������:\n";
		cout_dynamic(dynamic_mas, len);

		break; }

	case 3: {
		

		break; }

	case 0:
		return 0;
	}

	cout << "�������� ����� �������:\n\n";
	
	if (choice1 <= 2) cout << "1) ����� ������������ ������ ������� ������� ������\n0) ��������� ������ ���������\n";
	else cout << "1) ����� �������� ��� ������������������ ��������, ��������������� ������.\n   ���������� ���������� ��������� ��� ���� � ���� ������\n0) ��������� ������ ���������\n";

	int choice2;

	do {
		cin >> choice2;

		if (choice2 != 1  && choice2 != 0) cout << "������� �������� ��������, ���������� �����.\n";
	} while (choice2 != 1  && choice2 != 0);

	switch (choice2) {

	case 1: {
		if (choice1 == 1) {

			double result;

			result = static_determinant(mas, len);

			cout << "��������������� �������:\n";

			for (int i = 0; i < len; i++) {
				cout << endl;
				for (int j = 0; j < len; j++) {
					cout << setw(8) << fixed << setprecision(4) << mas[i][j] << " ";
				}
			}

			cout << "\n������������ ������� ����� " << fixed << setprecision(0)<< round(result)<<"\n";
		}

		if (choice1 == 2) {

			double result;

			result = dynamic_determinant(dynamic_mas, len);

			cout << "��������������� �������:\n";

			for (int i = 0; i < len; i++) {
				cout << endl;
				for (int j = 0; j < len; j++) {
					cout << setw(8) << fixed << setprecision(4) << mas[i][j] << " ";
				}
			}

			cout << "\n������������ ������� ����� " << fixed << setprecision(0) << round(result)<<"\n";
		}

		if (choice1 == 3) {

			string start_s;

			cout << "������� ��� ����� (��� ������� ����� ����� ����������� �� �����):\n";

			cin.ignore(32767, '\n');
			getline(cin, start_s);

			string s;

			s = cut_str(start_s);

			str_sort(s);

			cout << "���������� ��������� ��� ����: " << letters_pairs(s, vec)<<endl;

			cout << "��� ��������� ���� ����:\n";
			cout_vector(vec);
			
			}
			cout << endl;
		
		break; }
	case 0:
		return 0;
	}
	main();
}
